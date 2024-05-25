#pragma once
#ifndef BUYPROPERTY_H
#define BUYPROPERTY_H

#include"Property.h"

using namespace std;

class BuyProperty : public Property {
public:
	int minPrice;
	int maxPrice;
	BuyProperty() {
		address = Address();
		numRooms = 0;
		amenities = false;
		minPrice = 0;
		maxPrice = 0;
	}
	BuyProperty(Address ad, int nr, bool amen, int minPr, int maxPr) {
		address = ad;
		numRooms = nr;
		amenities = amen;
		minPrice = minPr;
		maxPrice = maxPr;
	}
	void saveToFile(std::ofstream& outFile) const {
		// Сначала сохраняем адрес
		address.saveToFile(outFile);

		// Записываем остальные данные в файл
		outFile.write(reinterpret_cast<const char*>(&numRooms), sizeof(numRooms));
		outFile.write(reinterpret_cast<const char*>(&amenities), sizeof(amenities));
		outFile.write(reinterpret_cast<const char*>(&minPrice), sizeof(minPrice));
		outFile.write(reinterpret_cast<const char*>(&maxPrice), sizeof(maxPrice));
	}

	void loadFromFile(std::ifstream& inFile) {
		// Сначала загружаем адрес
		address.loadFromFile(inFile);

		// Считываем остальные данные из файла
		inFile.read(reinterpret_cast< char*>(&numRooms), sizeof(numRooms));
		inFile.read(reinterpret_cast< char*>(&amenities), sizeof(amenities));
		inFile.read(reinterpret_cast<char*>(&minPrice), sizeof(minPrice));
		inFile.read(reinterpret_cast<char*>(&maxPrice), sizeof(maxPrice));
	}
};

#endif