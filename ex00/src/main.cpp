/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:54:42 by dacortes          #+#    #+#             */
/*   Updated: 2024/03/26 11:25:22 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << R << "Error: " << E
			<< (ac > 1 ? "you have more than one argument" : "invalid argument")
			<< std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(av[1]);
	std::cout << &nanl << std::endl;
	return (EXIT_SUCCESS);
}
