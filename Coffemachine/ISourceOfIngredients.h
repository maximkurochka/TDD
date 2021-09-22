#pragma once

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