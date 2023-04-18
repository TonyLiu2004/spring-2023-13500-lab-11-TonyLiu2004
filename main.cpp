#include <iostream>
#include "profile.h"

int main() {
    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << "\n"; 
    std::cout << p1.getFullName() << "\n"; 

    p1.setDisplayName("Marco Rossi");
    std::cout << p1.getUsername() << "\n"; 
    std::cout << p1.getFullName() << "\n"; 

    Profile p2("tarma1", "Tarma Roving");
    std::cout << p2.getUsername() << "\n"; 
    std::cout << p2.getFullName() << "\n"; 
}