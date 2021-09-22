#include "pch.h"
#include "MockWeatherServer.h"
#include "WeatherClient.h"

typedef std::vector<std::string> VectorOfStrings;

enum ECall
{
	GetAverageTemperature,
	GetMinimumTemperature,
	GetMaximumTemperature,
	GetAverageWindDirection,
	GetMaximumWindSpeed
};

VectorOfStrings firstSetOfReturnsValue{
	" 1;  2;  0",
	" 1;  4;  6",
	" 2;  0;  3",
	" 0; -2;  9"
};

VectorOfStrings secondSetOfReturnsValue{
	" 5;  -1;   8",
	" 3;   0;   9",
	" 2;  -3;  10",
	"-2;  123; 15"
};

VectorOfStrings thirdSetOfReturnsValue{
	" 28;  180;   5",
	" 10;   0;    6",
	" 20;   0;   10",
	"  2; -180;  -9"
};

class MockWeatherServerMultipleParametersTests :
	public ::testing::TestWithParam<std::tuple<ECall, VectorOfStrings, double>>
{
protected:
	MockWeatherServer mock;
	WeatherClient client;
	VectorOfStrings dates{
		"19.09.2021;03:00",
		"19.09.2021;09:00",
		"19.09.2021;15:00",
		"19.09.2021;21:00"
	};
};

TEST_P(MockWeatherServerMultipleParametersTests, CheckResults)
{
	auto call = std::get<0>(GetParam());
	auto vec = std::get<1>(GetParam());
	auto res = std::get<2>(GetParam());

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(vec[i]));
	}

	switch (call)
	{
	case ECall::GetAverageTemperature:
		EXPECT_EQ(res, client.GetAverageTemperature(mock, "19.09.2021"));
		break;

	case ECall::GetMinimumTemperature:
		EXPECT_EQ(res, client.GetMinimumTemperature(mock, "19.09.2021"));
		break;

	case ECall::GetMaximumTemperature:
		EXPECT_EQ(res, client.GetMaximumTemperature(mock, "19.09.2021"));
		break;

	case ECall::GetAverageWindDirection:
		EXPECT_EQ(res, client.GetAverageWindDirection(mock, "19.09.2021"));
		break;

	case ECall::GetMaximumWindSpeed:
		EXPECT_EQ(res, client.GetMaximumWindSpeed(mock, "19.09.2021"));
		break;
	}
}

INSTANTIATE_TEST_CASE_P(
	MockServerTests,
	MockWeatherServerMultipleParametersTests,
	::testing::Values(
		std::make_tuple(ECall::GetAverageTemperature, firstSetOfReturnsValue, static_cast<double>(1)),
		std::make_tuple(ECall::GetAverageTemperature, secondSetOfReturnsValue, static_cast<double>(2)),
		std::make_tuple(ECall::GetAverageTemperature, thirdSetOfReturnsValue, static_cast<double>(15)),

		std::make_tuple(ECall::GetMinimumTemperature, firstSetOfReturnsValue, static_cast<double>(0)),
		std::make_tuple(ECall::GetMinimumTemperature, secondSetOfReturnsValue, static_cast<double>(-2)),
		std::make_tuple(ECall::GetMinimumTemperature, thirdSetOfReturnsValue, static_cast<double>(2)),

		std::make_tuple(ECall::GetMaximumTemperature, firstSetOfReturnsValue, static_cast<double>(2)),
		std::make_tuple(ECall::GetMaximumTemperature, secondSetOfReturnsValue, static_cast<double>(5)),
		std::make_tuple(ECall::GetMaximumTemperature, thirdSetOfReturnsValue, static_cast<double>(28)),

		std::make_tuple(ECall::GetAverageWindDirection, firstSetOfReturnsValue, static_cast<double>(1)),
		std::make_tuple(ECall::GetAverageWindDirection, secondSetOfReturnsValue, static_cast<double>(29.75)),
		std::make_tuple(ECall::GetAverageWindDirection, thirdSetOfReturnsValue, static_cast<double>(0)),

		std::make_tuple(ECall::GetMaximumWindSpeed, firstSetOfReturnsValue, static_cast<double>(9)),
		std::make_tuple(ECall::GetMaximumWindSpeed, secondSetOfReturnsValue, static_cast<double>(15)),
		std::make_tuple(ECall::GetMaximumWindSpeed, thirdSetOfReturnsValue, static_cast<double>(10))
	)
);