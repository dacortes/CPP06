/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:59:09 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/11 16:19:06 by dacortes         ###   ########.fr       */
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
//Utils
void	ScalarConverter::printConvert(char toChar, int toInt, float toFloat,
	double toDouble, int flag)
{
	std::string displayChar;
	displayChar.append(1, toChar);
	std::cout << "char:\t" <<
	((toInt < 0 or toInt > 255) ? \
	"[ overflow / underflow ]" : (ScalarConverter::checkChar(displayChar) \
	and !(toChar >= '0' and toChar <='9') ? \
	"Non displayable" : &displayChar[0]))
	<< std::endl;
	std::cout << "int:\t";
	if ((flag == CHECK_INT) or (flag == CHECK_INT + CHECK_FLOAT))
		std::cout << "[ overflow / underflow ]" << std::endl;
	else
		std::cout << toInt << std::endl;
	std::cout << "float:\t";
	if ((flag == CHECK_FLOAT) or (flag == CHECK_INT + CHECK_FLOAT))
		std::cout << "[ overflow / underflow ]" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << toFloat << "f"
		<< std::endl;
 	std::cout << "double:\t" << std::fixed << std::setprecision(1) << toDouble
 		<< std::endl;
}

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

//checker type
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
//convert to
bool ScalarConverter::convertToChar(std::string &str)
{
	char	toChar = static_cast<char>(str[0]);
	int		toInt = static_cast<int>(toChar);
	float	toFloat = static_cast<float>(toChar);
	double	toDouble = static_cast<double>(toChar);
	ScalarConverter::printConvert(toChar, toInt, toFloat, toDouble,
	NO_UN_OVER_FLOW);
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToInt(std::string &str)
{
	char *pEnd;

	long res = std::strtol(str.c_str(), &pEnd, 10);
	if ((res > INT_MAX or res < INT_MIN) or errno == ERANGE)
	{
		std::cerr << "Error: Invalid range: Int: overflow/underflow"
		<< std::endl;
        return(EXIT_FAILURE);
	}
	char	toChar = static_cast<char>(res);
	int		toInt = static_cast<int>(res);
	float	toFloat = static_cast<float>(res);
	double	toDouble = static_cast<double>(res);
	ScalarConverter::printConvert(toChar, toInt, toFloat, toDouble,
	NO_UN_OVER_FLOW);
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToFloat(std::string &str)
{
	char *pEnd;

	double res = strtod(str.c_str(), &pEnd);
	if ((res > FLT_MAX or res < FLT_MIN ) or errno == ERANGE)
	{
		std::cerr << "Error: Invalid range: float: overflow/underflow"
		<< std::endl;
	}
	char	toChar = static_cast<char>(res);
	int		toInt = static_cast<int>(res);
	float	toFloat = static_cast<float>(res);
	double	toDouble = static_cast<double>(res);
	long	checkInt = static_cast<long>(res);
	ScalarConverter::printConvert(toChar, toInt, toFloat, toDouble,
	(((checkInt > INT_MAX or checkInt < INT_MIN) or errno == ERANGE)) ? \
	CHECK_INT : NO_UN_OVER_FLOW);
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToDouble(std::string &str)
{
	char *pEnd;

	double res = strtod(str.c_str(), &pEnd);
	if ((res > DBL_MAX or res < DBL_MIN) or errno == ERANGE)
	{
		std::cerr << "Error: Invalid range: Double: overflow/underflow"
		<< std::endl;
        return(EXIT_FAILURE);
	}
	char	toChar = static_cast<char>(res);
	int		toInt = static_cast<int>(res);
	float	toFloat = static_cast<float>(res);
	double	toDouble = static_cast<double>(res);
	long	checkInt = static_cast<long>(res);
	ScalarConverter::printConvert(toChar, toInt, toFloat, toDouble,
	(((checkInt > INT_MAX or checkInt < INT_MIN) or errno == ERANGE) ? \
	(((res > FLT_MAX or res < FLT_MIN) or errno == ERANGE) ? \
	(CHECK_INT + CHECK_FLOAT) : CHECK_INT) : NO_UN_OVER_FLOW));
	return (EXIT_SUCCESS);
}

bool ScalarConverter::convertToLiteral(std::string &str)
{
	std::string words[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	std::cout << "char:\timpossible" << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	std::cout << "float:\t" << ((ScalarConverter::keyword(str) < 3) ? \
	words[ScalarConverter::keyword(str)] : \
	words[ScalarConverter::keyword(str) - 3]) << std::endl;
	std::cout << "double: " << ((ScalarConverter::keyword(str) > 2) ? \
	words[ScalarConverter::keyword(str)] : \
	words[ScalarConverter::keyword(str) + 3]) << std::endl;
	return (EXIT_SUCCESS);
}

//get type
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
	if (ScalarConverter::keyword(verify) > -1)
		return (TO_LITERAL);
	return (ERROR_SUCCESS);
}

void ScalarConverter::convert(std::string scalar)
{
	int stt = ScalarConverter::getType(scalar);

	if ( stt == TO_CHAR)
		ScalarConverter::convertToChar(scalar);
	if ( stt == TO_INT)
		ScalarConverter::convertToInt(scalar);
	if (stt == TO_FLOAT)
		ScalarConverter::convertToFloat(scalar);
	if (stt == TO_DOUBLE)
		ScalarConverter::convertToDouble(scalar);
	if (stt == TO_LITERAL)
		ScalarConverter::convertToLiteral(scalar);
	if (stt == -1)
	{
		std::cout << "Error: Can't convert: " << scalar << std::endl;
		std::cout << "-> Invalid type of literal" << std::endl;
		std::cout << " * Allowed literals are:\n" <<
		"[ Char -> 'a' ] | [ Int -> 1 ] | [ Float -> 1.5f ] | [ Double -> 1.5 ]"
		<< std::endl;
	}
	
}

