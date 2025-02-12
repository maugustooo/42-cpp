#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    std::cout << "BitcoinExchange Copy constructor called" << std::endl;
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    std::cout << "BitcoinExchange Assignation operator called" << std::endl;
    if (this != &src)
    {
        this->_rates = src._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange Destructor called" << std::endl;
}

void BitcoinExchange::convert(std::string date, double value)
{
    std::map<std::string, double>::iterator it;
    it = _rates.find(date);
    double result;
    if (it != _rates.end())
    {
        result = value * it->second;
        std::cout << date << " =>> " << value << "=" << result << std::endl;
    }
    else
    {
        it = _rates.lower_bound(date);
        if(it != _rates.begin())
        {
            --it;
            result = value * it->second;
            std::cout << date << "=>>" << value << " = " << result << std::endl;
        }
        else
        {
            std::cerr << "Error: No exchange rate found for date " << date << std::endl;
        }
    }
}

void BitcoinExchange::getValues(std::string inputfile)
{
    std::ifstream file(inputfile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string valuestr;
        if (!std::getline(iss, date, '|') || !std::getline(iss, valuestr))
        {
            std::cerr << "Error: could not parse line: " << line << std::endl;
            continue;
        }
        date.erase(date.find_last_not_of(" \n\r\t") + 1);
		valuestr.erase(0, valuestr.find_first_not_of(" \n\r\t"));
        double value;
        std::istringstream viss(valuestr);
        if (!(viss >> value) || (value < 0 || value > 1000))
        {
            std::cerr << "Error: invalid value: " << valuestr << std::endl;
            continue;
        }
        convert(date, value);
    }
}

void BitcoinExchange::getExchangeRates(std::string filename, std::string inputfile)
{
    std::ifstream file(filename.c_str());   
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, ratestr;
        if (!std::getline(iss, date, ',') || !std::getline(iss, ratestr, ','))
        {
            std::cerr << "Error: could not parse line: " << line << std::endl;
            continue;
        }
        double rate;
        std::istringstream riss(ratestr);
        if (!(riss >> rate))
        {
            std::cerr << "Error: invalid rate: " << ratestr << std::endl;
            continue;
        }
        this->_rates[date] = rate;
    }
    getValues(inputfile);
}
