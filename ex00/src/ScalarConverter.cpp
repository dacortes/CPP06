/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:59:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/30 11:40:45 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

/*
 * Orthodox Canonical Form
*/
ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}

/*
 * Funtions
*/

int ScalarConverter::keyword(std::string &verify)
{
	std::string words[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (size_t i = 0; i < 6; i++)
	{
		if (words[i] == verify)
			return (i);
	}	   
	return (-1);
}

int ScalarConverter::repetitionCounter(const std::string &str, char c)
{
    int count;

	count = 0;
    for (size_t i = 0; i < str.length(); ++i)
	{
        if (str[i] == c)
            count++;
    }
    return (count);
}

// bool	ScalarConverter::checkLimits(const std::string &min, \
// 		const std::string &max, const std::string &verify)
// {
// 	size_t size = verify.length();
// 	size_t len_max = max.length();
// 	size_t len_min = min.length();

// 	std::string pos = "+" + max;
// 	if (!size or ((size > len_max and verify[0] != '-') \
// 			and (size > len_max and verify[0] != '+')) or size > len_min)
// 		return (EXIT_FAILURE);
// 	if (verify[0] != '-' and  (size == len_max) \
// 			and (std::strncmp(verify.c_str(), max.c_str(), len_max) > 0))
// 		return (EXIT_FAILURE);
// 	if (verify[0] == '-' and (size == len_min) \
// 			and (std::strncmp(verify.c_str(), min.c_str(), len_min) > 0))
// 		return (EXIT_FAILURE);
// 	if (verify[0] == '+' and size == (len_max + 1) \
// 			and (std::strncmp(verify.c_str(), pos.c_str(), (len_max + 1)) > 0))
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

bool ScalarConverter::checkChar(std::string &verify)
{
	return (verify.length() > 1 or (verify.length() ==  1 and (verify[0] < 32 \
		or verify[0] > 126)) or std::isdigit(verify.c_str()[0]));
}

bool ScalarConverter::checkInt(std::string &verify)
{
	if (!verify.length())
		return (EXIT_FAILURE);
	for (size_t i = (0 + (verify[0] == '-') + (verify[0] == '+')); verify[i];
			i++)
	{
		if (!std::isdigit(verify.c_str()[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool ScalarConverter::checkFloat(std::string &verify)
{
	int stt = 0;

	if (!verify.length())
		return (EXIT_FAILURE);
	stt += ScalarConverter::repetitionCounter(verify, '.');
	stt += ScalarConverter::repetitionCounter(verify, 'f');
	if (stt != 2)
		return (EXIT_FAILURE);
	for (size_t i = (0 + (verify[0] == '-') + (verify[0] == '+'));
			verify[i] and (verify[i] != 'f'); i++)
	{
		if (!std::isdigit(verify.c_str()[i]) and verify[i] != '.')
			return (EXIT_FAILURE);
	}
	if (verify[verify.length() - 1] != 'f')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool ScalarConverter::checkDouble(std::string &verify)
{
	if (!verify.length())
		return (EXIT_FAILURE);
	if (ScalarConverter::repetitionCounter(verify, '.') != 1)
		return (EXIT_FAILURE);
	for (size_t i = (0 + (verify[0] == '-') + (verify[0] == '+'));
			verify[i]; i++)
	{
		if (!std::isdigit(verify.c_str()[i]) and verify[i] != '.')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToInt(std::string &str)
{
	char *pEnd;

	long res = std::strtol(str.c_str(), &pEnd, 10);
	if ((res >  2147483647 or res < -2147483648) and errno == ERANGE)
	{
        std::cerr << "Error: Desbordamiento al convertir el número." << std::endl;
        return(EXIT_FAILURE);
	}
	std::cout << res << std::endl;
	return (EXIT_SUCCESS);
}


int ScalarConverter::getType(std::string &verify)
{
	char *qEnd;
	// double h = strtod (verify.c_str(), &qEnd);
	
	// std::cout << static_cast<float>(h) << std::endl;
	if (ScalarConverter::checkInt(verify))
		return (1);
	else
	{
		// int num = std::atoi(verify.c_str());
		// std::cout << O << "num: " << E << num << std::endl; 
		ScalarConverter::convertToInt(verify);
		// std::cout << "Límite inferior de float: " << FLT_MIN << std::endl;
    	// std::cout << "Límite superior de float: " << FLT_MAX << std::endl;
    	std::cout << "Límite inferior de double: " << DBL_MIN << std::endl;
    	std::cout << "Límite superior de double: " << DBL_MAX << std::endl;
		std::cout << "test: " << std::fixed << std::setprecision(1) << static_cast<float>(2147483647) << std::endl;
		std::cout << "test: " << static_cast<float>(1) << std::endl;
		std::cout << "->test: " << strtod("1.2", &qEnd) << std::endl;
		std::cout << "ssss: " << qEnd << std::endl;

		// double n = std::atof (verify.c_str());
		// double n;
		// char *pEnd;
		// n = strtod (verify.c_str(), &pEnd);
		if (errno == ERANGE)
		{ 
			std::cerr << "Error: Desbordamiento al convertir el número." << std::endl;
			return (EXIT_FAILURE);
		}
		// std::cout << n << std::endl;
	}
	if (ScalarConverter::checkFloat(verify))
		return (2);
	// else
	// {
		
	// }
	ScalarConverter::checkDouble(verify);
	//***********
	ScalarConverter::keyword(verify);
	//ScalarConverter::checkLimits(MIN_INTEGER, MAX_INTEGER, verify);

	return (6);
}

void ScalarConverter::convert(std::string scalar)
{
	ScalarConverter::getType(scalar);
}

