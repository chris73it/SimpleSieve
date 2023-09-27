#include "Quot.h"

std::ostream& operator << (std::ostream& _os, const Quot& _q)
{
	_os << _q.m_num << " : " << _q.m_den << " ["
		<< _q.m_num_factors << " : " << _q.m_den_factors << "]";
	return _os;
}

Quot::operator double() const
{
	return (double)m_num / (double)m_den;
}

double Quot::approx()
{
	return *this;
}

// Under the assumption that we only need to care for values that
// are at most 127, only factors 2 3 and 5 can happen with exponent 3
// or greater, while all the other factors can at most have exponent 2.
void Quot::simplify()
{
	uint32_t xor32;
	for (size_t index = 0; index < 3; ++index) {
		xor32 = factors[m_num] ^ factors[m_den];
		m_num_factors &= xor32;
		m_den_factors &= xor32;
	}
}

Quot::Quot(uint8_t _num, uint8_t _den)
	: m_num{_num}, m_den{_den}, m_num_factors{factors[m_num]}, m_den_factors{factors[m_den]}
{
	simplify();
}

Quot::Quot()
	: m_num{ 0 }, m_den{ 0 }, m_num_factors{ 0 }, m_den_factors{ 0 }
{
}

Quot& Quot::operator+=(const Quot& _rhs)
{
	this->m_num = this->m_num * _rhs.m_den + _rhs.m_num * this->m_den;
	this->m_den *= _rhs.m_den;
	simplify();
	return (*this);
}

const Quot Quot::operator+(const Quot& _rhs) const
{
	return Quot(*this) += _rhs;
}
