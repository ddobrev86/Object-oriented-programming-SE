#include "ConsultantUtils.h"

bool ConsultantUtils::checkProcessor(const Computer& obj)
{
	return strcmp(obj.getProcessor(), "i5") == 0 ||
		strcmp(obj.getProcessor(), "i7") == 0;
}

bool ConsultantUtils::checkVideo(const Computer& obj)
{
	size_t end = sizeof(ConfigurationConstants::videoConst) / sizeof(unsigned);
	for (size_t i = 0; i < end; i++)
	{
		if (obj.getVideo() == ConfigurationConstants::videoConst[i])
			return true;
	}

	return false;
}

bool ConsultantUtils::checkHardDrive(const Computer& obj)
{
	return obj.getHardDrive() >= ConfigurationConstants::hardDriveConst;
}

bool ConsultantUtils::checkWeight(const Computer& obj)
{
	return obj.getWeight() <= ConfigurationConstants::weightConst;
}

bool ConsultantUtils::checkBatteryLife(const Computer& obj)
{
	return obj.getBattery() > ConfigurationConstants::batteryLifeConst;
}

bool ConsultantUtils::isGoodForGaming(const Computer& obj)
{
	return checkProcessor(obj) && checkHardDrive(obj) && checkVideo(obj);
}

bool ConsultantUtils::isGoodForTravel(const Computer& obj)
{
	return checkBatteryLife(obj) && checkWeight(obj);
}

