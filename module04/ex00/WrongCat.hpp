#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        //orthodox canonical form:
		WrongCat();
		WrongCat(const WrongCat &wrongCat);
		WrongCat &operator=(WrongCat const &rSym);
		~WrongCat();
		//methods:
		void makeSound() const;
};

#endif