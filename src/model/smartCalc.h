#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_SMARTCALC_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_SMARTCALC_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "financeUtils.h"
namespace s21 {
const char kSeparator = '|';

class SmartCalc {
 private:
  static void replaceFunctions(std::string &str);
  void convertInfixToPostfixStr(std::string &infix);
  void convertPostfixStrToVector(const std::string &notation);
  double calcPostfix(const double x);
  void checkBrackets(const std::string &str);

 public:
  SmartCalc() : expression_(""), postfix_() {}
  explicit SmartCalc(std::string expr) : expression_(std::move(expr)) {}
  double calcExpression(double x);

  static LoanResults calcCredit(LoanInfo input);
  static DepositResults calcDeposit(DepositInfo info);

 private:
  static const std::unordered_map<std::string, std::string> replacements_;
  static const std::unordered_map<std::string, int> priority_;

  std::string expression_;
  std::vector<std::string> postfix_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_SMARTCALC_H_
