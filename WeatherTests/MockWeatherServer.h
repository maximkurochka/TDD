#pragma once
#include "pch.h"
#include "IWeatherServer.h"

class MockWeatherServer : public IWeatherServer
{
public:
	MOCK_METHOD(std::string, GetWeather, (const std::string&), (override));
};