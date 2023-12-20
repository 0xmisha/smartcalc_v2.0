#include "controller.h"

namespace s21 {
double CalculatorController::calculateExpression(const double xValue) {
  return calc_.calcExpression(xValue);
}

LoanResults CalculatorController::calculateCredit(const LoanInfo &info) {
  return SmartCalc::calcCredit(info);
}

DepositResults CalculatorController::calculateDeposit(const DepositInfo &info) {
  return SmartCalc::calcDeposit(info);
}
}  // namespace s21