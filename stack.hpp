/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:52:48 by saich             #+#    #+#             */
/*   Updated: 2022/12/14 16:53:33 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory.h>
#include "iterator.hpp"
#include "RAiterator.hpp"
#include "reverse_iterator.hpp"

#include <iostream>     // std::cout
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >

    class stack
    {
        public:
            typedef typename Container::value_type                                          value_type;
            typedef Container                                                       container_type;
            typedef typename Container::size_type                                              size_type;

            explicit stack (const container_type& ctnr = container_type()):my_container(ctnr)
            {

            }
            container_type base() const
            {
                return my_container;
            }
            bool empty() const
            {
                return my_container.empty();
            }

            size_type size() const
            {
                return my_container.size();
            }

            value_type& top()
            {
                return my_container.back();
            }

            const value_type& top() const
            {
                return my_container.back();
            }

            void push (const value_type& val)
            {
                return my_container.push_back(val);
            }

            void pop()
            {
                return my_container.pop_back();
            }


            virtual ~stack() {};
        
        protected:
            container_type my_container;
    };
    template <class T, class Container>
    bool operator==(const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() == y.base());
    }

    template <class T, class Container>
    bool operator< (const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() < y.base());
    }

    template <class T, class Container>
    bool operator!=(const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() != y.base());
    }

    template <class T, class Container>
    bool operator> (const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() > y.base());
    }

    template <class T, class Container>
    bool operator>=(const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() >= y.base());
    }

    template <class T, class Container>
    bool operator<=(const ft::stack<T, Container>& x,
                    const ft::stack<T, Container>& y)
    {
        return (x.base() <= y.base());
    }

}
