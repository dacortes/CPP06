/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:46:38 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 10:17:57 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include <cstdlib>
# include <string>
# include <iostream>
# include <cerrno>
# include <stdint.h>

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"                 //end
# define R "\033[1m\033[1;31m"      //red
# define G "\033[1m\033[1;32m"      //green
# define Y "\033[1m\033[1;33m"      //yellow
# define B "\033[1;34m"             //blue
# define T "\033[1m\033[1;35m"      //Turquesa
# define C "\033[1;36m"             //Cyan
# define O "\033[1m\033[38;5;208m"  //orange
# define F "\033[1m\033[38;5;128m"  //purple

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

typedef struct s_Data
{
	std::string firstName;
	std::string lastName;
	int		age;
} Data;

class Serializer
{
	private:
		
		/*
		* Orthodox Canonical Form
		*/
		Serializer(void);
		Serializer(const Serializer& obj);
		Serializer &operator=(const Serializer& obj);
	public:
		~Serializer(void);
		/*
		* Funtions
		*/
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
