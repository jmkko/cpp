#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {

    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_firstname (std::string x);
    void set_lastname (std::string x);
    void set_nickname (std::string x);
    void set_phonenumber (std::string x);
    void set_darkestsecret (std::string x);
    std::string get_firstname ();
    std::string get_lastname ();
    std::string get_nickname ();
    std::string get_phonenumber ();
    std::string get_darkestsecret ();
};

#endif
