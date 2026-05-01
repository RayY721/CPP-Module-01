#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{

}

void HumanB::attack(void) const
{
    if (this->weapon == NULL)
        std::cout << name << " attacks with their bare hands" << std::endl;
    else
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}