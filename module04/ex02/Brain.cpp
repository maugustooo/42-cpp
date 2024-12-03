# include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src){
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain &Brain::operator=(Brain const &src){
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = src._ideas[i];
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const{
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string &idea){
    _ideas[index] = idea;
}