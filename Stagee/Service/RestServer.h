#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <Libs/mongoose/mongoose.h>
/*Boost decimals*/
#include <Polynome.h>
#include <SolverDichotomy.h>
#include <SolverHorde.h>
#include <SolverNewtone.h>
/*Double*/
#include <Polynome.h>

using namespace std;

class RestServer {
public:
  RestServer();
  ~RestServer();
};
