#include <algorithm>  // Ensure this include is present

#include "s21_model.h"

namespace s21 {
//-------------Validator part-------------//
std::string ModelValidator::GetterStr() { return str_; }
std::string ModelValidator::GetterAns() { return ans_; }

bool ModelValidator::GetterError() { return error_; }

bool ModelValidator::IsOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

bool ModelValidator::IsBracket(char c) { return c == '(' || c == ')'; }


int ModelValidator::CheckStr(const char *expression) {
  int status = 0;
  int brackets_count = 0;
  bool dot_find = false;
  bool minus_inside_brackets = false;

  // Проверка на пустое выражение
  if (expression[0] == '\0' ||
      (expression[0] == '(' && expression[1] == ')' && expression[2] == '\0')) {
    status = 1;
  } else if (strlen(expression) == 1 && IsOperator(expression[0])) {
    // Одиночный знак минус ("-") является недопустимым выражением
    status = 1;
  } else {
    // char str_func[18] = "cosintaqrlogd";
    char str_op[15] = "*/^%)";
    char str_check[24] = "1234567890*%/+-()^.,";
    size_t len_expression = strlen(expression);

    if (IsOperator(expression[len_expression - 1]) ||
        strchr(str_op, expression[0]) != NULL) {
      // Выражение заканчивается оператором без правого/левого операнда
      status = 1;
    } else if (expression[0] == '.' && expression[1] == '\0') {
      status = 1;
    } else {
      for (size_t i = 0; i < len_expression && status != 1; i++) {
        if ((expression[i - 1] == '/' || expression[i - 1] == '%') &&
            expression[i] == '0') {
          status = 1;
        }
        if ((expression[i - 2] == 't' && expression[i - 1] == '(') &&
            expression[i] == '-') {
          status =1;
        }
        if ((expression[i - 2] == 'g' && expression[i - 1] == '(') &&
            expression[i] == '0') {
          status = 1;
        }

        if (isdigit(expression[i]) && expression[i + 1] == ' ' &&
            isdigit(expression[i + 2])) {
          status = 1;
        }

        if ((IsOperator(expression[i]) && expression[i + 1] == ' ' &&
             IsOperator(expression[i + 2]))) {
          // Повторение оператора или пробела перед оператором
          status =1;
        }
        if (expression[i] == '(' && expression[i + 1] == ')') {
          status =1;
        }

        if (IsOperator(expression[i])) {
          if (i > 0 && IsOperator(expression[i - 1])) {
            // Найдено повторение оператора
            status = 1;
          }
        }

        if (!isdigit(expression[i]) && expression[i] != '.' &&
            expression[i] != '(' && expression[i] != ')' &&
            expression[i] != '+' && expression[i] != '-' &&
            expression[i] != '*' && expression[i] != '/'
             &&
            // expression[i] != '^' && strchr(str_func, expression[i]) == NULL &&
            strchr(str_check, expression[i]) == NULL) {
          // Найден недопустимый символ
          status =1;
        }

        if (expression[i] == '(') {
          brackets_count++;
        } else if (expression[i] == ')') {
          brackets_count--;
          if (brackets_count < 0) {
            // Неуравновешенные скобки
            status = 1;
          }
        }

        // Остальная логика проверки выражения
        if (expression[i] == '.') {
          if (dot_find) {
            // Найдена десятичная точка второй раз
            status = 1;
          }
          dot_find = true;
        } else {
          dot_find = false;
        }

        if (expression[i] == '-') {
          if (expression[i - 1] == '(' && expression[i + 1] == ')') {
            // Использование (-) - некорректное выражение
            status = 1;
          }

          if (expression[i - 1] == '(') {
            minus_inside_brackets = true;
          } else if (expression[i - 1] == ')' && minus_inside_brackets) {
            // Использование (-) внутри скобок - некорректное выражение
            status = 1;

          } else {
            minus_inside_brackets = false;
          }
        }
      }

      if (brackets_count != 0) {
        // Неуравновешенные скобки
        status =1;
      }
    }
  }

  return status;
}

void ModelValidator::SetterStr(std::string str) {
  str_ = str;
  ans_ = str_;  // Copying str to ans, unsure why addition was used in the previous code

  // Remove all spaces
  str_.erase(std::remove(str_.begin(), str_.end(), ' '), str_.end());

  // You need to loop through each character if you want to check brackets for each
  for (char c : str_) {
    if (!IsBracket(c)) {
      error_ = CheckStr(str_.c_str());  // Assuming CheckStr can handle the whole string
      break;
    }
  }

  // Assuming some logic needs to be applied if no errors
  if (!error_) {
    auto nullpos = ans_.find('\0');
    if (nullpos != std::string::npos)
      ans_.resize(nullpos);
  }

  // Additional methods not shown should be handled similarly
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