#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(static_cast<unsigned>(time(NULL)));
	int i = rand() % 3;

	switch (i)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		std::cout << "Error on generate" << std::endl;
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error on identify" << std::endl;
}

void identify(Base &p)
{
	if (static_cast<void*>(&p) == static_cast<void*>(static_cast<A*>(&p)))
	std::cout << "A" << std::endl;
	else if (static_cast<void*>(&p) == static_cast<void*>(static_cast<B*>(&p)))
		std::cout << "B" << std::endl;
	else if (static_cast<void*>(&p) == static_cast<void*>(static_cast<C*>(&p)))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error on identify" << std::endl;
}