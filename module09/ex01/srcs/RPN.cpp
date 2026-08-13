#include "RPN.hpp"
#include <stack>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
  (void)other;
}

RPN &RPN::operator=(const RPN &other) {
  (void)other;
  return *this;
}

RPN::~RPN() {}

bool RPN::isArithmeticOperator(const char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isDigit(const char c) {
  return (std::isdigit(static_cast<unsigned char>(c)));
}

bool RPN::isValidInputCharacter(const char c) {
  return (isArithmeticOperator(c) || isDigit(c) || c == ' ');
}

void RPN::validateExpression(const std::string str) {
  for(size_t i = 0; i < str.size(); i++)
    if(!isValidInputCharacter(str[i]))
      throw std::invalid_argument(std::string("Invalid character: '") + str[i] + "'. Expected a digit from '0' to '9' or an operator '+', '-', '*', '/'.");
}

int RPN::popAndReturnTop(std::stack<int> &s) {
  const int top = s.top();
  s.pop();
  return top;
}

bool RPN::isAdditionOverflow(const int a, const int b) {
  if (b > 0)
    return a > INT_MAX - b;
  else
    return a < INT_MIN - b;
}

int RPN::addition(const int a, const int b) {
  if (isAdditionOverflow(a, b))
    throw std::overflow_error("Addition overflow.");
  return b + a;
}

bool RPN::isSubtractionOverflow(const int a, const int b) {
  if (b > 0)
    return a < INT_MIN + b;
  else
    return a > INT_MAX + b;
}

int RPN::subtract(const int a, const int b) {
  if (isSubtractionOverflow(a, b))
    throw std::overflow_error("Subtraction overflow.");
  return b - a;
}

bool RPN::isMultiplicationOverflow(const int a, const int b) {
  if (a > 0) {
    if (b > 0)
      return a > INT_MAX / b;
    else
      return b < INT_MIN / a;
  } else {
    if (b > 0)
      return a < INT_MIN / b;
    else
      return (a != 0 && b < INT_MAX / a);
  }
}

int RPN::multiply(const int a, const int b) {
  if (isMultiplicationOverflow(a, b))
    throw std::overflow_error("Multiplication overflow.");
  return b * a;
}

bool RPN::isDivisionOverflow(const int a, const int b) {
  return (b == -1 && a == INT_MIN);
}

int RPN::divide(const int a, const int b) {
  if(a == 0)
    throw std::invalid_argument("Division by zero.");
  if (isDivisionOverflow(a, b))
    throw std::overflow_error("Division overflow.");
  return b / a;
}

int RPN::performOperation(const int a, const int b, const char c) {
  switch(c) {
    case '+':
      return addition(a, b);
    case '-':
      return subtract(a, b);
    case '*':
      return multiply(a, b);
    default:
      return divide(a, b);
  }
}

int RPN::reversePolishNotation(const std::string &str) {
  std::stack<int> stack;

  validateExpression(str);

  for(size_t i = 0; i < str.size(); i++) {
    if(isDigit(str[i]))
      stack.push(str[i] - '0');
    else if(str[i] == ' ')
      continue;
    else if(isArithmeticOperator(str[i])) {
      if (stack.size() < 2)
        throw std::invalid_argument("Invalid expression: not enough operands for operator '" + std::string(1, str[i]) + "'.");
      stack.push(performOperation(popAndReturnTop(stack), popAndReturnTop(stack), str[i]));
    }
  }
  if(stack.size() != 1)
    throw std::invalid_argument("Invalid expression: too many operands.");
  return stack.top();
}
