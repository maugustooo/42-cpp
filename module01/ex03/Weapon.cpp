# include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

Weapon::Weapon(std::string type){
    _type = type;
}

void Weapon::setType(std::string type){
    _type = type;
}

const std::string &Weapon::getType(){
    return _type;
}
