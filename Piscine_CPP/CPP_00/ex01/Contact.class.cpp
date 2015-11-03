/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 11:53:16 by harar             #+#    #+#             */
/*   Updated: 2015/11/03 11:57:39 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::add(int index)
{
	this->index = index;
	std::cout << "First name: ";
	std::getline (std::cin, this->first_name);
	std::cout << "Last name: ";
	std::getline (std::cin, this->last_name);
	std::cout << "Nickname: ";
	std::getline (std::cin, this->nickname);
	std::cout << "Login: ";
	std::getline (std::cin, this->login);
	std::cout << "Postal adress: ";
	std::getline (std::cin, this->postal_adress);
	std::cout << "Email: ";
	std::getline (std::cin, this->email);
	std::cout << "Phone number: ";
	std::getline (std::cin, this->phone_number);
	std::cout << "Birthday: ";
	std::getline (std::cin, this->birthday);
	std::cout << "Favorite meal: ";
	std::getline (std::cin, this->fav_meal);
	std::cout << "Underwear color: ";
	std::getline (std::cin,this->underwear_color);
	std::cout << "Darkest secret: ";
	std::getline (std::cin, this->darkest_secret);
}

void print_space(std::string str)
{
	int len;

	len = str.length();
	if (len > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		while (len++ < 10)
			std::cout << " ";
		std::cout << str;
	}
	return ;
}

void Contact::s_print(void)
{
	std::cout << "         " << this->index << "|";
	print_space(this->first_name);
	std::cout << "|";
	print_space(this->last_name);
	std::cout << "|";
	print_space(this->nickname);
	std::cout << "|" << std::endl;
	return ;
}

void Contact::all_print(void)
{
	std::cout << "first_name:      " << this->first_name << std::endl;
	std::cout << "last_name:       " << this->last_name << std::endl;
	std::cout << "nickname:        " << this->nickname << std::endl;
	std::cout << "login:           " << this->login << std::endl;
	std::cout << "postal_adress:   " << this->postal_adress << std::endl;
	std::cout << "email:           " << this->email << std::endl;
	std::cout << "phone_number:    " << this->phone_number << std::endl;
	std::cout << "birthday:        " << this->birthday << std::endl;
	std::cout << "fav_meal:        " << this->fav_meal << std::endl;
	std::cout << "underwear_color: " << this->underwear_color << std::endl;
	std::cout << "darkest_secret:  " << this->darkest_secret << std::endl;
	return ;
}
