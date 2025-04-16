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

std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> jacob;
    int j0 = 0, j1 = 1;
    jacob.push_back(j1);

    while (true) {
        int next = j1 + 2 * j0;
        if (next >= n)
            break;
        jacob.push_back(next);
        j0 = j1;
        j1 = next;
    }

    return jacob;
}

template <typename Container>
void fordJohnson(Container &cont, int left, int right) {
    int size = right - left + 1;
    if (size <= 1)
        return;

    std::vector<int> A, B;

    for (int i = left; i + 1 <= right; i += 2) {
        if (cont[i] > cont[i + 1]) {
            A.push_back(cont[i]);
            B.push_back(cont[i + 1]);
        } else {
            A.push_back(cont[i + 1]);
            B.push_back(cont[i]);
        }
    }

    if ((size % 2) != 0)
        A.push_back(cont[right]);

    fordJohnson(A, 0, A.size() - 1);

    std::vector<int> jacob = generateJacobsthal(B.size());
    std::vector<int> result = A;

    std::vector<bool> inserted(B.size(), false);
    for (int i = 0; i < (int)jacob.size(); i++) {
        int idx = jacob[i];
        if (idx >= (int)B.size())
			continue;

        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), B[idx]);
        result.insert(pos, B[idx]);
        inserted[idx] = true;
    }

    for (int i = 0; i < (int)B.size(); i++) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), B[i]);
            result.insert(pos, B[i]);
        }
    }
    for (int i = 0; i < (int)result.size(); i++)
        cont[left + i] = result[i];
}


template <typename Container>
void sortContainer(Container &cont)
{
    if (cont.size() <= 1)
        return;
    fordJohnson(cont, 0, cont.size() - 1);
}

void PmergeMe::handleSort()
{
	std::cout << "vector before: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	clock_t vecStart = clock();
	sortContainer(_vector);
	clock_t vecEnd = clock();
	std::cout << std::endl <<"Time to process a range of " << _vector.size() << " elements with std::vector : " << vecStart - vecEnd << std::endl;
	std::cout << std::endl << "vector after: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

// void sortDeque(std::deque<int> &deque, int start, int end)
// {
// 	if (deque.size() <= 1)
// 		return;
// 	mergeInsertionSortDeque(deque, 0, deque.size() - 1);
// }

// void mergeInsertionSortDeque(std::deque<int> &deque, int start, int end)
// {
// 	if (start >= end)
// 		return;
// 	int mid = start + (end - start) / 2;
// 	mergeInsertionSortDeque(deque, start, mid);
// 	mergeInsertionSortDeque(deque, mid + 1, end);
// 	mergeDeque(deque, start, mid, end);
// }

// void mergeDeque(std::deque<int> &deque, int start, int mid, int end)
// {
// 	std::deque<int> left(deque.begin() + start, deque.begin() + mid + 1);
// 	std::deque<int> right(deque.begin() + mid + 1, deque.begin() + end + 1);

// 	int i = 0, j = 0, k = start;
// 	while (i < left.size() && j < right.size())
// 	{
// 		if (left[i] <= right[j])
// 			deque[k++] = left[i++];
// 		else
// 			deque[k++] = right[j++];
// 	}

// 	while (i < left.size())
// 		deque[k++] = left[i++];
	
// 	while (j < right.size())
// 		deque[k++] = right[j++];
// }

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

