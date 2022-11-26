/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:54 by saich             #+#    #+#             */
/*   Updated: 2022/11/26 22:45:36 by saich            ###   ########.fr       */
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
			// Constructor, destructor, operator = ====================================================================
			explicit vector(const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_capacity(0),
				_size(0),
				_data(nullptr)
			{}
			explicit vector(size_type n,const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			:
				_capacity(n),
				_size(n),
				_alloc(alloc)
			{
				_data = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(&_data[i], val);
			}
			vector (const vector& x) : _capacity(x.capacity()), _size(x.size()), _alloc(x._alloc)
            {
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0;i < _size;i++)
                    _alloc.construct(&_data[i], x._data[i]);
            }
			virtual ~vector()
			{
                for(size_type i=0;i< _size;i++)
                {
                    _alloc.destroy(&_data[i]);
                }
                _alloc.deallocate(_data, _size);
            }
			vector& operator= (const vector& x)
			{
				_alloc = x.get_allocator();
				if (!_data)
				{
					_data = _alloc.allocate(x._capacity);
					for (size_t i = 0; i < x._size; i++)
						_alloc.construct(&_data[i], x._data[i]);
					_capacity = x._capacity;
                    _size = x._size;
                    return *this;
				}
				if (_capacity == x._capacity)
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.destroy(&_data[i]);
					for (size_t i = 0; i <x._size; i++)
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
            // Capacity functions=========================================================================================================
			size_type size() const {return _size;}

			size_type capacity() const {return _capacity;}

			size_type max_size() const {return _alloc.max_size();}

			bool empty() const 
			{
				if (_size == 0)
					return true;
				return false;
			}

			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					value_type *tmp;
					tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(tmp+i, _data[i]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_alloc.deallocate(_data, _capacity);
					_data = tmp;
					_capacity = n;
				}
			}

			/*void resize (size_type n, value_type val = value_type())
			{
				
			}*/
		private:
            size_type       									_capacity;
            size_type       									_size;
            allocator_type  									_alloc;
            value_type      									*_data;
	};
};

#endif


