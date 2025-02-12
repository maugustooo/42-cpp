#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    BitcoinExchange exchange;
    exchange.getExchangeRates("data.csv", filename);
    return 0;
}