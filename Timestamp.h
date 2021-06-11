#pragma once
#include<cstring>
#include<iostream>

class Timestamp {
protected:
	unsigned long _time;

public:
	Timestamp() :_time(0) {};
	Timestamp(unsigned long _time);

	friend std::ostream& operator<<(std::ostream&, const Timestamp&);
	friend std::istream& operator>>(std::istream&, Timestamp&);

	Timestamp& operator+=(const unsigned long seconds);
	Timestamp& operator+(const unsigned long seconds);


	unsigned long getValue() {
		return _time;
	}

	void setValue(unsigned long _time) {
		this->_time = _time;
	}
};
