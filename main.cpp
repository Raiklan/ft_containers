/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:41:44 by saich             #+#    #+#             */
/*   Updated: 2022/12/07 19:14:34 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"
// test NAMESPACE::vector
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
	//using NAMESPACE::vector testing reserve size and capacity functions
	NAMESPACE::vector<int> v5(10);
	std::cout << "Vector size:" << v5.size() << std::endl;
	std::cout << "Vector capacity:" << v5.capacity() << std::endl;
	v5.reserve(15);
	std::cout << "Vector size:" << v5.size() << std::endl;
	std::cout << "Vector capacity:" << v5.capacity() << std::endl;
	v5.resize(20, 10);
	std::cout << "Vector size:" << v5.size() << std::endl;
	std::cout << "Vector capacity:" << v5.capacity() << std::endl;
	if (v5.empty() == false)
		std::cout << "NAMESPACE::vector is not empty" << std::endl;
	else
		std::cout << "NAMESPACE::vector is empty" << std::endl;
	std::cout << "Vector max size is:" << v5.max_size() << std::endl;
	NAMESPACE::vector<int> v6;
	v6 = v5;
	std::cout << "Vector size:" << v6.size() << std::endl;
	std::cout << "Vector capacity:" << v6.capacity() << std::endl;
	NAMESPACE::vector<int> v4;
	for (int i = 1; i <= 10; i++)
    {
        v4.push_back(i);
        std::cout << "Max capacity v4: " << v4.capacity() << std::endl;
    }
	std::cout << std::endl;
	
    // using ::iterator and ::reverse_iterator
    NAMESPACE::vector<int> v;
    NAMESPACE::vector<int>::iterator it;
    NAMESPACE::vector<int>::reverse_iterator rit;

	
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
        std::cout << "Max capacity: " << v.capacity() << std::endl;
    }

    it = v.begin();
    rit = v.rbegin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    while (rit != v.rend())
    {
        std::cout << *rit << std::endl;
        rit++;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // using insert() function
    NAMESPACE::vector<std::string> v2;
    NAMESPACE::vector<std::string>::iterator it2;
    
    v2.push_back("Hello");
    v2.push_back("World");
    v2.push_back("!");
    
    it2 = v2.begin();
    it2++;
    v2.insert(it2, "C++");
    it2 = v2.begin();
    while (it2 != v2.end())
    {
        std::cout << *it2 << std::endl;
        it2++;
    }
    
    // testing clear() function
    v.clear();
    it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    
    // testing erase() function
    v.erase(v.begin(), v.end());
    it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Max capacity: " << v.capacity() << std::endl;

    return (0);
}
