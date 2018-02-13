#include <Polynome.h>
#include <SolverDichotomyStub.h>
#include <gtest/gtest.h>
#include <vector>
#include <cfloat>

using namespace std;

const double delta = 1e-8;
// a0 + a1*x^1 + a2*x^2 + ... + xn*x^n = 0

TEST(HaveRealRootsTestCase, Test01) {
  vector<double> initValue = {-1.5, 1};
  vector<double> expectedValue = {1.5};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test02) {
  vector<double> initValue = {7.5, -6.5, 1};
  vector<double> expectedValue = {1.5, 5};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test03) {
  vector<double> initValue = {22.5, -12, -3.5, 1};
  vector<double> expectedValue = {-3, 1.5, 5};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test04) {
  vector<double> initValue = {-11.25, 28.5, -10.25, -4, 1};
  vector<double> expectedValue = {-3, 0.5, 1.5, 5};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test05) {
  vector<double> initValue = {-120, 274, -225, 85, -15, 1};
  vector<double> expectedValue = {1, 2, 3, 4, 5};
  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test06) {
  vector<double> initValue = {720, -1044, -140, 889, -560, 154, -20, 1};
  vector<double> expectedValue = {-1, 1, 2, 3, 4, 5, 6};
  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test07) {
  vector<double> initValue = {1440, -1368, -1324, 1638, -231, -252, 114, -18, 1};
  vector<double> expectedValue = {-2, -1, 1, 2, 3, 4, 5, 6};
  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

//(x-5)(x-5)(x-5)(x-5)(x-5)(x-5)
TEST(HaveRealRootsTestCase, Test08) {
  vector<double> initValue = {15625, -18750, 9375, -2500, 375, -30, 1};
  vector<double> expectedValue = {-5};
  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveRealRootsTestCase, Test99) {
  //(x-1.5)(x-5.0)(x+3.0)(x-0.5)(x-10.25)
  vector<double> initValue = {115.313, -303.375, 133.563, 30.75, -14.25, 1};
  vector<double> expectedValue = {-3, 0.5, 1.5, 5, 10.25};
  //[-3 0.500004 1.49999 5.00002 10.25 ]
  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

/******************************************************/

TEST(HaveSimmetricalRealRootsTestCase, Test01) {
  vector<double> initValue = {-900, 0, 634, 0, -106.25, 0, 1};
  vector<double> expectedValue = {-10, -2, -1.5, 1.5, 2, 10};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

TEST(HaveSimmetricalRealRootsTestCase, Test02) {
  vector<double> initValue = {-900, 0, 634, 0, -106.25, 0, 1};
  vector<double> expectedValue = {-10, -2, -1.5, 1.5, 2, 10};

  SolverDichotomy testObject;
  Polynome polynome(initValue);
  vector<double> resultValue = testObject.solve(&polynome, -100.0, 100.0);

  EXPECT_EQ(expectedValue.size(), resultValue.size())
      << "Vectors are of unequal length";
  for (unsigned int i = 0; i < expectedValue.size(); ++i) {
    EXPECT_NEAR(expectedValue[i], resultValue[i], delta)
        << "Vectors differ at index " << i;
  }
}

/******************************************************/

TEST(HaveNoRealRootsTestCase, Test01) {}

/******************************************************/

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
/******************************************************/

TEST(ValuesTestCase, Test01) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 3;
  double expectedValue = 2;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test02) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 1;
  double expectedValue = 0;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}
/******************************************************/
TEST(CheckValuesTestCase, Test01) {
  vector<double> initValue = {6, 5};

  double solveAt = 3;
  double expectedValue = 21;

  /*Create new polynome object*/
  Polynome polynome(initValue);

  double resultValue = polynome.value(solveAt);

  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(CheckValuesTestCase, Test02) {
  vector<double> initValue = {6, 5};

  double solveAt = 0;
  double expectedValue = 6;

  /*Create new polynome object*/
  Polynome polynome(initValue);

  double resultValue = polynome.value(solveAt);

  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test03) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 1.01;
  double expectedValue = -0.0099;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test04) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 0.99;
  double expectedValue = 0.0101;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test05) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 2;
  double expectedValue = 0;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test06) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = 100;
  double expectedValue = 9702;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

TEST(ValuesTestCase, Test07) {
  vector<double> initValue = {2, -3, 1};
  Polynome polynome(initValue);
  double solveAt = -100.0;
  double expectedValue = 10302;
  double resultValue = polynome.value(solveAt);
  EXPECT_NEAR(expectedValue, resultValue, delta);
}

/******************************************************/

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

/******************************************************/

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
TEST CASES  : SignTestCase
NAME        : sign
DESCRIPTION : Testing of SolverDichotomy.sign(double)
INPUT       : double
OUTPUT      : bool
/*****************************************************/

TEST(SignTestCase, Test01) {
  double initValue = -3;

  bool expectedValue = false;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test02) {
  double initValue = 0;

  bool expectedValue = true;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test03) {
  double initValue = 3;

  bool expectedValue = true;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test04) {
  double initValue = DBL_MAX;

  bool expectedValue = true;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test05) {
  double initValue = -DBL_MAX;

  bool expectedValue = false;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test06) {
  double initValue = DBL_MAX_10_EXP;

  bool expectedValue = true;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test07) {
  double initValue = -DBL_MAX_10_EXP;

  bool expectedValue = false;
  SolverDichotomyStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
/******************************************************/

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
