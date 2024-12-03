#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        //orthodox canonical form:
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(Brain const &rSym);
        ~Brain();
        //methods:
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);
    private:
        std::string _ideas[100];
};

#endif