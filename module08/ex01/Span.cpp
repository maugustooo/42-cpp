#include "Span.hpp"

Span::Span(unsigned int n) : _nbr(n)
{
	std::cout << "Constuctor called" << std::endl;
}

Span::Span(Span const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	_nbr = other._nbr;
	_vector = other._vector;
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int number)
{
	if (_vector.size() >= _nbr)
		throw FullSpanException();
	_vector.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > _nbr)
		throw FullSpanException();
	_vector.insert(_vector.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_vector.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _vector;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_vector.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _vector;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}
