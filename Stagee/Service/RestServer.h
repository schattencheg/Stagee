#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <Libs/mongoose/mongoose.h>
#include <Polynome.h>
#include <SolverDichotomy.h>
#include <SolverHorde.h>
#include <SolverNewtone.h>

using namespace std;

class RestServer {
public:
  RestServer();
  ~RestServer();
};
