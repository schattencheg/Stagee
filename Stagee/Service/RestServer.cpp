#include "RestServer.h"

using namespace std;

static const char *s_http_port = "8080";
static struct mg_serve_http_opts s_http_server_opts;

static void handle_checkvalue_call(struct mg_connection *nc,
                                   struct http_message *hm) {
  /*curl -i -X GET http://localhost:8080/api/checkvalue -d "{'x':3,
   * 'polynomial':[2,-3,1]}"*/
  string JSONString = string(hm->body.p);
  JSONString.resize(hm->body.len);
  int posX = JSONString.find("'x':") + 4;
  int posXEnd = JSONString.find(",");
  string xStr = JSONString.substr(posX, posXEnd - posX);
  double x = stod(xStr);

  int posPoly = JSONString.find("'polynomial':[") + 14;
  int posPolyEnd = JSONString.find("]");
  string polyStr = JSONString.substr(posPoly, posPolyEnd - posPoly);
  stringstream ss(polyStr);
  vector<double> polynome;
  while (ss.good()) {
    string substr;
    getline(ss, substr, ',');
    polynome.push_back(stod(substr));
  }

  /*Create new polynome object*/
  PolynomeBoost myPolynome(polynome);
  /*Calculate value at point x*/
  double answerIs = myPolynome.value(x);

  /* Send headers */
  mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
  mg_printf_http_chunk(nc, "[%lf]", answerIs);
  mg_send_http_chunk(nc, "", 0); /* Send empty chunk, the end of response */
}

static void handle_findroots_call(struct mg_connection *nc,
                                  struct http_message *hm) {
  /*curl -i -X GET http://localhost:8080/api/findroots -d "[6, 2]"*/
  /*curl -i -X GET http://localhost:8080/api/findroots -d "[-1, 0, 0, 0, 1]"*/
  /*curl -i -X GET http://localhost:8080/api/findroots -d "[151200, 127860,
   * 44524, 8175, 935, 45, 1]"*/
  /*curl -i -X GET http://localhost:8080/api/findroots -d "[15625, -18750, 9375, -2500, 375, -30, 1]"*/
  string JSONString = string(hm->body.p);
  JSONString.resize(hm->body.len);
  int posPoly = JSONString.find("[") + 1;
  int posPolyEnd = JSONString.find("]");
  string polyStr = JSONString.substr(posPoly, posPolyEnd - posPoly);

  stringstream ss(polyStr);
  vector<double> polynomeCoeffs;

  while (ss.good()) {
    string substr;
    getline(ss, substr, ',');
    polynomeCoeffs.push_back(stod(substr));
  }

  /* Send headers */
  mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
  std::stringstream res;

  /*Create new polynome object*/
  PolynomeBoost polynome(polynomeCoeffs);
  /*Create new solver object*/
  SolverDichotomyBoost polySolverDichotomy;

  Polynome simplePolynome(polynomeCoeffs);
  SolverDichotomy polySolver;

  /*Search for roots*/
  /*Simple Polynome*/
  //vector<double> answerIs = polySolver.solve(&simplePolynome, -100.0, 100.0);
  //if (simplePolynome.isDegenerative()) {
  //  res << "all numbers";
  //} else {
  //  std::copy(answerIs.begin(), answerIs.end(),
  //            ostream_iterator<double>(res, " "));
  //}
  //mg_printf_http_chunk(nc, "Simple algorithm:\n");
  //mg_printf_http_chunk(nc, "[%s]\n", res.str().c_str());



  /*PolynomeBoost*/
  vector<double> answerIs = polySolverDichotomy.solve(&polynome, -100.0, 100.0);
  if (polynome.isDegenerative()) {
    res << "all numbers";
  } else {
    std::copy(answerIs.begin(), answerIs.end(),
              ostream_iterator<double>(res, " "));
  }
  mg_printf_http_chunk(nc, "Boost algorithm:\n");
  mg_printf_http_chunk(nc, "[%s]", res.str().c_str());
  mg_send_http_chunk(nc, "", 0); /* Send empty chunk, the end of response */
}

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
  struct http_message *hm = (struct http_message *)ev_data;

  switch (ev) {
    case MG_EV_HTTP_REQUEST:
      if (mg_vcmp(&hm->uri, "/api/findroots") == 0) {
        handle_findroots_call(nc, hm);
      } else if (mg_vcmp(&hm->uri, "/api/checkvalue") == 0) {
        handle_checkvalue_call(nc, hm);
      } else {
        mg_printf(nc, "%s",
                  "HTTP/1.1 400 Incorrect input\r\nTransfer-Encoding: "
                  "chunked\r\n\r\n");
        mg_send_http_chunk(nc, "",
                           0); /* Send empty chunk, the end of response */
      }
      break;
    default:
      break;
  }
}

RestServer::RestServer() {
  struct mg_mgr mgr;
  struct mg_connection *nc;
  struct mg_bind_opts bind_opts;
  int i;
  char *cp;
  const char *err_str;
#if MG_ENABLE_SSL
  const char *ssl_cert = NULL;
#endif
  mg_mgr_init(&mgr, NULL);
  /* Set HTTP server options */
  memset(&bind_opts, 0, sizeof(bind_opts));
  bind_opts.error_string = &err_str;
#if MG_ENABLE_SSL
  if (ssl_cert != NULL) {
    bind_opts.ssl_cert = ssl_cert;
  }
#endif
  nc = mg_bind_opt(&mgr, s_http_port, ev_handler, bind_opts);
  if (nc == NULL) {
    fprintf(stderr, "Error starting server on port %s: %s\n", s_http_port,
            *bind_opts.error_string);
    exit(1);
  }

  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.enable_directory_listing = "yes";

  printf("Starting RESTful server on port %s, serving %s\n", s_http_port,
         s_http_server_opts.document_root);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);
}

RestServer::~RestServer() {}
