/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:59:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/27 10:35:22 by dacortes         ###   ########.fr       */
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

bool	ScalarConverter::checkLimits(const std::string &min, \
		const std::string &max, const std::string &verify)
{
	size_t size = verify.length();
	size_t len_max = max.length();
	size_t len_min = min.length();

	std::string pos = "+" + max;
	if (!size or ((size > len_max and verify[0] != '-') \
			and (size > len_max and verify[0] != '+')) or size > len_min)
		return (EXIT_FAILURE);
	if (verify[0] != '-' and  (size == len_max) \
			and (std::strncmp(verify.c_str(), max.c_str(), len_max) > 0))
		return (EXIT_FAILURE);
	if (verify[0] == '-' and (size == len_min) \
			and (std::strncmp(verify.c_str(), min.c_str(), len_min) > 0))
		return (EXIT_FAILURE);
	if (verify[0] == '+' and size == (len_max + 1) \
			and (std::strncmp(verify.c_str(), pos.c_str(), (len_max + 1)) > 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	if (ScalarConverter::checkLimits(MIN_INTEGER, MAX_INTEGER, verify))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Falta verificar los inff de todos los flotantes :v
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
	std::cout << "soy un float" << std::endl;
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
	std::cout << "soy un double" << std::endl;
	return (EXIT_SUCCESS);
}

int ScalarConverter::parsing(std::string &verify)
{
	(void)verify;
	return (1);
}

void ScalarConverter::convert(std::string scalar)
{
	std::cout << (ScalarConverter::checkInt(scalar) ? "no es un int" : "si es un int :D")
		<< std::endl;
	std::cout << (ScalarConverter::checkChar(scalar) ? "no es un char " : "si es un char :D")
		<< std::endl;
	ScalarConverter::checkFloat(scalar);
	ScalarConverter::checkDouble(scalar);
	if (!ScalarConverter::checkInt(scalar))
	{
		int i = std::atoi(scalar.c_str());
		std::cout << "num convert: " << i << std::endl;
	}
}

