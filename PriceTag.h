#pragma once
#include <iostream>

template<typename T>
class PriceTag {
	double price;
public:
	PriceTag() :price(0) {};
	PriceTag(double _price);

	friend std::ostream& operator<<(std::ostream&, const PriceTag&);
	friend std::istream& operator>>(std::istream&,  PriceTag&);

	void discount();

	void setPrice(double _p) {
		price = _p;
	}
	double getPrice() const {
		return this->price;
	}
};


template<typename T>
PriceTag<T>::PriceTag(double _price) : price(_price) {}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PriceTag<T>& other) {
	out << "Price is: " << other.price;
	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, PriceTag<T>& other) {
	std::cout << "Price is: ";
	double temp;
	in >> temp;
	other.setPrice(temp);
	return in;
}

template<typename T>
void PriceTag<T>::discount() {
	setPrice(getPrice() + (0.20 * getPrice()));
}