/*编写你自己的Account类*/
#pragma once
#include<string>

class Account
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static	 void rate(double newRate) { interestRate = newRate; }

private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 35.68;
	static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();
