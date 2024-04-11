/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:46:32 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/11 18:19:48 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

/*
 * Orthodox Canonical Form
*/
Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer& obj)
{
	(void)obj
}

Serializer &Serializer::operator=(const Serializer& obj)
{
	(void)obj
	return (*this);
}

Serializer::~Serializer(void)
{}

/*
 * Funtions
*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
