/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:22:58 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 15:44:25 by dacortes         ###   ########.fr       */
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

void identify(Base* p)
{
	int id = -1;
	std::string type[3] = {"\033[1m\033[38;5;208mA\033[m", \
		"\033[1m\033[1;32mB\033[m", "\033[1m\033[1;33mC\033[m"};
	id += ((dynamic_cast<A*>(p) != NULL) ? 1 : 0);
	id += ((dynamic_cast<B*>(p) != NULL) ? 2 : 0);
	id += ((dynamic_cast<C*>(p) != NULL) ? 3 : 0);
	std::cout << "Indentified by reference, is: " << \
	(id != -1 ? type[id]: "none") << std::endl;
}

void identify(Base& p)
{
	int id = -1;
	std::string type[3] = {"\033[1m\033[38;5;208mA\033[m", \
		"\033[1m\033[1;32mB\033[m", "\033[1m\033[1;33mC\033[m"};
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		id += 1;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		id += 2;
	}
	catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		id += 3;
	}
	catch(const std::exception& e){}
	std::cout << "Indentified by reference, is: " << \
	(id != -1 ? type[id]: "none") << std::endl;
}

int main(void)
{
	Base *base = create();
	identify(base);
	identify(*base);
	if (base != NULL)
		delete base;
	return (EXIT_SUCCESS);
}
