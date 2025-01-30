#include "iter.hpp"

void ft_toUpper(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

void ft_toLower(char &c)
{
    c = std::tolower(static_cast<unsigned char>(c));
}

void increment(int &n) {
    n++;
}

int main(void)
{
	char arr[] = {'a', 'b', 'c'};
	int arr2[] = {1, 2, 3};

	::iter(arr, 3, ft_toUpper);
    std::cout << "Upper" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
	::iter(arr, 3, ft_toLower);
    std::cout << "Lower" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
	 std::cout << "before increment" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr2[i] << std::endl;
	}
	::iter(arr2, 3, increment);
    std::cout << "after increment" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr2[i] << std::endl;
	}
	std::cout << std::endl;
}