#pragma once
#include "Timestamp.h"

class TimestampWithDescription : public Timestamp
{
private:
	char* description;

	void free();
	void copyFrom(const TimestampWithDescription& other);
	void moveFrom(TimestampWithDescription&& other);

public:
	TimestampWithDescription();
	TimestampWithDescription(unsigned timestamp, const char* desc);
	TimestampWithDescription(const TimestampWithDescription& other);
	TimestampWithDescription& operator=(const TimestampWithDescription& other);
	TimestampWithDescription(TimestampWithDescription&& other) noexcept;
	TimestampWithDescription& operator=(TimestampWithDescription&& other) noexcept;
	~TimestampWithDescription();

	void setDescription(const char* description);
	const char* getDescription() const;

	friend std::istream& operator>>(std::istream& is, TimestampWithDescription& timestamp);
	friend std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& timestamp);
};

