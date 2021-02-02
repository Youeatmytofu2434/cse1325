#include "pet.h"

int main () {
    Pet dog {"Celestia", 15, DOG};
    Pet cat {"Bella", 8, CAT};
    Pet rabbit {"Max", 2, RABBIT};
    Pet hamster {"Coco", 1, HAMSTER};
    
    std::vector <Pet> list = {dog, cat, rabbit, hamster};
    for (int i = 0; i < 4; i++){
        std::cout << list[i].to_string() << std::endl;
    }
    
    
}
