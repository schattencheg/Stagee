#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <Libs/mongoose/mongoose.h>
/*Boost decimals*/
#include <PolynomeBoost.h>
#include <SolverDichotomyBoost.h>
/*Double*/
#include <Polynome.h>
#include <SolverDichotomy.h>


using namespace std;

class RestServer {
public:
  RestServer();
  ~RestServer();
};
