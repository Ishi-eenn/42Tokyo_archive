#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter) {
  (void)scalarConverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter) {
  if (this != &scalarConverter)
    *this = scalarConverter;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

template <typename T>
bool ScalarConverter::isInfinityOrNan(const T &num) {
  static const double inf = std::numeric_limits<double>::infinity();
  return num != num || num == inf || num == -inf;
}

template <typename T>
bool ScalarConverter::isRepresentableAs(const double &num) {
  return std::numeric_limits<T>::min() <= num && num <= std::numeric_limits<T>::max();
}

bool ScalarConverter::isCharLiteral(const std::string &str) {
  const int first = 0;
  const int last = 2;

  if(str.size() != 3)
    return false;
  return str[first] == '\'' && str[last] == '\'';
}

bool ScalarConverter::isIntegerRangeForFloat(const float &num) {
  if (isInfinityOrNan(num))
    return false;

  if (num >= (std::numeric_limits<int>::max() - 1.0f) || num < (std::numeric_limits<int>::min() + 1.0f) || (num >= 0.0f && num < std::numeric_limits<float>::min()))
    return false;
  return true;
}

bool ScalarConverter::isIntegerString(const std::string &str) {
  size_t head = 0;
  if (str[head] == '-' || str[head] == '+')
    head++;

  for (size_t i = head; i < str.size(); i++)
    if (!std::isdigit(str[i]))
      return false;
  return true;
}

bool ScalarConverter::isValidIntegerFormat(const std::string &str) {
  std::stringstream ss(str);
  double num;
  ss >> std::noskipws >> num;

  if (ss.fail() || !ss.eof() || !isIntegerString(str))
    return false;

  return isRepresentableAs<int>(num);
}

bool ScalarConverter::isTypeFloat(const std::string &str) {
  if (str.empty() || str[str.size() - 1] != 'f')
    return false;

  const std::string except_tail_f = str.substr(0, str.size() - 1);

  if (!isValidDoubleFormat(except_tail_f))
    return false;

  std::stringstream ss(except_tail_f);
  double num;
  if (!(ss >> num) || !(ss.eof()))
    return false;

  return isInfinityOrNan<float>(num) || (-std::numeric_limits<float>::max() <= num && num <= std::numeric_limits<float>::max());
}

bool ScalarConverter::isValidDoubleFormat(const std::string &str) {
  if(str == "nan" || str == "-inf" || str == "+inf")
    return true;

  std::stringstream ss(str);
  double num;
  ss >> std::noskipws >> num;

  if (ss.fail() || !ss.eof() || !isDoubleString(str))
    return false;
  return true;
}

bool ScalarConverter::isDoubleString(const std::string &str) {
  size_t head = 0;
  if (str[head] == '-' || str[head] == '+')
    head++;

  for (size_t i = head; i < str.size(); i++)
    if (!(std::isdigit(str[i]) || str[i] == '.'))
      return false;
  return true;
}

template <typename T>
bool ScalarConverter::isValidRange(const double &num) {
  return std::numeric_limits<T>::min() <= num && num <= std::numeric_limits<T>::max();
}

template <typename T>
bool ScalarConverter::isCharRange(const ScalarType type, const T &scalar) {
  if (!isIntegerRange(type, scalar))
    return false;
  return isValidRange<char>(scalar);
}

template <typename T>
bool ScalarConverter::isIntegerRange(const ScalarType type, const T &scalar) {
  if (type == kScalarTypeFloat && !isIntegerRangeForFloat(scalar))
    return false;
  if (type == kScalarTypeDouble && !isValidRange<int>(scalar))
    return false;
  return true;
}

template <typename T>
bool ScalarConverter::isFloatRange(const T &scalar) {
  return isInfinityOrNan(scalar) || (-std::numeric_limits<float>::max() <= scalar && scalar <= std::numeric_limits<float>::max());
}

template <typename T>
void ScalarConverter::printCharRepresentation(const ScalarType type, const T &scalar) {
  if (type == kScalarTypeInvalid || !isCharRange(type, scalar))
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(static_cast<char>(scalar)))
    std::cout << "char: '" << static_cast<char>(scalar) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
}

template <typename T>
void ScalarConverter::printIntegerRepresentation(const ScalarType type, const T &scalar) {
  if (type == kScalarTypeInvalid || !isIntegerRange(type, scalar))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(scalar) << std::endl;
}

template <typename T>
void ScalarConverter::printFloatRepresentation(const ScalarType type, const T &scalar) {
  if (type == kScalarTypeInvalid || !isFloatRange(scalar)) {
    std::cout << "float: impossible" << std::endl;
  } else {
    std::cout << "float: ";
    if (scalar == static_cast<int>(scalar))
      std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<float>(scalar) << "f" << std::endl;
  }

}

template <typename T>
void ScalarConverter::printDoubleRepresentation(const ScalarType type, const T &scalar) {
  if(type == kScalarTypeInvalid)
    std::cout << "double: impossible" << std::endl;
  else {
    std::cout << "double: ";
    if (scalar == static_cast<int>(scalar))
      std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<double>(scalar) << std::endl;
  }
}

template <typename T>
void ScalarConverter::printScalarRepresentations(const ScalarType type, const T scalar) {
  printCharRepresentation(type, scalar);
  printIntegerRepresentation(type, scalar);
  printFloatRepresentation(type, scalar);
  printDoubleRepresentation(type, scalar);
}

double ScalarConverter::parseToDouble(const std::string &str) {
  std::stringstream ss(str);
  double num;
  ss >> std::noskipws >> num;

  return num;
}

char ScalarConverter::stringToChar(const std::string &str) {
  return static_cast<char>(str[1]);
}

int ScalarConverter::stringToInteger(const std::string &str) {
  return static_cast<int>(parseToDouble(str));
}

float ScalarConverter::stringToFloat(const std::string &str) {
  std::string except_tail_f = str.substr(0, str.size() - 1);
  return static_cast<float>(parseToDouble(except_tail_f));
}

double ScalarConverter::stringToDouble(const std::string &str) {
  return static_cast<double>(parseToDouble(str));
}

void ScalarConverter::convert(const std::string &str) {
  if(isCharLiteral(str))
    printScalarRepresentations(kScalarTypeChar, stringToChar(str));
  else if(isValidIntegerFormat(str))
    printScalarRepresentations(kScalarTypeInt, stringToInteger(str));
  else if(isTypeFloat(str))
    printScalarRepresentations(kScalarTypeFloat, stringToFloat(str));
  else if(isValidDoubleFormat(str))
    printScalarRepresentations(kScalarTypeDouble, stringToDouble(str));
  else
    printScalarRepresentations(kScalarTypeInvalid, 0);
}
