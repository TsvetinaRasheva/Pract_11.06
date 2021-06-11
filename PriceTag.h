#pragma once
#include <iostream>

template<typename T>
class PriceTag {
	T price;
public:
	PriceTag() : price(0) {};
	PriceTag(T _price);

	template<typename T>
	friend std::ostream& operator<<(std::ostream&, const PriceTag<T>&);
	template<typename T>
	friend std::istream& operator>>(std::istream&,  PriceTag<T>&);

	void discount();

	void setPrice(T _p) {
		price = _p;
	}
	T getPrice() const {
		return this->price;
	}
};


template<typename T>
PriceTag<T>::PriceTag(T _price) : price(_price) {}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PriceTag<T>& other) {
	out << other.price;
	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, PriceTag<T>& other) {
	std::cout << "Price is: ";
	T temp;
	in >> temp;
	other.setPrice(temp);
	return in;
}

template<typename T>
void PriceTag<T>::discount() {
	setPrice(getPrice() - (0.20 * getPrice()));
}