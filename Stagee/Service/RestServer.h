#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <Libs/mongoose/mongoose.h>
/*Boost decimals*/
#include <PolynomeBoost.h>
#include <SolverDichotomy.h>
#include <SolverDichotomyBoost.h>
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
