#include <Polynome.h>
#include <SolverDichotomyStub.h>
#include <SolverNewtoneStub.h>
#include <SolverHordeStub.h>
#include <gtest/gtest.h>
#include <vector>
#include <cfloat>

using namespace std;

const double delta = 1e-5;
// a0 + a1*x^1 + a2*x^2 + ... + xn*x^n = 0

/*****************************************************
TEST CASES  : HaveRealRootsTestCaseDichotomy
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveRealRootsTestCaseDichotomy, Test01) {
  vector<double> initValue = {0, 1};
  vector<double> expectedValue = {0};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCaseDichotomy, Test02) {
    vector<double> initValue = {0, 0, 1};
    vector<double> expectedValue = {0};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}

TEST(HaveRealRootsTestCaseDichotomy, Test03) {
    vector<double> initValue = {0, 0, 0, 1};
    vector<double> expectedValue = {0};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x-2)(x-3)
TEST(HaveRealRootsTestCaseDichotomy, Test04) {
    vector<double> initValue = {-6, 11, -6, 1};
    vector<double> expectedValue = {1, 2, 3};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x+1)(x-2)(x+2)
TEST(HaveRealRootsTestCaseDichotomy, Test05) {
    vector<double> initValue = {4, 0, -5, 0, 1};
    vector<double> expectedValue = {-2, -1, 1, 2};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-100)(x+100)
TEST(HaveRealRootsTestCaseDichotomy, Test06) {
    vector<double> initValue = {-9801, 0, 1};
    vector<double> expectedValue = {-99, 99};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : HaveNoRealRootsTestCaseDichotomy
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveNoRealRootsTestCaseDichotomy, Test01) {
    vector<double> initValue = {-101, 1};
    vector<double> expectedValue = {};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseDichotomy, Test02) {
    vector<double> initValue = {101, 1};
    vector<double> expectedValue = {};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseDichotomy, Test03) {
    vector<double> initValue = {1, 0};
    vector<double> expectedValue = {};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseDichotomy, Test04) {
    vector<double> initValue = {7, 3, 5};
    vector<double> expectedValue = {};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseDichotomy, Test05) {
    vector<double> initValue = {1, 0, 0, 0, 1};
    vector<double> expectedValue = {};

    SolverDichotomy testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : SignTestCaseDichotomy
NAME        : sign
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(SignTestCaseDichotomy, Test01) {
  double initValue = -3;
  bool expectedValue = false;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test02) {
  double initValue = 0;
  bool expectedValue = true;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test03) {
  double initValue = 3;
  bool expectedValue = true;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test04) {
  double initValue = DBL_MAX;
  bool expectedValue = true;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test05) {
  double initValue = -DBL_MAX;
  bool expectedValue = false;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test06) {
  double initValue = DBL_MAX_10_EXP;
  bool expectedValue = true;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseDichotomy, Test07) {
  double initValue = -DBL_MAX_10_EXP;
  bool expectedValue = false;
  SolverDichotomyStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
/******************************************************/

/*****************************************************
TEST CASES  : HaveRealRootsTestCaseNewtone
NAME        : solve
DESCRIPTION : Testing of SolverNewtone.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveRealRootsTestCaseNewtone, Test01) {
  vector<double> initValue = {0, 1};
  vector<double> expectedValue = {0};

  SolverNewtone testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCaseNewtone, Test02) {
    vector<double> initValue = {0, 0, 1};
    vector<double> expectedValue = {0};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}

TEST(HaveRealRootsTestCaseNewtone, Test03) {
    vector<double> initValue = {0, 0, 0, 1};
    vector<double> expectedValue = {0};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x-2)(x-3)
TEST(HaveRealRootsTestCaseNewtone, Test04) {
    vector<double> initValue = {-6, 11, -6, 1};
    vector<double> expectedValue = {1, 2, 3};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x+1)(x-2)(x+2)
TEST(HaveRealRootsTestCaseNewtone, Test05) {
    vector<double> initValue = {4, 0, -5, 0, 1};
    vector<double> expectedValue = {-2, -1, 1, 2};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-100)(x+100)
TEST(HaveRealRootsTestCaseNewtone, Test06) {
    vector<double> initValue = {-9801, 0, 1};
    vector<double> expectedValue = {-99, 99};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : HaveNoRealRootsTestCaseNewtone
NAME        : solve
DESCRIPTION : Testing of SolverNewtone.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveNoRealRootsTestCaseNewtone, Test01) {
    vector<double> initValue = {-101, 1};
    vector<double> expectedValue = {};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseNewtone, Test02) {
    vector<double> initValue = {101, 1};
    vector<double> expectedValue = {};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseNewtone, Test03) {
    vector<double> initValue = {1, 0};
    vector<double> expectedValue = {};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseNewtone, Test04) {
    vector<double> initValue = {7, 3, 5};
    vector<double> expectedValue = {};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseNewtone, Test05) {
    vector<double> initValue = {1, 0, 0, 0, 1};
    vector<double> expectedValue = {};

    SolverNewtone testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : SignTestCaseNewtone
NAME        : sign
DESCRIPTION : Testing of SolverNewtone.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(SignTestCaseNewtone, Test01) {
  double initValue = -3;
  bool expectedValue = false;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test02) {
  double initValue = 0;
  bool expectedValue = true;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test03) {
  double initValue = 3;
  bool expectedValue = true;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test04) {
  double initValue = DBL_MAX;
  bool expectedValue = true;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test05) {
  double initValue = -DBL_MAX;
  bool expectedValue = false;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test06) {
  double initValue = DBL_MAX_10_EXP;
  bool expectedValue = true;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseNewtone, Test07) {
  double initValue = -DBL_MAX_10_EXP;
  bool expectedValue = false;
  SolverNewtoneStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
/******************************************************/

/*****************************************************
TEST CASES  : HaveRealRootsTestCaseHorde
NAME        : solve
DESCRIPTION : Testing of SolverHorde.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveRealRootsTestCaseHorde, Test01) {
  vector<double> initValue = {0, 1};
  vector<double> expectedValue = {0};

  SolverHorde testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCaseHorde, Test02) {
    vector<double> initValue = {0, 0, 1};
    vector<double> expectedValue = {0};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}

TEST(HaveRealRootsTestCaseHorde, Test03) {
    vector<double> initValue = {0, 0, 0, 1};
    vector<double> expectedValue = {0};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x-2)(x-3)
TEST(HaveRealRootsTestCaseHorde, Test04) {
    vector<double> initValue = {-6, 11, -6, 1};
    vector<double> expectedValue = {1, 2, 3};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-1)(x+1)(x-2)(x+2)
TEST(HaveRealRootsTestCaseHorde, Test05) {
    vector<double> initValue = {4, 0, -5, 0, 1};
    vector<double> expectedValue = {-2, -1, 1, 2};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
//(x-100)(x+100)
TEST(HaveRealRootsTestCaseHorde, Test06) {
    vector<double> initValue = {-9801, 0, 1};
    vector<double> expectedValue = {-99, 99};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : HaveNoRealRootsTestCaseHorde
NAME        : solve
DESCRIPTION : Testing of SolverHorde.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(HaveNoRealRootsTestCaseHorde, Test01) {
    vector<double> initValue = {-101, 1};
    vector<double> expectedValue = {};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseHorde, Test02) {
    vector<double> initValue = {101, 1};
    vector<double> expectedValue = {};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseHorde, Test03) {
    vector<double> initValue = {1, 0};
    vector<double> expectedValue = {};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseHorde, Test04) {
    vector<double> initValue = {7, 3, 5};
    vector<double> expectedValue = {};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
TEST(HaveNoRealRootsTestCaseHorde, Test05) {
    vector<double> initValue = {1, 0, 0, 0, 1};
    vector<double> expectedValue = {};

    SolverHorde testObject;
    Polynome polynome(initValue);
    vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

    EXPECT_EQ(expectedValue.size(), resultValue.size())
        << "Vectors are of unequal length";
    for (unsigned int i = 0; i < min(expectedValue.size(),resultValue.size()); ++i) {
      EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
          << "Vectors differ at index " << i;
    }
}
/*****************************************************
TEST CASES  : SignTestCaseHorde
NAME        : sign
DESCRIPTION : Testing of SolverHorde.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(SignTestCaseHorde, Test01) {
  double initValue = -3;
  bool expectedValue = false;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test02) {
  double initValue = 0;
  bool expectedValue = true;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test03) {
  double initValue = 3;
  bool expectedValue = true;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test04) {
  double initValue = DBL_MAX;
  bool expectedValue = true;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test05) {
  double initValue = -DBL_MAX;
  bool expectedValue = false;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test06) {
  double initValue = DBL_MAX_10_EXP;
  bool expectedValue = true;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCaseHorde, Test07) {
  double initValue = -DBL_MAX_10_EXP;
  bool expectedValue = false;
  SolverHordeStub testObject;
  bool resultValue = testObject.signTransit(initValue);
  EXPECT_EQ(expectedValue, resultValue);
}
/* detached test cases */
/*****************************************************
TEST CASES  : DegeneracyTestCase
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(DegeneracyTestCase, Test01) {
  vector<double> initValue = {0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test02) {
  vector<double> initValue = {0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test03) {
  vector<double> initValue = {0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test04) {
  vector<double> initValue = {0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test05) {
  vector<double> initValue = {0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test06) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test07) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test08) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test09) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test10) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = true;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test11) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test12) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test13) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test14) {
  vector<double> initValue = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test15) {
  vector<double> initValue = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test16) {
  vector<double> initValue = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test17) {
  vector<double> initValue = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test18) {
  vector<double> initValue = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test19) {
  vector<double> initValue = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test20) {
  vector<double> initValue = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}

TEST(DegeneracyTestCase, Test21) {
  vector<double> initValue = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  bool expectedValue = false;
  Polynome testObject(initValue);
  bool resultValue = testObject.isDegenerative();
  EXPECT_EQ(expectedValue, resultValue) << "Vectors are of unequal length";
}
/*****************************************************
TEST CASES  : ValuesTestCase
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(ValuesTestCase, Test01) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 3;
  double expectedValue = 2;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}
/*****************************************************
TEST CASES  : ValuesTestCaseConstant
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(ValuesTestCaseConstant, Test01) {
  vector<double> initValue = {1, 0, 0};
  Polynome polynome(initValue);
  double solveAt = 0;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseConstant, Test02) {
  vector<double> initValue = {1, 0, 0};
  Polynome polynome(initValue);
  double solveAt = -100.0;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseConstant, Test03) {
  vector<double> initValue = {1, 0, 0};
  Polynome polynome(initValue);
  double solveAt = 100.0;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseConstant, Test04) {
  vector<double> initValue = {1, 0, 0};
  Polynome polynome(initValue);
  double solveAt = DBL_MAX;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseConstant, Test05) {
  vector<double> initValue = {1, 0, 0};
  Polynome polynome(initValue);
  double solveAt = -DBL_MAX;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}
/*****************************************************
TEST CASES  : ValuesTestCaseDiffPower
NAME        : solve
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
*****************************************************/
TEST(ValuesTestCaseDiffPower, Test01) {
  vector<double> initValue = {1};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 1;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test02) {
  vector<double> initValue = {1, 2};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 5;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test03) {
  vector<double> initValue = {1, 2, 3};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 17;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test04) {
  vector<double> initValue = {1, 2, 3, 4};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 49;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test05) {
  vector<double> initValue = {1, 2, 3, 4, 5};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 129;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test06) {
  vector<double> initValue = {1, 2, 3, 4, 5, 6};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 321;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test07) {
  vector<double> initValue = {1, 2, 3, 4, 5, 6, 7};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 769;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test08) {
  vector<double> initValue = {1, 2, 3, 4, 5, 6, 7, 8};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 1793;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test09) {
  vector<double> initValue = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 4097;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test10) {
  vector<double> initValue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 9217;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCaseDiffPower, Test11) {
  vector<double> initValue = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 129;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}
/*****************************************************
TEST CASES  : SpeedTest
NAME        : none
DESCRIPTION : Performance test
INPUT       :
OUTPUT      :
*****************************************************/
template <typename T>
T func(T x)
{
  return pow(x-5, 6);
}

template <typename T>
T poly(T x)
{
  return pow(x, 6) - 30 * pow(x, 5) + 375 * pow(x, 4) - 2500 * pow(x, 3) + 9375 * pow(x, 2) - 18750 * x + 15625;
}

template <typename T, T Fn(T), typename It>
void test(It it)
{
  for (T f = 4.98; f < 5.02; f += 0.0001)
    *it++ = Fn(f);
}

TEST(SpeedTest, Test1) {
    std::vector<float>       vf;
    std::vector<double>      vd;
    std::vector<long double> vld;

    const clock_t dblt0 = clock();
    for (int i = 0; i < 100; i++)
    {
      test<double,      func>(std::back_inserter<decltype(vd) >(vd));
      test<double,      poly>(std::back_inserter<decltype(vd) >(vd));
    }
    const clock_t dblt1 = clock();
    const double elapsedSec = (dblt1 - dblt0) / (double)CLOCKS_PER_SEC;

    std::cout << "Double: " << elapsedSec << std::endl;

    std::cout << std::endl;

    using namespace boost::multiprecision;
    typedef cpp_bin_float_quad cppbinFloat;

    std::vector<cppbinFloat> vbin_float1;
    std::vector<cppbinFloat> vbin_float2;

    const clock_t bint0 = clock();
    for (int i = 0; i < 100; i++)
    {
      test<cppbinFloat, func>(std::back_inserter<decltype(vbin_float1)>(vbin_float1));
      test<cppbinFloat, poly>(std::back_inserter<decltype(vbin_float2)>(vbin_float2));
    }
    const clock_t bint1 = clock();
    const double elapsedSecBin = (bint1 - bint0) / (double)CLOCKS_PER_SEC;
    std::cout << "Bin float: " << elapsedSecBin << std::endl;
}

/********************************************************************/
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
