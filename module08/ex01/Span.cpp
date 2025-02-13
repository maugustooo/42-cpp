#include "Span.hpp"

Span::Span(unsigned int n) : _vectorbr(n)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	_vectorbr = other._vectorbr;
	_vector = other._vector;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_vector.size() >= _vectorbr)
		throw FullSpanException();
	_vector.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > _vectorbr)
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
