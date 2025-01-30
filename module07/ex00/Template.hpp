#pragma once
#include <iostream>
#include <string>

template <typename s>

void swap(s &a, s &b)
{
	s tmp = a;
	a = b;
	b = tmp;
}

template <typename mi>

mi min(const mi a, const mi b)
{
	return (a < b ? a : b);
}

template <typename ma>

ma max(const ma a, const ma b)
{
	return (a > b ? a : b);
}
