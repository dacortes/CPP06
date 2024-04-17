/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:50:24 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 09:00:53 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main(void)
{
	Data foo;

	foo.firstName = "foo";
	foo.lastName = "fuu";
	foo.age = 30;
	uintptr_t renfe = Serializer::serialize(&foo);
	std::cout << O << "Reference::seriialize: " << E << renfe << std::endl;
	Data *fiu = Serializer::deserialize(renfe);
	std::cout << O << "Reference::deserialize: " << E << std::endl;
	std::cout << O << "firstName: " << E << fiu->firstName << std::endl;
	std::cout << O << "lastName: " << E << fiu->lastName << std::endl;
	std::cout << O << "age: " << E << fiu->age << std::endl;
	return (EXIT_SUCCESS);
}
