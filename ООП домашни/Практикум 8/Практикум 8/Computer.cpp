#include "Computer.h"
#include <cstring>
#include <stdexcept>
#pragma warning(disable:4996)

size_t Computer::counter = 1;

void Computer::free()
{
	delete[] brandName;
	delete[] processor;

	brandName = nullptr;
	processor = nullptr;
	video = 0;
	hardDrive = 0;
	weight = 0;
	batteryLife = 0;
	price = 0;
	quantity = 0;
}

void Computer::copyFrom(const Computer& other)
{
	brandName = new char[strlen(other.brandName) + 1];
	strcpy(brandName, other.brandName);

	processor = new char[strlen(other.processor) + 1];
	strcpy(processor, other.processor);

	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	batteryLife = other.batteryLife;
	price = other.price;
	quantity = other.quantity;
}

void Computer::setSerialNumber()
{
	serialNumber = counter++;
}

void Computer::setBrandName(const char* brandName)
{
	if (!brandName)
		throw std::invalid_argument("Empty string given");

	this->brandName = new char[strlen(brandName) + 1];
	strcpy(this->brandName, brandName);
}

void Computer::setProcessor(const char* processor) 
{
	if(!processor)
		throw std::invalid_argument("Empty string given");

	this->processor = new char[strlen(processor) + 1];
	strcpy(this->processor, processor);
}

Computer::Computer()
{
	serialNumber = 0;
	brandName = nullptr;
	processor = nullptr;
	video = 0;
	hardDrive = 0;
	weight = 0;
	batteryLife = 0;
	price = 0;
	quantity = 0;
}

Computer::Computer(const char* brandName, const char* processor, unsigned video, 
	unsigned hardDrive, unsigned weight, unsigned batteryLife, double price)
{
	try
	{
		setBrandName(brandName);
		setProcessor(processor);

		this->video = video;
		this->hardDrive = hardDrive;
		this->weight = weight;
		this->batteryLife = batteryLife;

		setPrice(price);
		setQuantity(quantity);

		setSerialNumber();
	}
	catch(const std::exception& e)
	{
		delete[] brandName;
		delete[] processor;

		throw e;
	}
	
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setPrice(double price)
{
	if (price < 0)
		throw std::invalid_argument("Price can't be bellow zero");

	this->price = price;
}

void Computer::setQuantity(unsigned quantity)
{
	this->quantity = quantity;
}

const char* Computer::getBrandName() const
{
	return brandName;
}

const char* Computer::getProcessor() const
{
	return processor;
}

unsigned Computer::getVideo() const
{
	return video;
}

unsigned Computer::getHardDrive() const
{
	return hardDrive;
}

unsigned Computer::getWeight() const
{
	return weight;
}

unsigned Computer::getBattery() const
{
	return batteryLife;
}

double Computer::getPrice() const
{
	return price;
}

unsigned Computer::getQuantity() const
{
	return quantity;
}

void Computer::addOne()
{
	quantity++;
}

void Computer::buyOne()
{
	quantity--;
}

std::ostream& operator<<(std::ostream& os, const Computer& obj)
{
	os << "Brand name: " << obj.brandName;
	os << "\n\tProcessor: " << obj.processor;
	os << "\n\tVideo: " << obj.video;
	os << "\n\tHard drive: " << obj.hardDrive;
	os << "\n\tWeight: " << obj.weight;
	os << "\n\tBattery life: " << obj.batteryLife;
	os << "\n\tPrice: " << obj.price;
	os << "\n\tQuanity: " << obj.quantity;

	return os;
}
