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

void merge(std::vector<int> &vector, int left, int mid, int right)
{
	std::vector<int> leftVector(vector.begin() + left, vector.begin() + mid + 1);
	std::vector<int> rightVector(vector.begin() + mid + 1, vector.begin() + right + 1);

	int i = 0, j = 0, k = left;
	while (i < leftVector.size() && j < rightVector.size())
	{
		if (leftVector[i] <= rightVector[j])
			vector[k++] = leftVector[i++];
		else
			vector[k++] = rightVector[j++];
	}
	while (i < leftVector.size())
		vector[k++] = leftVector[i++];
	while (j < rightVector.size())
		vector[k++] = rightVector[j++];
}

void mergeInsertionSort(std::vector<int> &vector, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeInsertionSort(vector, left, mid);
	mergeInsertionSort(vector, mid + 1, right);
	merge(vector, left, mid, right);
}

void sortVector(std::vector<int> &vector)
{
	if (vector.empty())
		return;
	mergeInsertionSort(vector, 0, vector.size() - 1);
}

void sortDeque(std::deque<int> &deque)
{
	if (deque.empty())
		return;
	;
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

