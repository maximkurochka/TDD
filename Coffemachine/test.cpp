#include "pch.h"
#include "ISourceOfIngredients.h"
#include "MockSourceOfIngredients.h"
#include "Coffemaker.h"

TEST(Americano, MakeLittleCupOfAmericano)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddWater(cupSize / 2, Temperature::Default));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));

	coffemaker.MakeAmericano(mock, static_cast<CupSize>(cupSize));
}

TEST(Americano, MakeBigCupOfAmericano)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Big);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddWater(cupSize / 2, static_cast<int>(Temperature::Default)));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));

	coffemaker.MakeAmericano(mock, static_cast<CupSize>(cupSize));
}

TEST(Cappucino, MakeLittleCupOfCappucino)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 3));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 3));

	coffemaker.MakeCappucino(mock, static_cast<CupSize>(cupSize));
}

TEST(Cappucino, MakeBigCupOfCappucino)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Big);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 3));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 3));

	coffemaker.MakeCappucino(mock, static_cast<CupSize>(cupSize));
}

TEST(Latte, MakeLittleCupOfLatte)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 2));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	coffemaker.MakeLatte(mock, static_cast<CupSize>(cupSize));
}

TEST(Latte, MakeBigCupOfLatte)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Big);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 2));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	coffemaker.MakeLatte(mock, static_cast<CupSize>(cupSize));
}

TEST(Marochino, MakeLittleCupOfMarochino)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddChocolate(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 4));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	coffemaker.MakeMarochino(mock, static_cast<CupSize>(cupSize));
}

TEST(Marochino, MakeBigCupOfMarochino)
{
	Coffemaker coffemaker;
	MockSourceOfIngredients mock;
	testing::InSequence seq;
	auto cupSize = static_cast<int>(CupSize::Big);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddChocolate(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 4));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	coffemaker.MakeMarochino(mock, static_cast<CupSize>(cupSize));
}
