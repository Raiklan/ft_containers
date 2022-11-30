/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:54 by saich             #+#    #+#             */
/*   Updated: 2022/11/30 19:06:34 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// Libraries ==================================================================
# include <iostream>
# include <memory>
# include <cstddef>
# include <tgmath.h>
# include "is_integral.hpp"
# include "equal.hpp"
# include "enable_if.hpp"
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
				_capacity(0),
				_size(0),
				_alloc(alloc),
				_data(0)
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
			/* -----------------------ITERATORS-------------------------------------
			iterator            begin() {return iterator(_data);}
            const_iterator      begin() const {return const_iterator(_data);}
            iterator            end() {return iterator(_data + _size);}
            const_iterator      end() const {return const_iterator(_data + _size);}
            reverse_iterator    rbegin() {return reverse_iterator(this->end());}
            const_reverse_iterator  rbegin() const {return const_reverse_iterator(this->end());}
            reverse_iterator    rend() {return reverse_iterator(this->begin());}
            const_reverse_iterator     rend() const {return const_reverse_iterator(this->begin());}
			 -----------------------ITERATORS-------------------------------------*/
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

			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					_size = n;
				else if (n > _size)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
					{
						_alloc.construct(&_data[i], val);
					}
					_size = n;
				}
			}
			// Modifiers =================================================================================================================
			
			void assign (size_type n, const value_type& val)
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                for(size_t i = 0; i < n; i++)
                    _alloc.construct(&_data[i], val);
                _size = n;
            }
			
			void push_back (const value_type& val)
            {
                if (_size + 1 > _capacity)
                {
                    if (_capacity == 0)
                        reserve(1);
                    else
                        reserve(_capacity * 2);
                }
                _alloc.construct(&_data[_size], val);
                _size++;
            }
			
			void pop_back()
            {
                if (_size != 0)
                {
                    _alloc.destroy(&_data[_size - 1]);
                    _size--;
                }
            }
			
			void    swap(vector &x)
            {
                size_type tmp = _size;
                _size = x._size;
                x._size = tmp;

                tmp = _capacity;
                _capacity = x._capacity;
                x._capacity = tmp;
                
                value_type *another_tmp = _data;

                _data = x._data;
                x._data = another_tmp;
            }

            void    clear()
            {
                for(size_type i=0; i < _size ; i++)
                    _alloc.destroy(_data + i);
                _size = 0;
            }
            // Element access ============================================================================================================
            reference front()
            {
                return _data[0];
            }
        
            const_reference front() const
            {
                return _data[0];
            }

            reference back()
            {
                return _data[_size - 1];
            }
            const_reference back() const
            {
                return _data[_size - 1];
            }

            reference at (size_type n)
            {
                if (n > _size)
                    throw std::out_of_range("Out of range");
                return _data[n];
            }
			
            const_reference at (size_type n) const
            {
                if (n > _size)
                    throw std::out_of_range("Out of range");
                return _data[n];
            }
			
			reference operator[] (size_type n)
            {
                return _data[n];
            }
			
            const_reference operator[] (size_type n) const
            {
                return _data[n];
            }
			// Allocator =================================================================================================================
            allocator_type get_allocator() const
            {
                allocator_type my_copy(_alloc);
                return my_copy;
            }
			// Non-member function overloads =============================================================================================
		private:
			size_type       									_capacity;
			size_type       									_size;
			allocator_type  									_alloc;
            value_type      									*_data;
	};
};

#endif


