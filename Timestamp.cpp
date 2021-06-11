#pragma once
#include "Timestamp.h"

Timestamp::Timestamp(unsigned long _time){
	this->_time = _time;
}

std::ostream& operator<<(std::ostream& out, const Timestamp& other)
{
	out << other._time;
	return out;
}

std::istream& operator>>(std::istream& in, Timestamp& other)
{
	unsigned long temp;
	in >> temp;
	other.setValue(temp);
	return in;
}

Timestamp& Timestamp::operator+=(const unsigned long seconds) {
	this->setValue(this->getValue() + seconds);
	return *this;
}

Timestamp& Timestamp::operator+(const unsigned long seconds) {
	Timestamp result(*this);
	result += seconds;
	return result;
}

