/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:54 by saich             #+#    #+#             */
/*   Updated: 2022/10/12 18:55:55 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// Libraries ==================================================================
# include <iostream>
# include <memory>
# include <cstddef>
# include <tgmath.h>
// ============================================================================
namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	typename allocator_type::size_type			size_type;
			explicit vector(const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_end_capacity(nullptr)
			{}
	}
}

#endif


