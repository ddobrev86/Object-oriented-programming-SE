#pragma once
#include "Computer.h"

namespace ConfigurationConstants
{
	unsigned const videoConst[4]{ 3060, 3070, 3080, 3090 };
	unsigned const hardDriveConst = 512;
	double const weightConst = 2.5;
	unsigned const batteryLifeConst = 6;
}

class ConsultantUtils
{
private:
	static bool checkProcessor(const Computer& obj);
	static bool checkVideo(const Computer& obj);
	static bool checkHardDrive(const Computer& obj);
	static bool checkWeight(const Computer& obj);
	static bool checkBatteryLife(const Computer& obj);
public:
	static bool isGoodForGaming(const Computer& obj);
	static bool isGoodForTravel(const Computer& obj);
};

