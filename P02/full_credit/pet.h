#ifndef __PET_H
#define __PET_H
#include <iostream>
#include <vector>

enum Type {DOG, CAT, RABBIT, HAMSTER};
std::string to_string (Type type);

class Pet {
    private:
        std::string name;
        double age;
        Type type;
    public:
        Pet (std::string name, double age, Type typeOfAnimal);
        std::string to_string();
    
};



#endif
