#include <iostream>
#include <vector>
#include "pet.h"

std::string to_string (Type type){
    std::vector <std::string> v = {"dog", "cat", "rabbit", "hamster"};
    return v[type];
}

Pet::Pet (std::string PetName, double PetAge, Type PetType): name {PetName}, age {PetAge}, type {PetType}{
    if (PetType < DOG || PetType > HAMSTER) std::cerr << "Invalid animal" << std::endl;

}

std::string Pet::to_string() {
    return name + " is a " 
           + ::to_string (type) + " age "
           + std::to_string (age);
}

