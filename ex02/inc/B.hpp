/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:17:26 by dacortes          #+#    #+#             */
/*   Updated: 2024/04/17 09:47:30 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B: public Base
{
	public:
		B(void)
		{
			std::cout << "Created" << G << " B " << E << "class" << std::endl;
		};
};
#endif
