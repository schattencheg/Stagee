#include <Polynome.h>
#include <rootfinderstub.h>
#include <gtest/gtest.h>
#include <vector>
#include <cfloat>

using namespace std;

const double delta = 0.0001;
// a0 + a1*x^1 + a2*x^2 + ... + xn*x^n = 0

TEST(HaveRealRootsTestCase, Test01) {
  /*Create new solver object*/
  RootFinderStub testObject;

  vector<double> initValue = {6, 2};
  vector<double> expectedValue = {-3};

  /*Create new polynome object*/
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

TEST(HaveNoRealRootsTestCase, Test01) {
  /*Create new solver object*/
  RootFinderStub testObject;

  vector<double> initValue = {1, 0, 0, 0, 4};
  vector<double> expectedValue = {};

  /*Create new polynome object*/
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

TEST(CheckValuesTestCase, Test03) {
  vector<double> initValue = {DBL_MAX, DBL_MIN};

  double solveAt = 0;
  double expectedValue = DBL_MAX;

  /*Create new polynome object*/
  Polynome polynome(initValue);

  double resultValue = polynome.value(solveAt);

  EXPECT_NEAR(expectedValue, resultValue, delta);
}
/******************************************************/
TEST(SignTestCase, Test01) {
  double initValue = -3;

  bool expectedValue = false;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test02) {
  double initValue = 0;

  bool expectedValue = true;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test03) {
  double initValue = 3;

  bool expectedValue = true;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test04) {
  double initValue = DBL_MAX;

  bool expectedValue = true;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test05) {
  double initValue = -DBL_MAX;

  bool expectedValue = false;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test06) {
  double initValue = DBL_MAX_10_EXP;

  bool expectedValue = true;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
TEST(SignTestCase, Test07) {
  double initValue = -DBL_MAX_10_EXP;

  bool expectedValue = false;
  RootFinderStub testObject;

  bool resultValue = testObject.signTransit(initValue);

  EXPECT_EQ(expectedValue, resultValue);
}
/******************************************************/

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
