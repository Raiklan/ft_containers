/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:46:08 by saich             #+#    #+#             */
/*   Updated: 2023/01/02 18:42:03 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <vector>
#include <map>
#include <stack>

#ifndef FT
# define NAMESPACE std
#else
# define NAMESPACE ft
#endif

using namespace NAMESPACE;
template <class T>
void	print(vector<T>& lst)
{
	std::cout << "My vector contains:" << std::endl;
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "TEST VECTOR(int)" << std::endl;
	std::cout << "Push back 10 element" << std::endl;
	vector<int> v_int;
	for (int i = 0; i < 10; i++)
		v_int.push_back(i);
	print(v_int);
	std::cout << "erase first 3 and 6th one" << std::endl;
	v_int.erase(v_int.begin() + 6);
	v_int.erase(v_int.begin(), v_int.begin() + 3);
	print(v_int);
	std::cout << "Insert a single element, fill and a range of them" << std::endl;
	vector<int>::iterator it;
	it = v_int.begin();
	it = v_int.insert ( it , 200);
	v_int.insert (it,2,300);
	// "it" no longer valid, get a new one:
	it = v_int.begin();
	vector<int> anothervector (2,400);
	v_int.insert (it+2,anothervector.begin(),anothervector.end());	
	int myarray [] = { 501,502,503 };
	v_int.insert (v_int.begin(), myarray, myarray+3);
	print(v_int);
	std::cout << "Pop Back last element" << std::endl;
	v_int.pop_back();
	print(v_int);
	std::cout << "Assign elements" << std::endl;
	vector<int> first;
	vector<int> second;
	vector<int> third;	
	first.assign (7,100);             // 7 ints with a value of 100	
	print(first);
	it=first.begin()+1;	
	second.assign (it,first.end()-1); // the 5 central values of first	
	print(second);
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.	
	print(third);
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "Swap elements" << std::endl;
	vector<int> foo (3,100);   // three ints with a value of 100
	vector<int> bar (5,200);   // five ints with a value of 200	
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	  std::cout << ' ' << foo[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	  std::cout << ' ' << bar[i];
	std::cout << '\n';
	std::cout << "Clear function" << std::endl;
	print(v_int);
	v_int.clear();
	v_int.push_back(1200);
	v_int.push_back(42);
	print(v_int);
	std::cout << "Capacity functions" << std::endl;
	std::cout << "max size of v_int =" << v_int.max_size() << std::endl;
	std::cout << "size of v_int =" << v_int.size() << std::endl;
	std::cout << "capacity of v_int =" << v_int.capacity() << std::endl;
	std::cout << "is v_int empty ? " << v_int.empty() << std::endl;
	v_int.clear();
	std::cout << "How about now ? " << v_int.empty() << std::endl;
	std::cout << "Resize function" << std::endl;
	vector<int> myvector;
	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);
	print(myvector);
	myvector.resize(5);
	print(myvector);
	myvector.resize(8,100);
	print(myvector);
	myvector.resize(12);
	print(myvector);
	std::cout << "Reserve function" << std::endl;
	vector<int>::size_type sz;
	vector<int> foo1;
	sz = foo1.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
	  foo1.push_back(i);
	  if (sz!=foo1.capacity()) {
		sz = foo1.capacity();
		std::cout << "capacity changed: " << sz << '\n';
	  }
	}
	std::cout << "References" << std::endl;
	v_int.push_back(42);
	v_int.push_back(84);
	v_int.push_back(21);
	print(v_int);
	v_int.front() -= v_int.back();
	std::cout << "Front is now " << v_int.front() << std::endl;
	std::cout << "At 0 = " << v_int.at(0) << std::endl;
	std::cout << "At 1 = " << v_int.at(1) << std::endl;
	std::cout << "At 2 = " << v_int.at(2) << std::endl;
}
