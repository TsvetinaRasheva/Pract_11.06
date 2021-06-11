#pragma once
#include "TimestampWithDescription.h"

void TimestampWithDescription::copy(const TimestampWithDescription& other) {
	size_t sizeD = strlen(other.description) + 1;
	description = new char[sizeD];
	strcpy_s(description, sizeD, other.description);

	_time = other._time;
}

void TimestampWithDescription::clear() {
	delete[] description;
	description = nullptr;

	_time = 0;
}

TimestampWithDescription::TimestampWithDescription() : description(nullptr) {};

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other) {
	copy(other);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other){
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

TimestampWithDescription::~TimestampWithDescription() {
	clear();
}

std::ostream& operator<<(std::ostream& out, const TimestampWithDescription& other)
{ 
	out << other.description << " -> " << other._time;
	return out;
}

std::istream& operator>>(std::istream& in, TimestampWithDescription& other)
{
	std::cout << "desc: ";
	char arr[512];
	in.getline(arr, 512);

	std::cout << "time: ";
	unsigned long temptime;
	in >> temptime;

	other.SetDescription(arr);
	other.setValue(temptime);
	return in;
}
