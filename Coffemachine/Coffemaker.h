#pragma once
#include "ISourceOfIngredients.h"
#include "MockSourceOfIngredients.h"

enum CupSize
{
	Little = 100,
	Big = 140
};

enum Temperature
{
	Default = 60
};

class Coffemaker
{
public:
	void MakeAmericano(ISourceOfIngredients& sourceOfIngredients, CupSize cupSize)
	{
		sourceOfIngredients.SetCupSize(static_cast<int>(cupSize));
		sourceOfIngredients.AddWater(cupSize / 2, static_cast<int>(Temperature::Default));
		sourceOfIngredients.AddCoffee(cupSize / 3);
	}

	void MakeCappucino(ISourceOfIngredients& sourceOfIngredients, CupSize cupSize)
	{
		sourceOfIngredients.SetCupSize(static_cast<int>(cupSize));
		sourceOfIngredients.AddMilk(cupSize / 3);
		sourceOfIngredients.AddCoffee(cupSize / 3);
		sourceOfIngredients.AddMilkFoam(cupSize / 3);
	}

	void MakeLatte(ISourceOfIngredients& sourceOfIngredients, CupSize cupSize)
	{
		sourceOfIngredients.SetCupSize(static_cast<int>(cupSize));
		sourceOfIngredients.AddMilk(cupSize / 4);
		sourceOfIngredients.AddCoffee(cupSize / 2);
		sourceOfIngredients.AddMilkFoam(cupSize / 4);
	}

	void MakeMarochino(ISourceOfIngredients& sourceOfIngredients, CupSize cupSize)
	{
		sourceOfIngredients.SetCupSize(static_cast<int>(cupSize));
		sourceOfIngredients.AddChocolate(cupSize / 4);
		sourceOfIngredients.AddCoffee(cupSize / 4);
		sourceOfIngredients.AddMilkFoam(cupSize / 4);
	}
};
