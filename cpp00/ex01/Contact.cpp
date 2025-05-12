#include "Contact.hpp"

void Contact::set_firstname (std::string x){
    first_name = x;
} 

void Contact::set_lastname (std::string x){
    last_name = x;
} 

void Contact::set_nickname (std::string x){
    nick_name = x;
} 

void Contact::set_phonenumber (std::string x){
    phone_number = x;
} 

void Contact::set_darkestsecret (std::string x){
    darkest_secret = x;
} 

std::string Contact::get_firstname(){
    return first_name;
}

std::string Contact::get_lastname(){
    return last_name;
}

std::string Contact::get_nickname(){
    return nick_name;
}
std::string Contact::get_phonenumber(){
    return phone_number;
}
std::string Contact::get_darkestsecret(){
    return darkest_secret;
}
