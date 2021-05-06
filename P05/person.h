#ifndef __PERSON_H
#def __PERSON_H

#include <iostream>

class Person {
  public:
    Person (std::string name, std::string email);
    std::string to_string() const;
    virtual std::string full_info() const;  
    friend std::ostream& operator<< (std::ostream& ost, const Person& person);
  protected:
    std::string _name;
    sid::string _email;
}

#endif
