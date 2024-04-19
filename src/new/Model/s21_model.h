#ifndef CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H
#define CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace s21 {
class ModelValidator {
 public:
  /*ConstructorsPart*/
  ModelValidator() = default;
  ~ModelValidator() = default;
  /*GettersPart*/
  std::string GetterStr();
  bool GetterError();
  std::string GetterAns();
  /*SettersPart*/
  void SetterStr(std::string str);

 private:
  /*VariablesPart*/
  std::string str_{};
  std::string ans_{};
  bool error_ = false;
  /*FuncPart*/
  // bool is_operator(char c);
  // bool is_trigo(char c);
  // bool is_bracket(char c);
  bool CheckSymbols(int i);
  bool IsNumberOrSign(char a);
  bool BracketsAnsver();
  bool Check();
  // void SingleTarget();
  // void DlsCheck();
};
class ModelCalculator {
 public:
  /*ConstructorsPart*/
  ModelCalculator() = default;
  ~ModelCalculator() = default;
  /*GettersPart*/
  std::string getterAns();
  bool GetterError();
  double getterResult();
  /*SettersPart*/
  void setter_ans(std::string ans, double x);

 private:
  /*VariablesPart*/
  std::string ans_{};
  std::string postfix_{};
  bool error_ = false;
  double result_ = 0;
  double x_ = 0;
  /*FuncPart*/
  void postfix();
  int priopity_of_functions(char a);
  bool from_postfix();
  double operation_calc_binar(double a, double b, int i);
  double operation_calc_unar(double a, char oper);
};

class Model {
 public:
  /*ConstructorsPart*/
  Model() = default;
  ~Model() = default;
  /*FuncPart*/
  double target(const std::string str, bool *error, double x);
  /*FuncGraf*/

 private:
  /*VariablesPart*/
  ModelValidator validator_{};
  ModelCalculator calculator_{};
  /*ForCred*/
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_CALCULATOR_S21_MODEL_H