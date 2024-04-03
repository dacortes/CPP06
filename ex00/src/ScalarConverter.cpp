/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:59:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/03 19:11:09 by dacortes         ###   ########.fr       */
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
	if ((res > INT_MAX or res < INT_MIN) or errno == ERANGE)
	{
        std::cerr << "Error: Desbordamiento al convertir el número: int" << std::endl;
        return(EXIT_FAILURE);
	}
	std::cout << "Int: " << std::fixed << std::setprecision(1) << res << std::endl;
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToFloat(std::string &str)
{
	char *pEnd;

	double res = strtod(str.c_str(), &pEnd);
	if ((res > FLT_MAX or res < FLT_MIN ) or errno == ERANGE)
	{
		std::cerr << "Error: Desbordamiento al convertir el número: float" << std::endl;
        return(EXIT_FAILURE);
	}
	std::cout << "Float: " << std::fixed << std::setprecision(1) << res << "f" << std::endl;
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToDouble(std::string &str)
{
	char *pEnd;

	double res = strtod(str.c_str(), &pEnd);
	if ((res > DBL_MAX or res < DBL_MIN) or errno == ERANGE)
	{
		std::cerr << "Error: Desbordamiento al convertir el número: float" << std::endl;
        return(EXIT_FAILURE);
	}
	// if (static_cast<float>(res))
	// 	std::cout << "OK" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << res << std::endl;
	return (EXIT_SUCCESS);
}

int ScalarConverter::getType(std::string &verify)
{
	if (!ScalarConverter::checkChar(verify))
		return (TO_CHAR);
	if (!ScalarConverter::checkInt(verify))
		return (TO_INT);
	if (!ScalarConverter::checkFloat(verify))
		return (TO_FLOAT);
	if (!ScalarConverter::checkDouble(verify))
		return (TO_DOUBLE);
	if (!ScalarConverter::keyword(verify))
		return (TO_LITERAL);
	return (ERROR_SUCCESS);
}

void ScalarConverter::convert(std::string scalar)
{
	int stt = ScalarConverter::getType(scalar);

	std::cout << stt << std::endl;
	if ( stt == TO_INT)
		ScalarConverter::convertToInt(scalar);
	if (stt == TO_FLOAT)
		ScalarConverter::convertToFloat(scalar);
	if (stt == TO_DOUBLE)
		ScalarConverter::convertToDouble(scalar);
}

