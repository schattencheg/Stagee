#include "SolverDichotomyBoost.h"

SolverDichotomyBoost::SolverDichotomyBoost() {}

vector<double> SolverDichotomyBoost::solve(const ContDiffFunction *f, double left,
                                 double right) {
  if (f->isDegenerative()) { return vector<double>{}; }
  vector<double> pointsOfInterest = findSignDiffPoints(f, left, right);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size() - 1; i++) {
    vector<double> tempRoot =
        divByTwo(f, pointsOfInterest[i], pointsOfInterest[i + 1]);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<double> SolverDichotomyBoost::findSignDiffPoints(const ContDiffFunction *f,
                                              double left, double right) {
  cpp_bin_float_1000 step = 0.1;
  cpp_bin_float_1000 cur = f->derivValue(left);
  cpp_bin_float_1000 tmp = f->derivValue(left);

  vector<cpp_bin_float_1000> values;
  values.push_back(left);
  for (cpp_bin_float_1000 x = left + step; x < right; x += step) {
    cur = f->derivValue(static_cast<float>(x));
    if (cur*tmp<=0.0) {
      values.push_back(x);
      values.push_back(x + step);
    }
    tmp = cur;
  }
  values.push_back(right);

  vector<double> result;
  for (int i = 0; i < values.size(); i++)
      result.push_back(static_cast<float>(values[i]));
  return result;
}

bool SolverDichotomyBoost::sign(double value)
{
    return (value >= -epsilon) ? true : false;
}

vector<double> SolverDichotomyBoost::divByTwo(const ContDiffFunction *f, double left,
                                    double right) {
  double middle = (left + right) / 2.0;
  while ((!isRoot(f, middle))||(left==middle)||(middle==right)) {
    double lft = f->value(left);
    double rgt = f->value(right);
    double mid = f->value(middle);

    if (sign(lft) != sign(mid)) {
      right = middle;
    } else if (sign(rgt) != sign(mid)) {
      left = middle;
    } else {
      break;
    }
    middle = (left + right) / 2.0;
  }
  vector<double> result;
  if (isRoot(f, middle)) result.push_back(middle);
  return result;
}

bool SolverDichotomyBoost::isRoot(const ContDiffFunction *f, double value) {
  return (fabs(f->value(value)) < epsilon) ? true : false;
}
