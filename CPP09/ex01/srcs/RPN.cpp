#include <iostream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <cctype>
#include <limits>
#include "RPN.hpp"

static bool	is_operator(char const& c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static int	makeOp(long long a, long long b, char c)
{
	long long res = 0;
	switch(c)
	{
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			if (b == 0)
				throw zeroDiv();
			res = a / b;
			break;
		default:
			throw wrongExpression();
	}
	if (res < std::numeric_limits<int>::min())
		throw intMinOverflow();
	if (res > std::numeric_limits<int>::max())
		throw intMaxOverflow();
	return (static_cast<int>(res));
}

void	displayRPN(std::string const& expression)
{
	std::list<int>		lst;
	std::istringstream	iss(expression);
	std::string		token;
	int			a = 0;
	int			b = 0;
	while (iss >> token)
	{
        	if (token.size() > 1)
			throw wrongExpression();
		if (isdigit(token[0]))
			lst.push_back(atoi(token.c_str()));
		else if (is_operator(token[0]) && lst.size() > 1)
		{
			b = lst.back();
			lst.pop_back();
			a = lst.back();
			lst.pop_back();
			lst.push_back(makeOp(static_cast<long long>(a), static_cast<long long>(b), token[0]));
		}
		else
			throw wrongExpression();
	}
	if (lst.size() != 1)
		throw wrongExpression();
	std::cout << lst.back() << std::endl;
}

const char* zeroDiv::what() const throw()
{
	return ("Error: You can't divided by zero!!");
}

const char* intMinOverflow::what() const throw()
{
	return ("Error: Result overflow INT_MIN");
}

const char* intMaxOverflow::what() const throw()
{
	return ("Error: Result overflow INT_MAX");
}

const char* wrongExpression::what() const throw()
{
	return ("Error: Incorrect RPN expression");
}