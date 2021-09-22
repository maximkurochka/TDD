#include "pch.h"
#include "MockWeatherServer.h"
#include "WeatherClient.h"

typedef std::vector<std::string> VectorOfStrings;

class FixturesTest : public ::testing::Test
{
protected:
	MockWeatherServer mock;
	WeatherClient client;
};

TEST_F(FixturesTest, GetAverageTemperaturetWithFirstSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 1;  2;  0"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 1;  4;  6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  0;  3"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return(" 0; -2;  9"));

	EXPECT_EQ(static_cast<double>(1), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetAverageTemperatureWithSecondSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 5;  -1;   8"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 3;   0;   9"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  -3;  10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("-2;  123; 15"));

	EXPECT_EQ(static_cast<double>(2), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetAverageTemperaturetWithThirdSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 28;  180;   5"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 10;   0;    6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 20;   0;   10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("  2; -180;  -9"));

	EXPECT_EQ(static_cast<double>(15), client.GetAverageTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMinimumTemperatureWithFirstSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 1;  2;  0"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 1;  4;  6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  0;  3"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return(" 0; -2;  9"));

	EXPECT_EQ(static_cast<double>(0), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMinimumTemperatureSecondSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 5;  -1;   8"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 3;   0;   9"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  -3;  10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("-2;  123; 15"));

	EXPECT_EQ(static_cast<double>(-2), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMinimumTemperatureWithThirdSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 28;  180;   5"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 10;   0;    6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 20;   0;   10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("  2; -180;  -9"));

	EXPECT_EQ(static_cast<double>(2), client.GetMinimumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumTemperatureWithFirstSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 1;  2;  0"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 1;  4;  6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  0;  3"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return(" 0; -2;  9"));

	EXPECT_EQ(static_cast<double>(2), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumTemperatureWithSecondSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 5;  -1;   8"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 3;   0;   9"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  -3;  10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("-2;  123; 15"));

	EXPECT_EQ(static_cast<double>(5), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumTemperatureWithThirdSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 28;  180;   5"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 10;   0;    6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 20;   0;   10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("  2; -180;  -9"));

	EXPECT_EQ(static_cast<double>(28), client.GetMaximumTemperature(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetAverageWindDirectionWithFirstSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 1;  2;  0"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 1;  4;  6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  0;  3"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return(" 0; -2;  9"));

	EXPECT_EQ(static_cast<double>(1), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetAverageWindDirectionWithSecondSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 5;  -1;   8"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 3;   0;   9"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  -3;  10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("-2;  123; 15"));

	EXPECT_EQ(static_cast<double>(29.75), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetAverageWindDirectionWithThirdSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 28;  180;   5"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 10;   0;    6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 20;   0;   10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("  2; -180;  -9"));

	EXPECT_EQ(static_cast<double>(0), client.GetAverageWindDirection(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumWindSpeedWithFirstSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 1;  2;  0"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 1;  4;  6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  0;  3"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return(" 0; -2;  9"));

	EXPECT_EQ(static_cast<double>(9), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumWindSpeedWithSecondSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 5;  -1;   8"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 3;   0;   9"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 2;  -3;  10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("-2;  123; 15"));

	EXPECT_EQ(static_cast<double>(15), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}

TEST_F(FixturesTest, GetMaximumWindSpeedWithThirdSetOfValues)
{
	EXPECT_CALL(mock, GetWeather("19.09.2021;03:00")).WillOnce(::testing::Return(" 28;  180;   5"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;09:00")).WillOnce(::testing::Return(" 10;   0;    6"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;15:00")).WillOnce(::testing::Return(" 20;   0;   10"));
	EXPECT_CALL(mock, GetWeather("19.09.2021;21:00")).WillOnce(::testing::Return("  2; -180;  -9"));

	EXPECT_EQ(static_cast<double>(10), client.GetMaximumWindSpeed(mock, "19.09.2021"));
}