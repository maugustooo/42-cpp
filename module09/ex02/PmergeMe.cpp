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

template <typename Container>
void insertionSort(Container &cont, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = cont[i];
        int j = i - 1;
        while (j >= left && cont[j] > key)
        {
            cont[j + 1] = cont[j];
            j--;
        }
        cont[j + 1] = key;
    }
}

template <typename Container>
void merge(Container &cont, int left, int mid, int right)
{
    Container leftCont(cont.begin() + left, cont.begin() + mid + 1);
    Container rightCont(cont.begin() + mid + 1, cont.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)leftCont.size() && j < (int)rightCont.size())
    {
        if (leftCont[i] <= rightCont[j])
            cont[k++] = leftCont[i++];
        else
            cont[k++] = rightCont[j++];
    }
    while (i < (int)leftCont.size())
        cont[k++] = leftCont[i++];
    while (j < (int)rightCont.size())
        cont[k++] = rightCont[j++];
}

template <typename Container>
void mergeInsertionSort(Container &cont, int left, int right)
{
    if (right - left + 1 <= 5)
    {
        insertionSort(cont, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    mergeInsertionSort(cont, left, mid);
    mergeInsertionSort(cont, mid + 1, right);
    merge(cont, left, mid, right);
}

template <typename Container>
void sortContainer(Container &cont)
{
    if (cont.size() <= 1){
    	return;
	}
	mergeInsertionSort(cont, 0, cont.size() - 1);
}

void PmergeMe::handleSort()
{
	std::cout << "vector before: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	clock_t vecStart = clock();
	sortContainer(_vector);
	clock_t vecEnd = clock();
	std::cout << std::endl << "vector after: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl << "vector time: " << (double)(vecEnd - vecStart) / CLOCKS_PER_SEC << std::endl;
	std::cout << std::endl << "deque before: ";
	for (int i = 0; i < (int)_deque.size(); i++)
		std::cout << _deque[i] << " ";
	clock_t dequeStart = clock();
	sortContainer(_deque);
	clock_t dequeEnd = clock();
	std::cout << std::endl << "deque after: ";
	for (int i = 0; i < (int)_deque.size(); i++)
		std::cout << _deque[i] << " ";	
	std::cout << std::endl << "deque time: " << (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC << std::endl;
}

bool isNumber(const std::string &string)
{
	if (string.empty())
		return false;
	for (int i = 0; i < (int)string.size(); i++)
	{
		if (!std::isdigit(string[i]))
			return false;
	}
	return true;
}

void PmergeMe::start(int argc, char **argv)
{
	for (int i = 0; i < argc -1; i++)
	{	
		std::stringstream ss(argv[i + 1]);
		std::string token;
		while (ss >> token)
		{
			if (!isNumber(token))
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

