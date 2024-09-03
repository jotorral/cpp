#include "RPN.hpp" 

Rpn::Rpn()
{
	std::cout << "An RPN has been constructed by default." << std::endl;
}

Rpn::~Rpn()
{
	std::cout << "An RPN has been destructed." << std::endl;
}

Rpn::Rpn (const Rpn &other) : _operands(other._operands)
{
	std::cout << "An RPN has been constructed as a copy." << std::endl;
}

Rpn &Rpn::operator=(const Rpn &other)
{
	if (this != &other)
		(*this)._operands = other._operands;
	return (*this);
}

void	Rpn::setRpnOperand(int operand)
{
	_operands.push(operand);
}

int	Rpn::getRpnOperand()
{
	if (_operands.empty())
	{
        throw std::runtime_error("Error: Stack is empty. Probably the argument has a sintax error.");
	}
	int operand = _operands.top();
	_operands.pop();
	return (operand);
}

bool	Rpn::hasNoOperand()
{
	bool noOperand = false;
	if (_operands.empty())
		noOperand = true;
	return (noOperand);
}
