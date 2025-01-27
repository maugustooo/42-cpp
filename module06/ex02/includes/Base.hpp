#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);