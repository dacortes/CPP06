/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:54:42 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/11 16:19:35 by dacortes         ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}
