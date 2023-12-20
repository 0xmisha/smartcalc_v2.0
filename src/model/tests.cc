#include <gtest/gtest.h>

#include "financeUtils.h"
#include "smartCalc.h"

// g++ -std=c++17 -isystem /opt/homebrew/Cellar/googletest/1.14.0/include
// -L/opt/homebrew/Cellar/googletest/1.14.0/lib -lgtest -lgtest_main -pthread
// tests.cc smartCalc.cc && ./a.out

TEST(SmartCalcTest, BasicOperations) {
  s21::SmartCalc calc("0");
  EXPECT_NEAR(calc.calcExpression(0), 0, 1e-5);
}

TEST(SmartCalcTest, Addition) {
  s21::SmartCalc calc("1 + 1");
  EXPECT_NEAR(calc.calcExpression(0), 2, 1e-5);
}

TEST(SmartCalcTest, Subtraction) {
  s21::SmartCalc calc("1 - 1");
  EXPECT_NEAR(calc.calcExpression(0), 0, 1e-5);
}

TEST(SmartCalcTest, Multiplication) {
  s21::SmartCalc calc("3 * 3");
  EXPECT_NEAR(calc.calcExpression(0), 9, 1e-5);
}

TEST(SmartCalcTest, Division) {
  s21::SmartCalc calc("4 / 2");
  EXPECT_NEAR(calc.calcExpression(0), 2, 1e-5);
}

TEST(SmartCalcTest, Power) {
  s21::SmartCalc calc("3^2");
  EXPECT_NEAR(calc.calcExpression(0), 9, 1e-5);
}

TEST(SmartCalcTest, SquareRoot) {
  s21::SmartCalc calc("sqrt(9)");
  EXPECT_NEAR(calc.calcExpression(0), 3, 1e-5);
}

TEST(SmartCalcTest, Logarithm) {
  s21::SmartCalc calc("log(1)");
  EXPECT_NEAR(calc.calcExpression(0), 0, 1e-5);
}

TEST(SmartCalcTest, LogarithmZero) {
  s21::SmartCalc calc("log(0)");
  EXPECT_THROW(calc.calcExpression(0), std::invalid_argument);
}

TEST(SmartCalcTest, LogarithmNegative) {
  s21::SmartCalc calc("log(-1)");
  EXPECT_THROW(calc.calcExpression(0), std::invalid_argument);
}

TEST(SmartCalcTest, Cosine) {
  s21::SmartCalc calc("cos(0)");
  EXPECT_NEAR(calc.calcExpression(0), 1, 1e-5);
}

TEST(SmartCalcTest, Sine) {
  s21::SmartCalc calc("sin(0)");
  EXPECT_NEAR(calc.calcExpression(0), 0, 1e-5);
}

TEST(SmartCalcTest, Tangent) {
  s21::SmartCalc calc("tan(0)");
  EXPECT_NEAR(calc.calcExpression(0), 0, 1e-5);
}

TEST(SmartCalcTest, CreditCalculationAnnuity) {
  s21::SmartCalc calc;
  s21::LoanInfo info{100000, 12, 12, LoanType::ANNUITY};
  s21::LoanResults results = calc.calcCredit(info);
  EXPECT_NEAR(results.monthlyPayment, 8884.88, 1e-2);
}

TEST(SmartCalcTest, CreditCalculationDifferentiated) {
  s21::SmartCalc calc;
  s21::LoanInfo info{100000, 12, 12, LoanType::DIFFERENTIATED};
  s21::LoanResults results = calc.calcCredit(info);
  EXPECT_NEAR(results.monthlyPayment, 8875.00, 1e-2);
}

TEST(SmartCalcTest, DepositCalculation) {
  s21::SmartCalc calc;
  s21::DepositInfo info{1000, 5, 12, 10, 1, 0, 0, false};
  s21::DepositResults results = calc.calcDeposit(info);
  EXPECT_NEAR(results.finalAmount, 995.00, 1e-2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
