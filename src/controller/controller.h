#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#include <utility>

#include "../model/smartCalc.h"
namespace s21 {
class CalculatorController {
 public:
  CalculatorController() {}
  CalculatorController(std::string expression) : calc_(std::move(expression)) {}
  double calculateExpression(double xValue = 0);
  LoanResults calculateCredit(const LoanInfo &info);
  DepositResults calculateDeposit(const DepositInfo &info);

 private:
  SmartCalc calc_;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
