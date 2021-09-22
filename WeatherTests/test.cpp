#include "pch.h"
#include "MockWeatherServer.h"
#include "WeatherClient.h"

typedef std::vector<std::string> VectorOfStrings;

VectorOfStrings dates{
	"19.09.2021;03:00",
	"19.09.2021;09:00",
	"19.09.2021;15:00",
	"19.09.2021;21:00"
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

TEST(GetAverageTemperature, CheckResultWithFirstSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(firstSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(1), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST(GetAverageTemperature, CheckResultWithSeconfSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(secondSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(2), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST(GetAverageTemperature, CheckResultWithThirdSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(thirdSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(15), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST(GetMinimumTemperature, CheckResultWithFirstSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(firstSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(0), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST(GetMinimumTemperature, CheckResultWithSeconfSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(secondSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(-2), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST(GetMinimumTemperature, CheckResultWithThirdSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(thirdSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(2), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST(GetMaximumTemperature, CheckResultWithFirstSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(firstSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(2), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST(GetMaximumTemperature, CheckResultWithSeconfSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(secondSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(5), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST(GetMaximumTemperature, CheckResultWithThirdSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(thirdSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(28), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST(GetAverageWindDirection, CheckResultWithFirstSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(firstSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(1), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST(GetAverageWindDirection, CheckResultWithSeconfSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(secondSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(29.75), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST(GetAverageWindDirection, CheckResultWithThirdSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(thirdSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(0), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST(GetMaximumWindSpeed, CheckResultWithFirstSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(firstSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(9), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}

TEST(GetMaximumWindSpeed, CheckResultWithSeconfSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(secondSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(15), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}

TEST(GetMaximumWindSpeed, CheckResultWithThirdSetOfValues)
{
	MockWeatherServer mock;
	WeatherClient client;

	EXPECT_CALL(mock, GetWeather(testing::_)).Times(4);
	for (std::size_t i = 0; i < dates.size(); i++)
	{
		ON_CALL(mock, GetWeather(dates[i])).WillByDefault(testing::Return(thirdSetOfReturnsValue[i]));
	}

	EXPECT_EQ(static_cast<double>(10), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}