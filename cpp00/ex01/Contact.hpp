#include <string>

class Contact {

    std::string first_mane;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_firstname (std::string x); 
    void set_lastname (std::string x); 
    void set_nickname (std::string x); 
    void set_phonenumber (std::string x); 
    void set_darkestsecret (std::string x); 
};
