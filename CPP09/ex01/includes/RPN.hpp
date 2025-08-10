#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>

#define USAGE_ERROR "Error: Usage is ./RPN \"reverse polish notation mathematical expression\""

/* RPN Functions */
void	displayRPN(std::string const& expression);

/* Exceptions */
class zeroDiv : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class intMinOverflow : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class intMaxOverflow : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class wrongExpression : public std::exception
{
	public :
		virtual const char* what() const throw();
};

#endif 