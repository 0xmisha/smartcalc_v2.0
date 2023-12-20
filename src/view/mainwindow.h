#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <cmath>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::CalculatorController controller;

 private slots:
  void get_input();
  void on_pushButton_clicked();
  void on_calculate_credit_button_clicked();
  void on_pushButton_calculate_debit_clicked();
};
#endif  // MAINWINDOW_H
