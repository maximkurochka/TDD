#pragma once
#include "pch.h"
#include <string>

class IWeatherServer
{
public:
	virtual ~IWeatherServer() { }
	// Returns raw response with weather for the given day and time in request
	virtual std::string GetWeather(const std::string& request) = 0;
};

class MockWeatherServer : public IWeatherServer
{
public:
	MOCK_METHOD(std::string, GetWeather, (const std::string&), (override));
};