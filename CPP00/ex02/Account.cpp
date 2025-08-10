/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:18:26 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 17:52:17 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	struct tm * timeinfo;

	time(&timestamp);
	timeinfo = localtime(&timestamp);
	std::cout << "[" <<  std::setfill ('0') << std::setw (4) << timeinfo->tm_year + 1900;
	std::cout << std::setfill ('0') << std::setw (2) << timeinfo->tm_mon + 1;
	std::cout << std::setfill ('0') << std::setw (2) << timeinfo->tm_mday;
	std::cout << "_" << std::setfill ('0') << std::setw (2) << timeinfo->tm_hour;
	std::cout << std::setfill ('0') << std::setw (2) << timeinfo->tm_min;
	std::cout << std::setfill ('0') << std::setw (2) << timeinfo->tm_sec << "] ";
}

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	_nbAccounts++;
	this->_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ; 
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ; 
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";";
	std::cout << "amount:" <<  this->_amount<< ";";
	std::cout << "deposits:" <<  this->_nbDeposits << ";";
	std::cout << "withdrawals:" <<  this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount<< ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" <<  this->_amount << ";";
	std::cout << "nb_deposits:" <<  this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount<< ";";
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" <<  this->_amount<< ";";
		std::cout << "nb_withdrawals:" <<  this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout <<"withdrawal:refused" << std::endl;
		return (false);
	}
}
