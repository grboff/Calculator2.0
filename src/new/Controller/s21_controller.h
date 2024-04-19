#ifndef CPP3_SMARTCALC_V2_CALCULATOR_S21_CONTROLLER_H
#define CPP3_SMARTCALC_V2_CALCULATOR_S21_CONTROLLER_H

#include "../Model/s21_model.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  ~Controller() = default;
  Controller(Model *m) : model_(m){};

  double Start(std::string str, bool *error, double x);
  // std::vector<std::pair<double, double>> StartGraf(std::string str, bool *error,
  //                                                  double xBegin, double xEnd,
  //                                                  double yBegin, double yEnd);
  // void StartCred(double loanAmount, int term, double interestRate, int type,
  //                char *monthlyPayment, double *overpayment,
  //                double *totalPayment);

 private:
  /*main*/
  Model *model_{};
  /*for cred*/
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_CALCULATOR_S21_CONTROLLER_H