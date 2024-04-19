#include "s21_model.h"

namespace s21 {
//-------------Validator part-------------//
std::string ModelValidator::GetterStr() { return str_; }
std::string ModelValidator::GetterAns() { return ans_; }

bool ModelValidator::GetterError() { return error_; }

// bool ModelValidator::is_operator(char c) {
//   return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
// }

// bool ModelValidator::is_trigo(char c) {
//   return (c == 's') || (c == 'c') || (c == 't') || (c == 'S') || (c == 'C') ||
//          (c == 'T') || (c == 'k') || (c == 'l' || (c == 'L'));
// }

// bool ModelValidator::is_bracket(char c) { return c == '(' || c == ')'; }



bool ModelValidator::BracketsAnsver() {
  std::stack<char> brackets;
  for (char c : str_) {
    if (c == '(')
      brackets.push(c);
    else if (c == ')') {
      if (brackets.empty()) return true;
      char top = brackets.top();
      brackets.pop();
      if (c == ')' && top != '(') return true;
    }
  }
  return !brackets.empty();
}


void ModelValidator::SetterStr(std::string str) {
  str_ = str;
  ans_ = str_ + str_;
  str_.erase(remove(str_.begin(), str_.end(), ' '), str_.end());
  if (!BracketsAnsver())
    error_ = Check();
  else
    error_ = BracketsAnsver();
  if (!error_) ans_.resize(ans_.find('\0'));
  // SingleTarget();
  // DlsCheck();
}
bool ModelValidator::Check() {
  bool error = false;
  int k = 0;
  for (size_t i = 0; i < str_.length() && error == 0; i++) {
  
   
     if (i + 1 < str_.length() && str_[i] == '(' && str_[i + 1] == '-') {
      ans_[k++] = '(';
      ans_[k++] = '0';
    } else if (i == 0 && str_[i] == '+') {
      if (str_.length() == 1) error = true;
      ans_[k++] = '0';
      ans_[k++] = '+';
    } else if (i + 1 < str_.length() && str_[i] == '(' && str_[i + 1] == '+') {
      ans_[k++] = '(';
      ans_[k++] = '0';
    } else if (CheckSymbols(i)) {
      error = true;
    } else if (IsNumberOrSign(str_[i])) {
      ans_[k++] = str_[i];
    } else {
      error = true;
    }
  }
  ans_[k++] = '\0';
  return error;
}

bool ModelValidator::CheckSymbols(int i) {
  bool err = false;
  // if ((str_[i] == 'x' || str_[i] == ')') && str_[i + 1] != '\0' &&
  //     ((str_[i + 1] >= '0' && str_[i + 1] <= '9') || str_[i + 1] == 'x')) {
  //   err = true;
  // if (str_[i + 1] != '\0' &&
  //            (str_[i + 1] == 'x' || str_[i + 1] == '(') &&
  //            ((str_[i] >= '0' && str_[i] <= '9') || str_[i] == 'x')) {
  //   err = true;
if ((str_[i] == '+' || str_[i] == '-') &&
             (str_[i + 1] == '*' || str_[i + 1] == '/' || str_[i + 1] == '^' ||
              str_[i + 1] == '\0')) {
    err = true;
  } else if ((str_[i] == '+' || str_[i] == '-') &&
             (str_[i + 1] == '+' || str_[i + 1] == '-')) {
    err = true;
  } else if ((str_[i] == '*' || str_[i] == '/' || str_[i] == '^') &&
             (str_[i + 1] == '*' || str_[i + 1] == '/' || str_[i + 1] == '^' ||
               str_[i + 1] == '\0')) {
    err = true;
  // } else if (str_[i] == ')' &&
  //            (str_[i + 1] == 'x' || (str_[i + 1] >= '0' && str_[i + 1] <= 9) ||
  //             str_[i + 1] == 'c' || str_[i + 1] == 's' || str_[i + 1] == 't' ||
  //             str_[i + 1] == 'a' || str_[i + 1] == 'l')) {
  //   err = true;
  // } else if (str_[i] == '(' &&
  //            (str_[i + 1] == ')' || str_[i + 1] == '*' || str_[i + 1] == '/' ||
  //             str_[i + 1] == 'm' || str_[i + 1] == '^')) {
  //   err = true;
  // } else if (str_[i] == '.' &&
  //            (str_[i + 1] == '.' || str_[i + 1] == '+' || str_[i + 1] == '-' ||
  //             str_[i + 1] == '*' || str_[i + 1] == '/' || str_[i + 1] == '(' ||
  //             str_[i + 1] == ')' || str_[i + 1] == '^' || str_[i + 1] == 'm' ||
  //             str_[i + 1] == 'c' || str_[i + 1] == 's' || str_[i + 1] == 't' ||
  //             str_[i + 1] == 'a' || str_[i + 1] == 'l')) {
  //   err = true;
  // }
              }
  return err;
}

bool ModelValidator::IsNumberOrSign(char a) {
  int err = false;
  if ((a >= '0' && a <= '9') || a == '/' || a == '*' || a == '(' || a == ')' ||
      a == '+' || a == '-' || a == '^' || a == 'x' || a == '.')
    err = true;
  return err;
}

//-------------Calculator part-------------
std::string ModelCalculator::getterAns() { return ans_; }

void ModelCalculator::setter_ans(std::string ans, double x) {
  ans_ = ans;
  x_ = x;
  postfix();
  error_ = from_postfix();
}

bool ModelCalculator::GetterError() { return error_; }

double ModelCalculator::getterResult() { return result_; }

int ModelCalculator::priopity_of_functions(char a) {
  // switch (a) {
  //   case '+':
  //   case '-':
  //     return 1;
  //   case '*':
  //   case '/':
  //   case '%':
  //     return 2;
  //   case 's':
  //   case 'c':
  //   case 't':
  //   case 'S':
  //   case 'C':
  //   case 'T':
  //   case 'k':
  //   case 'l':
  //   case 'L':
  //     return 3;
  //   case '^':
  //     return 4;
  //   default:
  //     return 0;
  // }

  int out = 1;
  if (a == 'c' || a == 's' || a == 't' || a == 'C' || a == 'S' || a == 'T' ||
      a == 'q' || a == 'l' || a == 'L')
    out = 5;
  if (a == '^') out = 4;
  if (a == '*' || a == '/' || a == 'm') out = 3;
  if (a == '+' || a == '-') out = 2;
  if (a == '(' || a == ')') out = 1;
  if ((a >= '0' && a <= '9') || a == '.') out = 0;
  // if (a == '0') out = 6;
  return out;
}
void ModelCalculator::postfix() {
  std::stack<char> operators;
  for (size_t i = 0; i < ans_.length(); i++) {
    if ((ans_[i] >= '0' && ans_[i] <= '9') || ans_[i] == '.' ||
        ans_[i] == 'x') {
      // if (!operators.empty() && !operators.top() == '0') operators.
      postfix_.push_back(ans_[i]);
    } else if (priopity_of_functions(ans_[i]) >= 2 &&
               priopity_of_functions(ans_[i]) <= 5) {
      postfix_.push_back(' ');
      if (operators.empty()) {
        operators.push('0');  // operators
      }
      if (!operators.empty() && priopity_of_functions(operators.top()) <
                                    priopity_of_functions(ans_[i])) {
        operators.push(ans_[i]);
      } else if (!operators.empty() && priopity_of_functions(operators.top()) >=
                                           priopity_of_functions(ans_[i])) {
        while (!operators.empty() && priopity_of_functions(operators.top()) >=
                                         priopity_of_functions(ans_[i])) {
          postfix_.push_back(operators.top());
          operators.pop();
          postfix_.push_back(' ');  //
        }
        operators.push(ans_[i]);
      }
    } else if (ans_[i] == '(') {
      postfix_.push_back(' ');
      operators.push(ans_[i]);
    } else if (ans_[i] == ')') {
      postfix_.push_back(' ');
      while (operators.top() != '(') {
        postfix_.push_back(operators.top());
        operators.pop();
        postfix_.push_back(' ');
      }
      operators.pop();
    }
  }
  while (operators.empty() or operators.top() != '0') {
    if (operators.empty()) break;
    postfix_.push_back(' ');
    postfix_.push_back(operators.top());
    operators.pop();
  }
}
bool ModelCalculator::from_postfix() {
  std::stack<double> numbersStack;
  for (size_t i = 0; i < postfix_.length() && !error_; i++) {
    if (((postfix_[i] >= '0' && postfix_[i] <= '9') || postfix_[i] == '.') &&
        !error_) {
      // char number[postfix_.length()] = "";
      std::string number = "";
      int k = 0;
      int countDouble = 0;
      while (
          ((postfix_[i] >= '0' && postfix_[i] <= '9') || postfix_[i] == '.') &&
          !error_) {
        if (postfix_[i] == '.') {
          countDouble++;
        }
        if (countDouble >= 2) {
          error_ = true;
        }
        number[k++] = postfix_[i];
        i++;
      }
      number[k] = '\0';
      double a = atof(number.c_str());
      numbersStack.push(a);
    } else if (postfix_[i] == 'x') {
      numbersStack.push(x_);
    } else if (priopity_of_functions(postfix_[i]) == 2 ||
               priopity_of_functions(postfix_[i]) == 3 ||
               priopity_of_functions(postfix_[i]) == 4) {
      double b = numbersStack.top();
      numbersStack.pop();
      if (numbersStack.empty()) {
        error_ = true;
      } else {
        double a = numbersStack.top();
        numbersStack.pop();
        double c = operation_calc_binar(a, b, i);
        if (!error_) {
          numbersStack.push(c);
        }
      }
    } else if (priopity_of_functions(postfix_[i]) == 5 &&
               !numbersStack.empty()) {
      double a = numbersStack.top();
      numbersStack.pop();
      double c = operation_calc_unar(a, postfix_[i]);
      numbersStack.push(c);
    }
  }
  if (error_ == false) result_ = numbersStack.top();
  return error_;
}

double ModelCalculator::operation_calc_binar(double a, double b, int i) {
  double res = 0;
  switch (postfix_[i]) {
    case '+':
      res = a + b;
      break;
    case '-':
      res = a - b;
      break;
    case '*':
      res = a * b;
      break;
    case '/':
      if (b == 0)
        error_ = true;
      else
        res = a / b;
      break;
    case 'm':
      if (b == 0)
        error_ = true;
      else
        res = fmodl(a, b);
      break;
    case '^':
      res = pow(a, b);
      break;
  }
  return res;
}

double ModelCalculator::operation_calc_unar(double a, char oper) {
  double res = 0;
  switch (oper) {
    case 'c':
      res = cos(a);
      break;
    case 's':
      res = sin(a);
      break;
    case 't':
      res = tan(a);
      break;
    case 'C':
      res = acos(a);
      break;
    case 'S':
      res = asin(a);
      break;
    case 'T':
      res = atan(a);
      break;
    case 'q':
      res = sqrt(a);
      break;
    case 'L':
      res = log(a);
      break;
    case 'l':
      res = log10(a);
      break;
  }
  return res;
}

double Model::target(const std::string str, bool *error, double x) {
  validator_.SetterStr(str);
  if (!validator_.GetterError()) {
    calculator_.setter_ans(validator_.GetterAns(), x);
    if (!calculator_.GetterError()) {
      return calculator_.getterResult();
    } else {
      *error = true;
    }
  } else {
    *error = true;
  }
  return 0;
}

// 

}  // namespace s21

/*
 int main() {
     std::string arg = "2.354.36+1";
     //ModelValidator(str_m);
     //str_m.SetterStr(arg);
     //ModelCalculator(ansver);
     //if (!str_m.GetterError()) {
     //    ansver.setter_ans(str_m.GetterAns());
     //}
     //std::cout << "Validator_part" << std::endl;
     //std::cout << str_m.GetterStr() << std::endl;
     //std::cout << str_m.GetterAns() << std::endl;
     //std::cout << str_m.GetterError() << std::endl;
     //std::cout << "Calc_part" << std::endl;
     //std::cout << ansver.getterAns() << std::endl;
     //std::cout << ansver.getterPostfix() << std::endl;
     //std::cout << ansver.GetterError() << std::endl;
     //std::cout << ansver.getterResult() << std::endl;
     double x = 25;
     s21::Model m;
     bool error;
     std::cout << m.target(arg, &error, x) << std::endl;
     std::cout << error << std::endl;
     return 0;

 }
*/

/*
// cred
int main() {
    s21::Model m;
    double loanAmount = 2000000;
    int term = 180;
    double interestRate = 8.6;
    int type = 2;
    char *monthlyPayment;
    double overpayment = 0;
    double totalPayment = 0;
    m.TargetCred(loanAmount, term, interestRate, type, monthlyPayment,
&overpayment, &totalPayment);
    if (std::strcmp(monthlyPayment, "25444.44 ... 11190.74")==0) {
      std::cout << true << " -> 1" << std::endl;
    }
    if (overpayment == 1297166.67) {
      std::cout << true << " -> 2" << std::endl;
    }
    if (totalPayment == 3297166.67) {
      std::cout << true << " -> 3" << std::endl;
    }
//printf("overpayment = %f\n",overpayment);
//printf("totalPayment = %f\n", totalPayment);
//printf("monthlyPayment = %s\n", monthlyPayment);
    return 0;
}
*/

/* graf
int main() {
    s21::Model m;
    std::string str = "x+1";
    bool error = false;
    double xBegin = -1;
    double xEnd = 1;
    double yBegin = -1;
    double yEnd = 1;
    bool result = true;
    double x = -1;
    double y = 0;
    std::vector<std::pair<double, double>> p = m.TargetGraf(str, &error, xBegin,
xEnd, yBegin, yEnd); for (const auto &pair : p) { y = x + 1; if (x !=
pair.first) { result = false; break;
      }
      if (y != pair.second) {
        result = false;
        break;
      }
      x += 0.01;
  }
  std::cout << result << std::endl;
  return 0;
}
*/