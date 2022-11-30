/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:47:43 by saich             #+#    #+#             */
/*   Updated: 2022/11/30 19:09:56 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <iostream>


#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
    template<bool Cond, class T = void>
        struct enable_if {};
    template<class T>
        struct enable_if<true, T> { typedef T type; };
}

#endif
