#pragma once
#include "Timestamp.h"

class TimestampWithDescription : public Timestamp {
	char* description;

	void copy(const TimestampWithDescription&);
	void clear();

public:
	TimestampWithDescription();
	TimestampWithDescription(const TimestampWithDescription&);
	TimestampWithDescription& operator=(const TimestampWithDescription&);
	~TimestampWithDescription();

	friend std::ostream& operator<<(std::ostream&, const TimestampWithDescription&);
	friend std::istream& operator>>(std::istream&, TimestampWithDescription&);

	char* GetDescription() const {
		return this->description;
	}
	void SetDescription(const char* _desc) {
		if (description != nullptr)
		{
			delete[] description;
			description = nullptr;
		}

		description = new char[strlen(_desc) + 1];
		strcpy_s(description, strlen(_desc)+1,_desc);
	}
};