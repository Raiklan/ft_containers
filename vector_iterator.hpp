/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:55:03 by saich             #+#    #+#             */
/*   Updated: 2023/01/02 15:55:31 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp" 

namespace ft
{

template < class T>
class vector_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public :

		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category			iterator_category;

		vector_iterator(void) : _value(0) {}
		vector_iterator(reference value) : _value(&value) {}
		vector_iterator(pointer value) : _value(value) {}
		vector_iterator(const vector_iterator& rhs) : _value(rhs._value) {}
		virtual ~vector_iterator(void) {}

		operator vector_iterator<const T>()
		{
			return vector_iterator<const T>(*_value);
		}

		vector_iterator&		operator=(pointer rhs)
		{
			_value = rhs;
			return *this;
		}
		vector_iterator&		operator=(const vector_iterator& rhs)
		{
			_value = rhs._value;
			return *this;
		}

		bool						operator==(const vector_iterator& rhs) const
		{ return (_value == rhs._value); }
		bool						operator!=(const vector_iterator& rhs) const
		{ return (_value != rhs._value); }
		bool						operator<(const vector_iterator& rhs) const
		{ return (_value < rhs._value); }
		bool						operator>(const vector_iterator& rhs) const
		{ return (_value > rhs._value); }
		bool						operator<=(const vector_iterator& rhs) const
		{ return (_value <= rhs._value); }
		bool						operator>=(const vector_iterator& rhs) const
		{ return (_value >= rhs._value); }

		reference					operator*(void) const
		{ return *_value; }
		pointer					operator->(void) const
		{ return _value; }
		reference					operator[](difference_type rhs) const
		{ return _value[rhs]; }

		vector_iterator&		operator+=(difference_type rhs)
		{
			_value += rhs;
			return *this;
		}
		vector_iterator&		operator-=(difference_type rhs)
		{
			_value -= rhs;
			return *this;
		}

		vector_iterator		operator+(difference_type rhs) const
		{ return (vector_iterator(_value + rhs)); }

		difference_type				operator-(const vector_iterator& rhs) const
		{ return (_value - rhs._value); }
		vector_iterator		operator-(difference_type rhs) const
		{ return (vector_iterator(_value - rhs)); }

		vector_iterator&		operator++(void)
		{
			++_value;
			return *this;
		}
		vector_iterator		operator++(int)
		{
			vector_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		vector_iterator&		operator--(void)
		{
			--_value;
			return *this;
		}
		vector_iterator		operator--(int)
		{
			vector_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	private :

		pointer _value;
};

}

#endif
