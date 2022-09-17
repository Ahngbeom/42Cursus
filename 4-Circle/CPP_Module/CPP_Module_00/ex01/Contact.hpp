/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:07:19 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 01:16:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define DISPLAY_MAX_WIDTH	11

enum	field_index
{
	Index,
	FirstName,
	LastName,
	Nickname,
	PhoneNumber,
	DarkestSecret
};

class	Contact
{
	private:
		static	std::string	field[6];
		std::size_t			id;
		std::string			informations[5];
		
	public:
		Contact();
		~Contact();
		std::string	display_input_field(std::size_t index);
		void		display_field();
		void		display_borderLine();
		void		set_id(std::size_t index);
		void		set_info(std::size_t index, std::string info);
		std::size_t	get_id();
		void		get_info();
		std::string	get_info(std::size_t index);
};

#endif