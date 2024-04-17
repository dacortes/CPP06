/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:17:41 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 09:47:33 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C: public Base
{
	public:
		C(void)
		{
			std::cout << "Created" << Y << " C " << E << "class" << std::endl;
		};
};
#endif
