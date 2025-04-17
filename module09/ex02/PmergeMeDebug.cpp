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

#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>

template <typename container>
container generateJacobsthal(int n)
{
    container jacob;
    int j0 = 0, j1 = 1, next = 0;

    jacob.push_back(j1);

    std::cout << "[DEBUG] Jacobsthal sequence:\n";

    while (true)
    {
        next = j1 + 2 * j0;
        if (next >= n)
            break;
        jacob.push_back(next);
        j0 = j1;
        j1 = next;
        std::cout << "j0: " << j0 << " j1: " << j1 << " next: " << next << "\n";
    }

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        std::cout << jacob[i] << " ";
    }
    std::cout << " END of jacobsthal\n\n";
    return jacob;
}

template <typename container>
void fordJohnson(container &cont, int left, int right)
{
    int size = right - left + 1;
    if (size <= 1)
        return;

    std::cout << "\n[DEBUG] fordJohnson called on: ";
    for (int i = left; i <= right; ++i)
        std::cout << cont[i] << " ";
    std::cout << "\n";

   container A;
   container B;

    int i;
    for (i = left; i + 1 <= right; i += 2) {
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

    std::cout << "  pair splited:\n";
    std::cout << "    A (maiores): ";
    for (i = 0; i < (int)A.size(); ++i)
        std::cout << A[i] << " ";
    std::cout << "\n    B (menores): ";
    for (i = 0; i < (int)B.size(); ++i)
        std::cout << B[i] << " ";
    std::cout << "\n";

    fordJohnson(A, 0, A.size() - 1);

    std::cout << "  A sorted:\n    ";
    for (i = 0; i < (int)A.size(); ++i)
        std::cout << A[i] << " ";
    std::cout << "\n";

	// container jacob = generateJacobsthal<container>(B.size());
	container result = A;
	container inserted(B.size(), false);

    std::cout << "  inserting B using Jacobsthal:\n";
    // for (i = 0; i < (int)jacob.size(); i++)
	// {
	// 	int idx = 0;
	// 	if (jacob[i + 1])
    //     	idx = jacob[i + 1];
    //     if (idx >= (int)B.size())
	// 		continue;

    //     typename container::iterator pos = std::upper_bound(result.begin(), result.end(), B[idx]);
    //     std::cout << "    inserting B[" << idx << "] = " << B[idx] << " in position ";
    //     std::cout << (pos - result.begin()) << "\n";

    //     result.insert(pos, B[idx]);
    //     inserted[idx] = true;
    // }

    std::cout << "  inserting last elements of B:\n";
    for (i = 0; i < (int)B.size(); i++) {
        if (!inserted[i]) {
            typename container::iterator pos = std::upper_bound(result.begin(), result.end(), B[i]);
            std::cout << "    inserting B[" << i << "] = " << B[i] << " in position ";
            std::cout << (pos - result.begin()) << "\n";
            result.insert(pos, B[i]);
        }
    }

    std::cout << "  final result (result):\n    ";
    for (i = 0; i < (int)result.size(); ++i)
        std::cout << result[i] << " ";
    std::cout << "\n";

    for (i = 0; i < (int)result.size(); i++)
        cont[left + i] = result[i];
}



template <typename container>
void sortcontainer(container &cont)
{
    if (cont.size() <= 1)
        return;
    fordJohnson(cont, 0, cont.size() - 1);
}

void PmergeMe::handleSort()
{
	//Vector
	std::cout << "vector before: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	clock_t vecStart = clock();
	sortcontainer(_vector);
	clock_t vecEnd = clock();
	std::cout << std::endl <<"Time to process a range of " << _vector.size() << " elements with std::vector : " << vecStart - vecEnd << std::endl;
	std::cout << std::endl << "vector after: ";
	for (int i = 0; i < (int)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	//Deque
	std::cout << "deque before: ";
	for (int i = 0; i < (int)_deque.size(); i++)
		std::cout << _deque[i] << " ";
	clock_t deqStart = clock();
	sortcontainer(_deque);
	clock_t deqEnd = clock();
	std::cout << std::endl <<"Time to process a range of " << _deque.size() << " elements with std::deque : " << deqStart - deqEnd << std::endl;
	std::cout << std::endl << "deque after: ";
	for (int i = 0; i < (int)_deque.size(); i++)
		std::cout << _deque[i] << " ";
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

