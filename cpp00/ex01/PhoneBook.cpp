/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:12:46 by jhervoch          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:09 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

PhoneBook::PhoneBook() : index(0) {}

int PhoneBook::get_index(){
    return index;
}

void PhoneBook::add(){
    if(index < 2)
    {
        std::string mystr;
        Contact new_contact;

        std::cout << "Adding a new contact:" << std::endl;
        std::cout << "Firstname:";
        getline (std::cin, mystr);
        new_contact.set_firstname(mystr);
        std::cout << "Lastname:";
        getline (std::cin, mystr);
        new_contact.set_lastname(mystr);
        std::cout << "Nickname:";
        getline (std::cin, mystr);
        new_contact.set_nickname(mystr);
        std::cout << "Phone number:";
        getline (std::cin, mystr);
        new_contact.set_phonenumber(mystr);
        std::cout << "Darkest secret:";
        getline (std::cin, mystr);
        new_contact.set_darkestsecret(mystr);
        contact_list[index] = new_contact;
        index++;
    }else{
        std::cout << "You have reached the maximum number of contact in the PhoneBook" << std::endl;
    }
}

void PhoneBook::print_col(std::string str){
    if (str.size()>10)
    {
        str.resize(10);
        str[9] = '.';
    }
    std::cout << std::setw(10) << str << "|";
}

void PhoneBook::search(){
    std::ostringstream  str1;
    std::string         str_index;
    int                 int_index;

    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < index; ++i)
    {
        str1.str("");
        str1.clear();
        str1 << i;
        str_index = str1.str();
        print_col(str_index);
        print_col(contact_list[i].get_firstname());
        print_col(contact_list[i].get_lastname());
        print_col(contact_list[i].get_nickname());
        std::cout << std::endl;
    }
    std::cout << "Waiting index : ";
    std::getline(std::cin, str_index);
    std::istringstream(str_index) >> int_index;
    if (is_index(str_index) && int_index >= 0 && int_index < 10)
    {
        std::cout << contact_list[int_index].get_firstname() << std::endl;
        std::cout << contact_list[int_index].get_lastname() << std::endl;
        std::cout << contact_list[int_index].get_nickname() << std::endl;
        std::cout << contact_list[int_index].get_phonenumber() << std::endl;
        std::cout << contact_list[int_index].get_darkestsecret() << std::endl;
    }else{
        std::cout << "Wrong index" << std::endl;
    }
}

bool PhoneBook::is_index(std::string str){
    bool is_number = true;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it){
        if (!isdigit(str[*it])){
            is_number = false;
            break;
        }
    }
    return is_number;
}
