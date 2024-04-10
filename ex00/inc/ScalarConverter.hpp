/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:30:19 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/10 19:03:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# include <cstdlib>
# include <string>
# include <iostream>
# include <cerrno>
# include <cfloat>
# include <iomanip>
# include <climits>

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
/*                            MACROS                                          */
/******************************************************************************/

# define TO_CHAR 1
# define TO_INT 2
# define TO_FLOAT 3
# define TO_DOUBLE 4
# define TO_LITERAL 5
# define ERROR_SUCCESS -1

# define NO_UN_OVER_FLOW 0
# define CHECK_INT 1
# define CHECK_FLOAT 2

/******************************************************************************/
/*                            CLASS                                           */
/******************************************************************************/

class ScalarConverter
{
	private:
		/*
		 * Orthodox Canonical Form
		*/
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		/*
		 * Funtions
		*/
		//utils
		static void printConvert(char toChar, int toInt, float toFloat,
			double toDouble, int flag);
		static int	keyword(std::string &verify);
		static int 	repetitionCounter(const std::string &str, char c);
		//checker type
		static bool checkChar(std::string &verify);
		static bool checkInt(std::string &verify);
		static bool checkFloat(std::string &verify);
		static bool checkDouble(std::string &verify);
		//convert to..
		static bool convertToChar(std::string &str);
		static bool convertToInt(std::string &str);
		static bool convertToFloat(std::string &str);
		static bool convertToDouble(std::string &str);
		static bool convertToLiteral(std::string &str);
		//get type
		static int getType(std::string &verify);
	public:
		/*
		 * Default destructor
		*/
		~ScalarConverter(void);
		/*
		 * Membert Funtions
		*/
		static void convert(std::string scalar);
};
#endif
