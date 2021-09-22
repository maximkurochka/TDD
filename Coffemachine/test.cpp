#include "pch.h"
#include "Coffemaker.h"

const grams SizeOfAntyhing = 50;

TEST(CheckWorkingOfMockingMethods, SetCupSize)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, SetCupSize(testing::_));
	mock.SetCupSize(CupSize::Little);
}

TEST(CheckWorkingOfMockingMethods, AddWater)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddWater(testing::_, testing::_));
	mock.AddWater(SizeOfAntyhing, Temperature::Default);
}

TEST(CheckWorkingOfMockingMethods, AddSugar)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddSugar(testing::_));
	mock.AddSugar(SizeOfAntyhing);
}

TEST(CheckWorkingOfMockingMethods, AddCoffee)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddCoffee(testing::_));
	mock.AddCoffee(SizeOfAntyhing);
}

TEST(CheckWorkingOfMockingMethods, AddMilk)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddMilk(testing::_));
	mock.AddMilk(SizeOfAntyhing);
}

TEST(CheckWorkingOfMockingMethods, AddMilkFoam)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddMilkFoam(testing::_));
	mock.AddMilkFoam(SizeOfAntyhing);
}

TEST(CheckWorkingOfMockingMethods, AddCream)
{
	MockCoffemaker mock;
	EXPECT_CALL(mock, AddCream(testing::_));
	mock.AddCream(SizeOfAntyhing);
}

TEST(Americano, MakeAmericano)
{
	MockCoffemaker mock;
	testing::InSequence seq;
	auto cupSize = static_cast<grams>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddWater(cupSize / 2, Temperature::Default));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));

	mock.MakeAmericano(static_cast<CupSize>(cupSize));
}

TEST(Cappucino, MakeCappucino)
{
	MockCoffemaker mock;
	testing::InSequence seq;
	auto cupSize = static_cast<grams>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 3));
	EXPECT_CALL(mock, AddCoffee(cupSize / 3));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 3));

	mock.MakeCappucino(static_cast<CupSize>(cupSize));
}

TEST(Latte, MakeLatte)
{
	MockCoffemaker mock;
	testing::InSequence seq;
	auto cupSize = static_cast<grams>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddMilk(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 2));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	mock.MakeLatte(static_cast<CupSize>(cupSize));
}

TEST(Marochino, MakeMarochino)
{
	MockCoffemaker mock;
	testing::InSequence seq;
	auto cupSize = static_cast<grams>(CupSize::Little);

	EXPECT_CALL(mock, SetCupSize(cupSize));
	EXPECT_CALL(mock, AddChocolate(cupSize / 4));
	EXPECT_CALL(mock, AddCoffee(cupSize / 4));
	EXPECT_CALL(mock, AddMilkFoam(cupSize / 4));

	mock.MakeMarochino(static_cast<CupSize>(cupSize));
}
