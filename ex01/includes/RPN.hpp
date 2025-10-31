#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
  public:
    static int reversePolishNotation(const std::string &str);

  private:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    static void validateExpression(const std::string str);
    static bool isArithmeticOperator(const char c);
    static bool isDigit(const char c);
    static bool isValidInputCharacter(const char c);
    static bool isAdditionOverflow(const int a, const int b);
    static bool isSubtractionOverflow(const int a, const int b);
    static bool isDivisionOverflow(const int a, const int b);
    static bool isMultiplicationOverflow(const int a, const int b);
    static int popAndReturnTop(std::stack<int> &s);
    static int addition(const int a, const int b);
    static int subtract(const int a, const int b);
    static int multiply(const int a, const int b);
    static int divide(const int a, const int b);
    static int performOperation(const int a, const int b, const char c);
};

#endif
