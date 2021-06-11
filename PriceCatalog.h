#pragma once
#include"PriceTag.h"
#include <vector>

template<typename T>
class PriceCatalog {
	std::vector<PriceTag<T>> products;

public:
	PriceCatalog();
	
	PriceCatalog<T> operator+=(const PriceTag<T>&);

	//friend std::ostream& operator<<(std::ostream&, const PriceCatalog<T>&);

};


template<typename T>
PriceCatalog<T>::PriceCatalog() {};

template<typename T>
PriceCatalog<T> PriceCatalog<T>::operator+=(const PriceTag<T>& other) {
	if (products.size() > 200)
	{
		std::cout << " NNo memory!";
		return *this;
	}
	products.push_back(other);
}

//template<typename T>
//std::ostream& operator<<(std::ostream& out, const PriceCatalog<T>& other) {
//	std::cout << "catalog\n";
//	size_t sizeC = other.products.size();
//	for (size_t i = 0; i < sizeC; i++)
//	{
//		std::cout << other.products.at(i).getPrice() << " , ";
//	}
//	return out;
//}
