#pragma once
#include <string>
#include <vector>
#include "pch.h"
#include "IWeatherClient.h"
#include "IWeatherServer.h"

class WeatherClient	: public IWeatherClient
{
public:
	WeatherClient()
	{
		mTimes.push_back("03:00");
		mTimes.push_back("09:00");
		mTimes.push_back("15:00");
		mTimes.push_back("21:00");
	}

	double GetAverageTemperature(IWeatherServer& server, const std::string& date)
	{
		return CountAverage(server, 
			date,
			static_cast<std::size_t>(Index::Temperature));
	}

	double GetMinimumTemperature(IWeatherServer& server, const std::string& date)
	{
		return GetNumberByCustomComparing(server, 
			date,
			GetMinimum,
			static_cast<std::size_t>(Index::Temperature),
			mMaxValue);
	}

	double GetMaximumTemperature(IWeatherServer& server, const std::string& date)
	{
		return GetNumberByCustomComparing(server,
			date,
			GetMaximum,
			static_cast<std::size_t>(Index::Temperature),
			mMinValue);
	}

	double GetAverageWindDirection(IWeatherServer& server, const std::string& date)
	{
		return CountAverage(server, 
			date, 
			static_cast<std::size_t>(Index::WindDirection));
	}

	double GetMaximumWindSpeed(IWeatherServer& server, const std::string& date)
	{
		return GetNumberByCustomComparing(server,
			date,
			GetMaximum,
			static_cast<std::size_t>(Index::WindSpeed),
			mMinValue);
	}

private:
	std::vector<double> ParseResponse(const std::string& response)
	{
		std::vector<double> vector;
		auto result = make_pair(static_cast<std::size_t>(0), std::string());

		while (result.first != std::string::npos)
		{
			result = Get(result.first, mSeparator, response + mSeparator);
			if (result.first == std::string::npos)
			{
				break;
			}
			vector.push_back(std::stod(result.second));
		}

		return vector;
	}

	std::string CreateRequest(const std::string& date, const std::string& time)
	{
		return std::string(date + mSeparator + time);
	}

	std::pair<std::size_t, std::string> Get(std::size_t from,
		const std::string& element,
		const std::string& response)
	{
		auto finsihElem = response.find(element, from);
		if (finsihElem == std::string::npos)
		{
			return std::make_pair(finsihElem, std::string());
		}

		auto substr = response.substr(from, finsihElem - from);
		return std::make_pair(finsihElem + element.size(), substr);
	}

	double CountAverage(IWeatherServer& server, 
		const std::string& date, 
		std::size_t index)
	{
		double result = 0.0;
		std::string request, response;
		std::vector<double> numbers;

		for (auto time : mTimes)
		{
			request = CreateRequest(date, time);
			response = server.GetWeather(request);
			numbers = ParseResponse(response);

			result += numbers[index];
		}

		return result / mTimes.size();
	}

	double GetNumberByCustomComparing(IWeatherServer& server,
		const std::string& date,
		std::function<double(double, double)> compare,
		std::size_t index,
		double start)
	{
		double result = start;
		std::string request, response;
		std::vector<double> numbers;

		for (auto time : mTimes)
		{
			request = CreateRequest(date, time);
			response = server.GetWeather(request);
			numbers = ParseResponse(response);

			result = compare(result, numbers[index]);
		}

		return result;
	}

private:
	std::function<double(double, double)> GetMaximum = [](double lhs, double rhs)
	{
		return (lhs > rhs) ? lhs : rhs;
	};

	std::function<double(double, double)> GetMinimum = [](double lhs, double rhs)
	{
		return (lhs < rhs) ? lhs : rhs;
	};

	const std::string mSeparator = ";";
	const double mMinValue = -1000.0;
	const double mMaxValue = 1000.0;

	enum Index
	{
		Temperature = 0,
		WindDirection,
		WindSpeed
	};

	std::vector<std::string> mTimes;
};