/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:08 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 13:16:57 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual			~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
//class D : public Base {};

Base::~Base(void)
{
}

Base*	generate()
{
	int i = std::rand();

	if (i % 3 == 0)
		return (new A);
	if (i % 3 == 1)
		return (new B);
	if (i % 3 == 2)
		return (new C);
	return (NULL);
}

// Base*	generate()
// {
// 	int i = std::rand();

// 	if (i % 4 == 0)
// 		return (new A);
// 	if (i % 4 == 1)
// 		return (new B);
// 	if (i % 4 == 2)
// 		return (new C);
// 	if (i % 4 == 3)
// 		return (new D);
// 	return (NULL);
// }

void	identify(Base* p)
{
	if (!p)
	{
		std::cout << "nullptr" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" <<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" <<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" <<std::endl;
	else
		std::cout << "other than A/B/C!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
        	(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	std::cout << "other than A/B/C!" << std::endl;
}


#endif 