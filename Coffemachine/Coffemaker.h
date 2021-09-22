#pragma once
#include "pch.h"

typedef int grams;

enum CupSize
{
	Little = 100,
	Big = 140
};

enum Temperature
{
	Default = 60
};

class ISourceOfIngredients
{
public:
	virtual ~ISourceOfIngredients() {}
	virtual void SetCupSize(int gram) = 0;
	virtual void AddWater(int gram, int temperature) = 0;
	virtual void AddSugar(int gram) = 0;
	virtual void AddCoffee(int gram) = 0;
	virtual void AddMilk(int gram) = 0;
	virtual void AddMilkFoam(int gram) = 0;
	virtual void AddChocolate(int gram) = 0;
	virtual void AddCream(int gram) = 0;
};

class MockCoffemaker : public ISourceOfIngredients
{
public:
	MOCK_METHOD(void, SetCupSize, (grams gram), (override));
	MOCK_METHOD(void, AddWater, (grams gram, int temperature), (override));
	MOCK_METHOD(void, AddSugar, (grams gram), (override));
	MOCK_METHOD(void, AddCoffee, (grams gram), (override));
	MOCK_METHOD(void, AddMilk, (grams gram), (override));
	MOCK_METHOD(void, AddMilkFoam, (grams gram), (override));
	MOCK_METHOD(void, AddChocolate, (grams gram), (override));
	MOCK_METHOD(void, AddCream, (grams gram), (override));

public:
	void MakeAmericano(CupSize cupSize)
	{
		SetCupSize(static_cast<int>(cupSize));
		AddWater(cupSize / 2, Temperature::Default);
		AddCoffee(cupSize / 3);
	}

	void MakeCappucino(CupSize cupSize)
	{
		SetCupSize(static_cast<int>(cupSize));
		AddMilk(cupSize / 3);
		AddCoffee(cupSize / 3);
		AddMilkFoam(cupSize / 3);
	}

	void MakeLatte(CupSize cupSize)
	{
		SetCupSize(static_cast<int>(cupSize));
		AddMilk(cupSize / 4);
		AddCoffee(cupSize / 2);
		AddMilkFoam(cupSize / 4);
	}

	void MakeMarochino(CupSize cupSize)
	{
		SetCupSize(static_cast<int>(cupSize));
		AddChocolate(cupSize / 4);
		AddCoffee(cupSize / 4);
		AddMilkFoam(cupSize / 4);
	}
};
