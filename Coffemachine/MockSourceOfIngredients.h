#pragma once
#include "pch.h"
#include "ISourceOfIngredients.h"

class MockSourceOfIngredients : public ISourceOfIngredients
{
public:
	MOCK_METHOD(void, SetCupSize, (int gram), (override));
	MOCK_METHOD(void, AddWater, (int gram, int temperature), (override));
	MOCK_METHOD(void, AddSugar, (int gram), (override));
	MOCK_METHOD(void, AddCoffee, (int gram), (override));
	MOCK_METHOD(void, AddMilk, (int gram), (override));
	MOCK_METHOD(void, AddMilkFoam, (int gram), (override));
	MOCK_METHOD(void, AddChocolate, (int gram), (override));
	MOCK_METHOD(void, AddCream, (int gram), (override));
};