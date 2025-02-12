#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _rates;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();
        void getExchangeRates(std::string filename, std::string inputfile);
        void convert(std::string currency, double value);
        void getValues(std::string inputfile);
};