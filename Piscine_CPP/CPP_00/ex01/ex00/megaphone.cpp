/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:09:59 by harar             #+#    #+#             */
/*   Updated: 2015/11/02 15:22:41 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	convert(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		s[i] = std::toupper(s[i]);
	}
}

int main (int argc, char **argv){

	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{	
			std::string p = argv[i];
			convert(p);
			std::cout << p;
		}
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << std::endl;
	return 0;
}