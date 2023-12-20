#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_equals, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(get_input()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(get_input()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(get_input()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(get_input()));

  ui->widget->setBackground(QColor(57, 57, 57));
  ui->widget->xAxis->grid()->setVisible(false);
  ui->widget->yAxis->grid()->setVisible(false);
  ui->lineEdit_2->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_3->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_4->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_5->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));

  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);
  ui->widget->xAxis->setBasePen(QPen(Qt::white));
  ui->widget->yAxis->setBasePen(QPen(Qt::white));

  ui->widget->xAxis->setTickPen(QPen(Qt::white));
  ui->widget->yAxis->setTickPen(QPen(Qt::white));

  ui->widget->xAxis->setTickLabelColor(Qt::white);
  ui->widget->yAxis->setTickLabelColor(Qt::white);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::get_input() {
  QPushButton *button = (QPushButton *)sender();
  QString pressedKey = button->text();
  int isFuncStatus =
      pressedKey.compare("sin") == 0 || pressedKey.compare("asin") == 0 ||
      pressedKey.compare("cos") == 0 || pressedKey.compare("acos") == 0 ||
      pressedKey.compare("tan") == 0 || pressedKey.compare("atan") == 0 ||
      pressedKey.compare("log") == 0 || pressedKey.compare("ln") == 0 ||
      pressedKey.compare("sqrt") == 0;
  if (pressedKey.compare("CE") == 0) {
    ui->result_label->setText("");
  } else if (isFuncStatus) {
    pressedKey.push_back("(");
    ui->result_label->setText(ui->result_label->text() + pressedKey);
  } else if (pressedKey.compare("%") == 0) {
    pressedKey = "mod";
    ui->result_label->setText(ui->result_label->text() + pressedKey);
  } else if (pressedKey.compare("÷") == 0) {
    pressedKey = "/";
    ui->result_label->setText(ui->result_label->text() + pressedKey);
  } else if (pressedKey.compare("=") == 0) {
    QString myString = ui->result_label->text();
    if (!myString.isEmpty()) {
      std::string string = myString.toStdString();
      try {
        s21::CalculatorController controller(string);
        double result = controller.calculateExpression();
        ui->result_label->setText(QString::number(result));
      } catch (const std::invalid_argument &e) {
        ui->result_label->setText(QString::fromStdString(e.what()));
      }
    }
  } else {
    ui->result_label->setText(ui->result_label->text() + pressedKey);
  }
}

void MainWindow::on_pushButton_clicked() {
  ui->widget->clearGraphs();
  QString function = ui->lineEdit->text();
  if (function.count(' ') != function.length()) {
    std::string string = function.toStdString();

    QVector<double> x, y;

    double xAxisStart = ui->lineEdit_3->text().toDouble();
    double xAxisEnd = ui->lineEdit_4->text().toDouble();
    double yAxisStart = ui->lineEdit_2->text().toDouble();
    double yAxisEnd = ui->lineEdit_5->text().toDouble();
    double step = ui->lineEdit_step->text().toDouble();

    if (xAxisStart == 0 || xAxisEnd == 0) {
      xAxisStart = -10;
      xAxisEnd = 10;
    }

    if (step == 0) {
      step = 0.1;
    }

    ui->widget->xAxis->setRange(xAxisStart, xAxisEnd);
    ui->widget->yAxis->setRange(yAxisStart, yAxisEnd);
    s21::CalculatorController controller(string);

    for (double X = xAxisStart; X <= xAxisEnd; X += step) {
      X = round(X * 10000000) / 10000000;
      x.push_back(X);
      try {
        y.push_back(controller.calculateExpression(X));
      } catch (const std::invalid_argument &e) {
        ui->lineEdit->setText(QString::fromStdString(e.what()));
      }
    }

    ui->widget->addGraph();
    QPen pen(Qt::white);
    pen.setWidth(3);

    ui->widget->graph(0)->setPen(pen);
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
  }
}

void MainWindow::on_calculate_credit_button_clicked() {
  LoanType creditType;
  if (ui->radioButton_differentiated->isChecked()) {
    creditType = LoanType::DIFFERENTIATED;
  }
  if (ui->radioButton_annuity->isChecked()) {
    creditType = LoanType::ANNUITY;
  }

  s21::LoanInfo info = {ui->lineEdit_total_credit->text().toDouble(),
                        ui->lineEdit_term->text().toInt(),
                        ui->lineEdit_interest_rate->text().toDouble(),
                        creditType};

  s21::CalculatorController controller;
  s21::LoanResults results = controller.calculateCredit(info);

  ui->lineEdit_monthly_payment->setText(
      QString::number(results.monthlyPayment));
  ui->lineEdit_overpayment->setText(QString::number(results.totalInterest));
  ui->lineEdit_total_payment->setText(QString::number(results.totalPayment));
}

void MainWindow::on_pushButton_calculate_debit_clicked() {
  s21::DepositInfo info(ui->lineEdit_deposit_amount->text().toDouble(),
                        ui->lineEdit_deposit_term->text().toInt(),
                        ui->lineEdit_interest_rate_debit->text().toDouble(),
                        ui->lineEdit_tax_rate->text().toDouble(),
                        ui->lineEdit_periodicity->text().toInt(),
                        ui->radioButton_capitalization->isChecked(),
                        ui->lineEdit_replenishments->text().toDouble(),
                        ui->lineEdit_partial_withdrawal->text().toDouble());

  s21::CalculatorController controller;
  s21::DepositResults results = controller.calculateDeposit(info);

  ui->lineEdit_accrued_interest->setText(
      QString::number(results.accruedInterest));
  ui->lineEdit_tax_amount->setText(QString::number(results.taxAmount));
  ui->lineEdit_final_despoit->setText(QString::number(results.finalAmount));
}
