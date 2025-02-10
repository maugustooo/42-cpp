#include "Span.hpp"

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	_N = other._N;
	_v = other._v;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_v.size() >= _N)
		throw FullSpanException();
	_v.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _N)
		throw FullSpanException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
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
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}
