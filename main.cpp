#pragma once
#include "TimestampWithDescription.h"
#include "Timestamp.h"
#include "PriceCatalog.h"

int main() {
	
	Timestamp obj = Timestamp();
	std::cin >> obj;
	std::cout << obj;
	std::cout << std::endl;

	obj += 2000;

	std::cout << obj;
	std::cout << std::endl;

	Timestamp obj1 = Timestamp();
	obj1 = obj + 2000;

	std::cout << obj1;
	std::cout << std::endl;

	std::cin.ignore();

	TimestampWithDescription timeD = TimestampWithDescription();
	std::cin >> timeD;
	std::cout << timeD;
	std::cout << std::endl;
	

	/*PriceTag<int> prT = PriceTag<int>(200);
	PriceTag<int> prT1 = PriceTag<int>(12.25);
	PriceTag<int> prT2 = PriceTag<int>(11);*/


//	PriceCatalog<PriceTag<int>> catalog = PriceCatalog<PriceTag<int>>();
	//catalog += prT;
	//catalog += prT1;
	//catalog += prT2;

	//std::cout << catalog;

	return 0;
}