/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 11:53:16 by harar             #+#    #+#             */
/*   Updated: 2015/11/03 11:58:56 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"



void go_search(Contact instance[8], int max)
{
	std::string index;
	int i;

	i = 0;
	std::cout << "     index|first name|last name |  nickname|" << std::endl;
	if (!max)
		std::cout << "No entry" << std::endl;
	else
	{
		while (i < max)
			instance[i++].s_print();
		std::cout << "Index: ";
		std::getline(std::cin, index);
		if (std::cin.eof() == 1)
			return ;
		else if (!index.length())
			std::cout << "Error, no entry" << std::endl;
		else if ((index.length() == 1) && ((((index.c_str())[0] - '0') >= 0) && (((index.c_str())[0] - '0') < 8)))
		{
			if (((index.c_str())[0] - '0') >= max)
				std::cout << "Error, no entry for this id" << std::endl;
			else
				instance[(index.c_str()[0] - '0')].all_print();
		}
		else
		{
			if (((index.c_str())[0] - '0') >= max)
				std::cout << "Error, no entry for this id" << std::endl;
		}
	}
	return ;
}

int main(void)
{
	std::string buf;
	Contact instance[8];
	int index;

	index = 0;
	while (1)
	{
		std::cout << "Command: ";
		std::getline (std::cin, buf);
		if ((!buf.compare("ADD") || !buf.compare("add")) && (std::cin.eof() != 1))
		{
			if (index == 8)
				std::cout << "Phonebook is full" << std::endl;
			else
			{
				instance[index].add(index);
				index++;
			}
		}
		else if (!buf.compare("SEARCH") || !buf.compare("search"))
			go_search(instance, index);
		else if (!buf.compare("EXIT") || !buf.compare("exit") || std::cin.eof() == 1)
			break ;
		else
			std::cout << std::endl;
	}
	return (0);
}
