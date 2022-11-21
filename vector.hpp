/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:54 by saich             #+#    #+#             */
/*   Updated: 2022/11/21 17:55:32 by saich            ###   ########.fr       */
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
			typedef	size_t										size_type;
			explicit vector(const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_capacity(0),
				_size(0),
				_data(nullptr)
			{}
			explicit vector(size_type n,const value_type& val = value_type(), const allocator_type& = allocator_type())
			:
				_capacity(n),
				_size(n),
				_alloc(alloc)
			{
				_data = alloc.allocate(_capacity);
				for (size_t i = 0, i < _size, i++)
					_alloc.construct(&_data[i], val);
			}
			vector (const vector& x) : _capacity(x.capacity()), _size(x.size()), _alloc(x._alloc)
            {
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0;i < _size;i++)
                    _alloc.construct(&_data[i], x._data[i]);
            }
			vector& operator= (const vector& x)
			{
				_alloc = x.get_allocator();
				if (!_data)
				{
					_data = _alloc.allocate(x._capacity);
					for (size_t i = 0, i < x._size, i++)
						_alloc.construct(&_data[i], x._data[i]);
					_capacity = x._capacity;
                    _size = x._size;
                    return *this;
				}
				if (_capacity == x._capacity)
				{
					for (size_t i = 0, i <_size, i++)
						_alloc.destroy(&_data[i]);
					for (size_t i = 0, i <x._size, i++)
						_alloc.construct(&_data[i], x._data[i]);
				}
				else
				{
					for(size_t i = 0; i < _size; i++)
                    {
                        _alloc.destroy(&_data[i]);
                    }
                    _alloc.deallocate(_data, _capacity);
                    _data = _alloc.allocate(x._capacity);
                    for(size_t i = 0; i < x._size; i++)
                    {
                        _alloc.construct(&_data[i], x._data[i]);
                    }
				}
				 _capacity = x._capacity;
                _size = x._size;
                return *this;
			}
            


	}
}

#endif
