#include "Contact.hpp"

class PhoneBook {
    Contact contact_list[8];
    int num_contact;

public:
    PhoneBook(int);
    void add();
    void search();
    void exit();
};
