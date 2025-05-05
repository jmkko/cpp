#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(int x) : num_contact(x) {}

void PhoneBook::add(){
    if(num_contact < 8)
    {
        std::string mystr;
        std::cout << "Adding a new contact:" << std::endl;
        std::cout << "Firstname:";
        getline (std::cin, mystr);
        contact_list[num_contact].set_firstname(mystr);
        std::cout << "Lastname:";
        getline (std::cin, mystr);
        contact_list[num_contact].set_lastname(mystr);
        std::cout << "Nickname:";
        getline (std::cin, mystr);
        contact_list[num_contact].set_nickname(mystr);
        std::cout << "Phone number:";
        getline (std::cin, mystr);
        contact_list[num_contact].set_phonenumber(mystr);
        std::cout << "Darkest secret:";
        getline (std::cin, mystr);
        contact_list[num_contact].set_darkestsecret(mystr);
        num_contact++;
    }
}
