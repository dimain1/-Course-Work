#pragma once
#ifndef SALEPROPERTY_H
#define SALEPROPERTY_H

#include"Property.h"
#include"fstream"

using namespace std;

class SaleProperty : public Property {
public:
	int area;
	int price;
	SaleProperty() {
		address = Address();
		area = 0;
		numRooms = 0;
		price = 0;
		amenities = false;
	}
	SaleProperty(Address a, int ar, int nr, int pr, bool amen) {
		address = a;
		area = ar;
		numRooms = nr;
		price = pr;
		amenities = amen;
	}
	void saveToFile(std::ofstream& outFile) const {
		// Сначала сохраняем адрес
		address.saveToFile(outFile);

		// Записываем остальные данные в файл
		outFile.write(reinterpret_cast<const char*>(&area), sizeof(area));
		outFile.write(reinterpret_cast<const char*>(&numRooms), sizeof(numRooms));
		outFile.write(reinterpret_cast<const char*>(&price), sizeof(price));
		outFile.write(reinterpret_cast<const char*>(&amenities), sizeof(amenities));
	}

	void loadFromFile(std::ifstream& inFile) {
		// Сначала загружаем адрес
		address.loadFromFile(inFile);

		// Считываем остальные данные из файла
		inFile.read(reinterpret_cast<char*>(&area), sizeof(area));
		inFile.read(reinterpret_cast<char*>(&numRooms), sizeof(numRooms));
		inFile.read(reinterpret_cast< char*>(&price), sizeof(price));
		inFile.read(reinterpret_cast< char*>(&amenities), sizeof(amenities));
	}

};

#endif
