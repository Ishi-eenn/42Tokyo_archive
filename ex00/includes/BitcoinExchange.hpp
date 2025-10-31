#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void addExchangeRate(std::string date, double rate);
    double calculateExchangeRate(std::string date, double amount);

  private:
    std::map<std::string, double, std::greater<std::string> > _exchangeRates;

  private:
    int parseToInt(const std::string &str);
    bool isLeapYear(const int year);
    bool isValidDayInFebruary(const int year, const int day);
    bool isValidYear(const int year) ;
    bool isValidMonth(const int month);
    bool isValidDay(const int year, const int month, const int day);
    bool isDateFormattedYYYYMMDD(const std::string &date);
    void isValidDateFormat(const std::string &date);
    void validateAmount(const double amount);
    void validateExchangeResult(const double rate, const double amount);
};

#endif
