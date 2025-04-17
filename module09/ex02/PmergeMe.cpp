#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_error = false;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
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
}
template <typename container>
void binaryInsert(container &cont, int value, size_t start, size_t end) 
{
    if (start >= end) 
    {
        cont.insert(cont.begin() + start, value);
        return;
    }
    
    size_t left = start;
    size_t right = end;
    
    while (left < right) 
    {
        size_t mid = left + (right - left) / 2;
        if (cont[mid] < value) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid;
        }
    }
    cont.insert(cont.begin() + left, value);
}

template <typename container>
container generateJacobsthal(size_t n)
{
    container jacob;
    size_t j0 = 0, j1 = 1;
	jacob.push_back(j0);
    jacob.push_back(j1);

    while (true)
	{
        size_t next = j1 + 2 * j0;
        if (next >= n)
            break;
        jacob.push_back(next);
        j0 = j1;
        j1 = next;
    }

    return jacob;
}

template <typename container>
container generateInsertionOrder(int n)
{
    container result;
    
    if (n <= 1)
    {
        if (n == 1)
            result.push_back(0);
        return result;
    }
    
    container jacobNumbers = generateJacobsthal<container>(n);
    
    result.push_back(0);
    
    for (size_t i = 2; i < jacobNumbers.size(); ++i)
    {
        for (int j = jacobNumbers[i]; j > jacobNumbers[i-1]; --j)
        {
            if (j-1 < n)
                result.push_back(j-1);
        }
    }
    std::vector<bool> used(n, false);
    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i] < n)
            used[result[i]] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        if (!used[i])
            result.push_back(i);
    }
    
    return result;
}

template <typename container>
void fordJohnson(container &cont, size_t left, size_t right)
{
    size_t size = right - left + 1;
    if (size <= 1)
        return;

    container A, B;

    for (size_t i = left; i + 1 <= right; i += 2)
	{
        if (cont[i] > cont[i + 1])
		{
            A.push_back(cont[i]);
            B.push_back(cont[i + 1]);
        } 
		else
		{
            A.push_back(cont[i + 1]);
            B.push_back(cont[i]);
        }
    }

    if ((size % 2) != 0)
        A.push_back(cont[right]);

    fordJohnson(A, 0, A.size() - 1);

    container order = generateInsertionOrder<container>(B.size());
    container result = A;
	container inserted(B.size(), false);
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		if (idx >= (size_t)B.size())
			continue;
	
		binaryInsert(result, B[idx], 0, result.size());
		inserted[idx] = true;
	}
	for (size_t i = 0; i < result.size(); ++i)
		cont[left + i] = result[i];
}


template <typename container>
void sortContainer(container &cont)
{
    if (cont.size() <= 1){
    	return;
	}
	mergeInsertionSort(cont, 0, cont.size() - 1);
}

void PmergeMe::handleSort()
{
	//Vector
	std::cout << "before:   ";
	for (size_t i = 0; i < (size_t)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	clock_t vecStart = clock();
	sortContainer(_vector);
	clock_t vecEnd = clock();
	std::cout << std::endl << "after:   ";
	for (size_t i = 0; i < (size_t)_vector.size(); i++)
		std::cout << _vector[i] << " ";
	double duration = 1000.0 * (vecEnd - vecStart) / CLOCKS_PER_SEC;
	std::cout << std::endl <<"Time to process a range of " << _vector.size() << " elements with std::vector : " << duration << std::endl;
	clock_t deqStart = clock();
	sortContainer(_deque);
	clock_t deqEnd = clock();
	duration = 1000.0 * (deqEnd - deqStart) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << duration << std::endl;
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

