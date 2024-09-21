#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
#include <string>

class ScalarConverter {
   private:
    typedef enum {
      kScalarTypeInvalid = 0,
      kScalarTypeChar,
      kScalarTypeInt,
      kScalarTypeFloat,
      kScalarTypeDouble
    } ScalarType;

    ScalarConverter();
    ScalarConverter(const ScalarConverter &scalarConverter);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);

    static bool isCharLiteral(const std::string &str);
    static bool isValidIntegerFormat(const std::string &str);
    static bool isIntegerRangeForFloat(const float &num);
    static bool isTypeFloat(const std::string &str);
    static bool isValidDoubleFormat(const std::string &str);
    static bool isIntegerString(const std::string &str);
    static bool isDoubleString(const std::string &str);

    template <typename T>
    static bool isValidRange(const double &num);
    template <typename T>
    static bool isCharRange(const ScalarType type, const T &scalar);
    template <typename T>
    static bool isIntegerRange(const ScalarType type, const T &scalar);
    template <typename T>
    static bool isFloatRange(const T &num);
    template <typename T>
    static bool isRepresentableAs(const double &num);
    template <typename T>
    static bool isInfinityOrNan(const T &num);

    template <typename T>
    static void printScalarRepresentations(const ScalarType type, const T scalar);
    template <typename T>
    static void printCharRepresentation(const ScalarType type, const T &num);
    template <typename T>
    static void printIntegerRepresentation(const ScalarType type, const T &num);
    template <typename T>
    static void printFloatRepresentation(const ScalarType type, const T &num);
    template <typename T>
    static void printDoubleRepresentation(const ScalarType type, const T &num);

    static double parseToDouble(const std::string &str);
    static char stringToChar(const std::string &str);
    static int stringToInteger(const std::string &str);
    static float stringToFloat(const std::string &str);
    static double stringToDouble(const std::string &str);

  public:
    static void convert(const std::string &str);
};

#endif
