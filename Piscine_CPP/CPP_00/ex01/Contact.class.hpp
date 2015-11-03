// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/02 16:17:49 by rclanget          #+#    #+#             //
//   Updated: 2015/11/02 17:19:56 by rclanget         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact
{

public:
	
	Contact(void);
	~Contact(void);

	void add(int index);
	void all_print(void);
	void s_print(void);

private:
	
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	login;
	std::string	postal_adress;
	std::string	email;
	std::string	phone_number;
	std::string	birthday;
	std::string	fav_meal;
	std::string	underwear_color;
	std::string	darkest_secret;	
};

#endif
