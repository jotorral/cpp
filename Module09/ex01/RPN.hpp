#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>

class Rpn
{
	private:
		std::stack<int>	_operands;

	public:
		Rpn();
		~Rpn();
		Rpn (const Rpn &other);
		Rpn &operator=(const Rpn &other);

		void	setRpnOperand(int);
		int		getRpnOperand();
		bool	hasNoOperand();
};
