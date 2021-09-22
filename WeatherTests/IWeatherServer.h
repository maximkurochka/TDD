#pragma once
#include <string>

class IWeatherServer
{
public:
	virtual ~IWeatherServer() { }
	// Returns raw response with weather for the given day and time in request
	virtual std::string GetWeather(const std::string& request) = 0;
};