#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_FINANCEUTILS_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_FINANCEUTILS_H_

#include <iostream>

enum class LoanType { ANNUITY, DIFFERENTIATED };
namespace s21 {
class LoanInfo {
 public:
  double totalLoan;
  int months;
  double annualRate;
  LoanType type;

  LoanInfo(double total, int m, double rate, LoanType t)
      : totalLoan(total), months(m), annualRate(rate), type(t) {}
};

class DepositInfo {
 public:
  double initialAmount;
  int termMonths;
  double annualRate;
  double taxRate;
  int accrualPeriodicity;  // 1 - every month, 12 - annually, etc.
  bool capitalization;
  double additions;
  double withdrawals;

  DepositInfo(double initial, int term, double rate, double tax,
              int periodicity, bool cap, double add, double withdraw)
      : initialAmount(initial),
        termMonths(term),
        annualRate(rate),
        taxRate(tax),
        accrualPeriodicity(periodicity),
        capitalization(cap),
        additions(add),
        withdrawals(withdraw) {}
};

class LoanResults {
 public:
  double monthlyPayment;
  double totalInterest;
  double totalPayment;
};

class DepositResults {
 public:
  double accruedInterest;
  double taxAmount;
  double finalAmount;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_FINANCEUTILS_H_