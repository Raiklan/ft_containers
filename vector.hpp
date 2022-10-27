/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:54 by saich             #+#    #+#             */
/*   Updated: 2022/10/27 14:26:42 by saich            ###   ########.fr       */
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
			template <typename PointerType> class RandomAccessIterator {
				public:
					using iterator_category = std::random_access_iterator_tag;
					using value_type = PointerType;
					using difference_type = std::ptrdiff_t;
					using pointer = PointerType*;
					using reference = PointerType&;
				protected:
					PointerType*	m_ptr;
				public:
				
					RandomAccessIterator(PointerType* ptr =nullptr){
						m_ptr = ptr;
					}
					RandomAccessIterator(const RandomAccessIterator<PointerType>& RAIterator);
					~RandomAccessIterator(){}
					
					RandomAccessIterator<PointerType>&		operator=(const RandomAccessIterator<PointerType>& RAIterator);
			};
			
	}
}

#endif


