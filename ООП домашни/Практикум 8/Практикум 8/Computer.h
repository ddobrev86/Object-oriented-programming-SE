#pragma once
#include <iostream>

class Computer
{
private:
	static size_t counter;

	size_t serialNumber;
	char* brandName;
	char* processor;
	unsigned video;
	unsigned hardDrive;
	unsigned weight;
	unsigned batteryLife;
	double price;
	unsigned quantity;

	void free();
	void copyFrom(const Computer& other);

	void setSerialNumber();
	void setBrandName(const char* brandName);
	void setProcessor(const char* processor);
	void setPrice(double price);

public:
	Computer();
	Computer(const char* brandName, const char* processor, unsigned video, 
		unsigned hardDrive, unsigned weight, unsigned batteryLife, double price);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();

	void setQuantity(unsigned quantity);
	void addOne();
	void buyOne();

	const char* getBrandName() const;
	const char* getProcessor() const;
	unsigned getVideo() const;
	unsigned getHardDrive() const;
	unsigned getWeight() const;
	unsigned getBattery() const;
	double getPrice() const;
	unsigned getQuantity() const;

	friend std::ostream& operator<<(std::ostream& os, const Computer& obj);

};

