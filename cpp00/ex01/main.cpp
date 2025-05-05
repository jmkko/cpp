#include "PhoneBook.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string str;
    PhoneBook my_phonebook(0);
    
    do{
        std::cout << "Waiting instruction :";
        std::getline(std::cin, str);
        if (str == "add")
            my_phonebook.add();
    }while (str == "exit");
}
