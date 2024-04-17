/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:22:58 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 10:12:00 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base	*create(void)
{
	Base	*newClass;

	newClass = NULL;
	std::srand(clock());
	switch (rand() % 3)
	{
	case 0:
		newClass = new A();
		break;
	case 1:
		newClass = new B();
		break;
	case 2:
		newClass = new C();
		break;
	default:
		break;
	}
	return (newClass);
}

int identify(Base *ptr)
{
	int id = -1;
	std::string type[3] = {"A", "B", "C"};
	id += ((dynamic_cast<A*>(ptr) != NULL) ? 1 : 0);
	id += ((dynamic_cast<B*>(ptr) != NULL) ? 2 : 0);
	id += ((dynamic_cast<C*>(ptr) != NULL) ? 3 : 0);
	std::cout << "Indentified by reference, is: " << \
	(id != -1 ? type[id]: "none") << std::endl;
	return (id);
}

int main(void)
{
	Base *base = create();
	if (identify(base) != -1)
		delete base;
	return (EXIT_SUCCESS);
}
