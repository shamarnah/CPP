#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *timeInfo = std::localtime(&now);
	/* converts that time (the current time) into a structure containing individual pieces:
	tm_year → year minus 1900
	tm_mon → month from 0 to 11
	tm_mday → day
	tm_hour → hour
	tm_min → minute
	tm_sec → second */
    std::cout << "["
              << timeInfo->tm_year + 1900
              << std::setfill('0') << std::setw(2) << timeInfo->tm_mon + 1
              << std::setfill('0') << std::setw(2) << timeInfo->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << timeInfo->tm_hour
              << std::setfill('0') << std::setw(2) << timeInfo->tm_min
              << std::setfill('0') << std::setw(2) << timeInfo->tm_sec
              << "] ";
}
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" <<std::endl;
}
Account::~Account(void)
{
	_nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
          << ";p_amount:" << p_amount
          << ";deposit:" << deposit
          << ";amount:" << _amount
          << ";nb_deposits:" << _nbDeposits
          << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}
int Account::checkAmount(void) const
{
    return _amount;
}