#pragma once
#include "IWeatherServer.h"

class IWeatherClient
{
public:
	virtual ~IWeatherClient() { }
	virtual double GetAverageTemperature(IWeatherServer& server, const std::string& date) = 0;
	virtual double GetMinimumTemperature(IWeatherServer& server, const std::string& date) = 0;
	virtual double GetMaximumTemperature(IWeatherServer& server, const std::string& date) = 0;
	virtual double GetAverageWindDirection(IWeatherServer& server, const std::string& date) = 0;
	virtual double GetMaximumWindSpeed(IWeatherServer& server, const std::string& date) = 0;
};