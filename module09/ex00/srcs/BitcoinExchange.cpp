#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  _exchangeRates = other._exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    _exchangeRates = other._exchangeRates;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::parseToInt(const std::string &str) {
  std::stringstream ss(str);
  double num;
  ss >> std::noskipws >> num;
  if (ss.fail() || !ss.eof())
    throw std::invalid_argument("invalid date format");

  return static_cast<int>(num);
}

bool BitcoinExchange::isLeapYear(const int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool BitcoinExchange::isValidDayInFebruary(const int year, const int day) {
  if(isLeapYear(year))
    return day <= 29;
  return day <= 28;
}

bool BitcoinExchange::isValidYear(const int year) {
  return 0 <= year && year <= 9999;
}

bool BitcoinExchange::isValidMonth(const int month) {
  return 1 <= month && month <= 12;
}

bool BitcoinExchange::isValidDay(const int year, const int month, const int day) {
  if(day < 1)
    return false;
  if(month == 2)
    return isValidDayInFebruary(year, day);
  if(month == 4 || month == 6 || month == 9 || month == 11)
    return day <= 30;
  return day <= 31;
}

bool BitcoinExchange::isDateFormattedYYYYMMDD(const std::string &date) {
  if(date.length() != 10)
    return false;
  for(int i = 0; i < 10; i++) {
    if(i == 4 || i == 7) {
      if(date[i] != '-')
        return false;
    } else {
      if(!isdigit(date[i]))
        return false;
    }
  }
  return true;
}

void BitcoinExchange::isValidDateFormat(const std::string &date) {
  if (!isDateFormattedYYYYMMDD(date))
    throw std::logic_error("invalid date format");
  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);
}


void BitcoinExchange::addExchangeRate(std::string date, double rate) {
  isValidDateFormat(date);
  if(_exchangeRates.find(date) != _exchangeRates.end())
    throw std::invalid_argument("date already exists");
  _exchangeRates[date] = rate;
}

void BitcoinExchange::validateAmount(const double amount) {
  if(amount < 0)
    throw std::invalid_argument("not a positive number.");
  else if(1000 < amount)
    throw std::invalid_argument("too large a number.");
}

void BitcoinExchange::validateExchangeResult(const double rate, const double amount) {
  if (rate < 0 && rate < -std::numeric_limits<double>::max() / amount)
    throw std::overflow_error("overflow exchange");
  else if (rate > 0 && rate > std::numeric_limits<double>::max() / amount)
    throw std::overflow_error("overflow exchange");
}

double BitcoinExchange::calculateExchangeRate(std::string date, double amount) {
  isValidDateFormat(date);
  validateAmount(amount);

  std::map<std::string, double, std::greater<std::string> >::iterator it = _exchangeRates.lower_bound(date);
  if(it == _exchangeRates.end())
    throw std::invalid_argument("no exchange rate available for this date");

  validateExchangeResult(it->second, amount);

  return amount * it->second;
}
