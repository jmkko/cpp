#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {
    Contact contact_list[8];
    int index;

public:
    PhoneBook();
    int get_index();
    void add();
    void search();
    void exit();
    void print_col(std::string str);
    bool is_index(std::string str);
};

#endif
