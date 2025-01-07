#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "Creating animals..." << std::endl;

    const Animal* animals[6];

    for (int i = 0; i < 3; i++)
    {
        animals[i] = new Dog();
        animals[i + 3] = new Cat();
    }

    for (int i = 0; i < 300; ++i)
    {
        if (i % 2 == 0)
        {
            dynamic_cast<const Dog*>(animals[i % 3])->getBrain()->setIdea(i % 100, "Fetch the ball");
            dynamic_cast<const Cat*>(animals[(i % 3) + 3])->getBrain()->setIdea(i % 100, "Chase the laser pointer");
        }
        else if (i % 3 == 0)
        {
            dynamic_cast<const Dog*>(animals[i % 3])->getBrain()->setIdea(i % 100, "Eat a bone");
            dynamic_cast<const Cat*>(animals[(i % 3) + 3])->getBrain()->setIdea(i % 100, "Eat a fish");
        }
        else
        {
            dynamic_cast<const Dog*>(animals[i % 3])->getBrain()->setIdea(i % 100, "Bark loudly");
            dynamic_cast<const Cat*>(animals[(i % 3) + 3])->getBrain()->setIdea(i % 100, "Meow loudly");
        }
    }


    for (int i = 0; i < 300; i++)
    {
        std::cout << "Dog " << (i % 3) + 1 << " idea: " << (i % 100) + 1 << " " << dynamic_cast<const Dog*>(animals[i % 3])->getBrain()->getIdea(i % 100) << std::endl;
        std::cout << "Cat " << (i % 3) + 1 << " idea: " << (i % 100) + 1 << " " <<dynamic_cast<const Cat*>(animals[(i % 3) + 3])->getBrain()->getIdea(i % 100) << std::endl;
    }

    for (int i = 0; i < 2; ++i){
        std::cout << "Animal " << i+1 << " type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < 6; i++)
        delete animals[i];
    return 0;
}

