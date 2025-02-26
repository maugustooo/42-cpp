#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called" << std::endl;
	_error = false;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "PmergeMe assignation operator called" << std::endl;
	if (this != &copy)
	{
		_deque = copy._deque;
		_vector = copy._vector;
		_error = copy._error;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

void sortVector(std::vector<int> &vector)
{
	if (vector.empty() || vector.size() <= 1)
		return;
	int mid = vector.size() / 2;
	std::vector<int> leftvector(vector.begin(), vector.begin() + mid);
	std::vector<int> rightvector(vector.begin() + mid, vector.end());
	sortVector(leftvector);
	sortVector(rightvector);
	std::merge(leftvector.begin(), leftvector.end(), rightvector.begin(), rightvector.end(), vector.begin());
}

void sortDeque(std::deque<int> &deque)
{
	if (deque.empty() || deque.size() <= 1)
		return;
	int mid = deque.size() / 2;
	std::deque<int> leftdeque(deque.begin(), deque.begin() + mid);
	std::deque<int> rightdeque(deque.begin() + mid, deque.end());
	sortDeque(leftdeque);
	sortDeque(rightdeque);
	std::merge(leftdeque.begin(), leftdeque.end(), rightdeque.begin(), rightdeque.end(), deque.begin());
}

void PmergeMe::handleSort()
{
	sortVector(_vector);
	sortDeque(_deque);
}

bool isNumber(const std::string &string)
{
	if (string.empty())
		return false;
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
			return false;
	}
	return true;
}

void PmergeMe::start(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{	
		std::stringstream ss(argv[1]);
		std::string token;
		while (ss >> token)
		{
			if (isNumber(token))
				_deque.push_back(std::atoi(token.c_str()));
			else
			{
				_error = true;
				throw InvalidArgsexception();
				break;
			}
			int num;
			std::stringstream sst(token);
			sst >> num;
			if (sst.fail() || num < 0)
			{
				_error = true;
				throw InvalidArgsexception();
				break;
			}
			else
			{
				_vector.push_back(num);
				_deque.push_back(num);
			}

		}
	}
	handleSort();
}

