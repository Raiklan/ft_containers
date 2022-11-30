/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:43:47 by saich             #+#    #+#             */
/*   Updated: 2022/11/30 19:09:36 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory.h>
#include <uchar.h>


#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{   
    template <class T> struct is_integral { static const bool value = false; };
    template <> struct is_integral<bool> { static const bool value = true; };
    template <> struct is_integral<char> { static const bool value = true; };
    template <> struct is_integral<char16_t> { static const bool value = true; };
    template <> struct is_integral<char32_t> { static const bool value = true; };
    template <> struct is_integral<wchar_t> { static const bool value = true; };
    template <> struct is_integral<short int> { static const bool value = true; };
    template <> struct is_integral<int> { static const bool value = true; };
    template <> struct is_integral<long int > { static const bool value = true; };
    template <> struct is_integral<long long int> { static const bool value = true; };
    template <> struct is_integral<unsigned char> { static const bool value = true; };
    //template <> struct is_integral<unsigned short int> { static const bool value = true; };
    //template <> struct is_integral<unsigned int> { static const bool value = true; };
    template <> struct is_integral<unsigned long int> { static const bool value = true; };
    template <> struct is_integral<unsigned long long int> { static const bool value = true; };
}

#endif
