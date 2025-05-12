/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:53:47 by jhervoch          #+#    #+#             */
/*   Updated: 2025/05/12 22:33:51 by jhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	std::cout << "[";
	std::cout << timeinfo->tm_year + 1900;
	std::cout <<  std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1;
	std::cout <<  std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
	std::cout << "_";
	std::cout <<  std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
	std::cout <<  std::setfill('0') << std::setw(2) << timeinfo->tm_min;
	std::cout <<  std::setfill('0') << std::setw(2) << timeinfo->tm_sec;
	std::cout << "] ";
}

void Account::displayStatus() const {
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account (int initial_deposit){
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	displayStatus();
	std::cout << "created" << std::endl;
}
