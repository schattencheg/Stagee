#include <Polynome.h>
#include <RootFinder.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

const double delta = 0.0001;
// a0 + a1*x^1 + a2*x^2 + ... + xn*x^n = 0

TEST(HaveRealRootsTestCase, Test01) {
  /*Create new solver object*/
  RootFinder testObject;

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
  RootFinder testObject;

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

TEST(ValuesTestCase, Test01) {
  vector<double> initValue = {2, -3, 1};

  double solveAt = 3;
  double expectedValue = 2;

  /*Create new polynome object*/
  Polynome polynome(initValue);

  double resultValue = polynome.value(solveAt);

  EXPECT_NEAR(expectedValue, resultValue, delta);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
