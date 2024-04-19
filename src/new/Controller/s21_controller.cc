#include "s21_controller.h"

namespace s21 {
double Controller::Start(std::string str, bool *error, double x) {
  return model_->target(str, error, x);
}

// std::vector<std::pair<double, double>> Controller::StartGraf(
//     std::string str, bool *error, double xBegin, double xEnd, double yBegin,
//     double yEnd) {
//   return model_->TargetGraf(str, error, xBegin, xEnd, yBegin, yEnd);
// }

// void Controller::StartCred(double loanAmount, int term, double interestRate,
//                            int type, char *monthlyPayment, double *overpayment,
//                            double *totalPayment) {
//   model_->TargetCred(loanAmount, term, interestRate, type, monthlyPayment,
//                      overpayment, totalPayment);
// }

}  // namespace s21

/*
int main() {
  std::string str = "x*2";
  //long double origin = 1;
  bool error = 0;
  s21::Model model;
  s21::Controller control(&model);
  std::vector<std::pair<double, double>> p;

  p = control.StartGraf(str, &error, -10, 10,-10,10);
  for (auto iter = p.begin(); iter != p.end(); iter++) {
    std::cout << (*iter).first << " " << (*iter).second << std::endl;
  }
  std::cout << error << std::endl;
  return 0;
}
*/
/*
int main() {
  double loanAmount = 100000;
  int term = 360;
  double interestRate = 10;
  int type = 1;
  char* monthlyPayment;
  double* overpayment;
  double* totalPayment;
  bool error = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.StartCred(loanAmount, term, interestRate, type, monthlyPayment,
overpayment, totalPayment); std::cout << error << std::endl; return 0;
}
*/
/*
//graf
int main() {
  std::string str = "x+1";
  //long double origin = 1;
  bool error = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.StartGraf(str, &error);
  std::cout << error << std::endl;
  return 0;
}
*/
/*
int main() {
  std::string str = "42x";
  //long double origin = 1;
  bool error = 0;
  s21::Model model;
  double x = 25;
  s21::Controller control(&model);
  std::cout << control.Start(str, &error, x) << std::endl;
  std::cout << error << std::endl;
  return 0;
}

*/
// int main() {
//   std::string str = "x+1";
//   //long double origin = 1;
//   bool error = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   control.StartGraf(str, &error);
//   for (int i=0; i < 256; i++) {
//       std::cout << model.GetterArray()[i] << std::endl;
//   }
//     std::cout << error << std::endl;
//     return 0;
// }