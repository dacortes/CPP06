/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:13:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 09:47:26 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class A: public Base
{
	public:
		A(void)
		{
			std::cout << "Created" << O << " A " << E << "class" << std::endl;
		};
};
#endif
