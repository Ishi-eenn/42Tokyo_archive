#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

void isValidArgCount(int argc) {
  if(argc != 2)
    throw std::invalid_argument("could not open file.");
}

bool isFileType(const std::string& filename, const std::string& extension) {
  if (filename.length() >= extension.length())
    return filename.substr(filename.length() - extension.length()) == extension;
  return false;
}

bool isCsvFile(const std::string& filename) {
  const std::string csvExtension = ".csv";
  return isFileType(filename, csvExtension);
}

bool isTxtFile(const std::string& filename) {
  const std::string txtExtension = ".txt";
  return isFileType(filename, txtExtension);
}

void isValidFileHeadLine(std::ifstream &file, std::string fileHeader) {
  std::string head_line;
  std::getline(file, head_line);
  if(file.eof())
    throw std::invalid_argument("empty file");
  if(file.fail())
    throw std::invalid_argument("reading file");
  if(head_line != fileHeader)
    throw std::invalid_argument("invalid file header");
}

void isValidCsvFileHeadLine(std::ifstream &file) {
  const std::string csvfileHeader = "date,exchange_rate";
  isValidFileHeadLine(file, csvfileHeader);
}

void isValidTxtFileHeadLine(std::ifstream &file) {
  const std::string txtfileHeader = "date | value";
  isValidFileHeadLine(file, txtfileHeader);
}

void checkAndOpenFile(std::ifstream &file, std::string filename) {
  file.open(filename);
  if(!file.is_open())
    throw std::invalid_argument(filename + " not found");
}

void checkCsvAndOpenFile(std::ifstream &file) {
  const std::string filename = "assets/data.csv";

  try {
    if(!isCsvFile(filename))
      throw std::invalid_argument("invalid file extension");
    checkAndOpenFile(file, filename);
    isValidCsvFileHeadLine(file);
  } catch (std::exception &e) {
    throw std::invalid_argument("\"" + filename + "\" " + e.what());
  }
}

void checkTxtAndOpenFile(std::ifstream &file, std::string filename) {
  try {
    if(!isTxtFile(filename))
      throw std::invalid_argument("invalid file extension");
    checkAndOpenFile(file, filename);
    isValidTxtFileHeadLine(file);
  } catch (std::exception &e) {
    throw std::invalid_argument("\"" + filename + "\" " + e.what());
  }
}

double extractAmount(const std::string& line, unsigned int n) {
  if (line.size() <= n)
    throw std::invalid_argument("bad input => " + line);

  std::string amountStr = line.substr(n);
  std::stringstream ss(amountStr);
  double amount;

  if (!(ss >> amount) || !ss.eof())
    throw std::invalid_argument("bad input => " + line);

  return amount;
}

void loadExchangeRates(BitcoinExchange &bitcoin, std::ifstream &dateFile){
  std::string line;
  while (std::getline(dateFile, line)) {
    if(dateFile.fail())
      throw std::invalid_argument("reading file");

    std::string date = line.substr(0, 10);
    double amount = extractAmount(line, 11);
    bitcoin.addExchangeRate(date, amount);
  }
}

void calculateAndDisplayExchangeRates(BitcoinExchange &bitcoin, std::ifstream &dateFile){
  std::string line;
  while (std::getline(dateFile, line)) {
    if(dateFile.fail())
      throw std::invalid_argument("reading file");

    try {
      std::string date = line.substr(0, 10);
      double amount = extractAmount(line, 13);
      double rate = bitcoin.calculateExchangeRate(date, amount);
      std::cout << date << " => " << amount << " = " <<  rate << std::endl;
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}

int main(int argc, char **argv) {
  try {
    isValidArgCount(argc);

    std::ifstream inputFile, dataFile;
    checkTxtAndOpenFile(inputFile, argv[1]);
    checkCsvAndOpenFile(dataFile);

    BitcoinExchange bitcoin;
    loadExchangeRates(bitcoin, dataFile);
    calculateAndDisplayExchangeRates(bitcoin, inputFile);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
