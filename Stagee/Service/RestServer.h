#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <libs/mongoose/mongoose.h>
#include <Polynome.h>
#include <SolverDichotomy.h>
#include <SolverHorde.h>
#include <SolverNewtone.h>

using namespace std;

class RestServer {
public:
  RestServer();
  ~RestServer();
  static void handle_checkvalue_call(struct mg_connection *nc,
                                     struct http_message *hm);
  static void handle_findroots_call(struct mg_connection *nc,
                                    struct http_message *hm);
  static void ev_handler(struct mg_connection *nc, int ev, void *ev_data);
};
