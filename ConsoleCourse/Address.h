#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class Address {
public:

	string country;
	string city;
	string district;

	Address() {
		country = "Russia";
		city = "Moscov";
		district = "Moscov City";
	}

	Address(string cont, string c, string dist) {
		country = cont;
		city = c;
		district = dist;
	}
    void saveToFile(std::ofstream& outFile) const {
        // Записываем длину строк и сами строки в файл
        size_t countryLength = country.size();
        outFile.write(reinterpret_cast<const char*>(&countryLength), sizeof(countryLength));
        outFile.write(country.c_str(), countryLength);

        size_t cityLength = city.size();
        outFile.write(reinterpret_cast<const char*>(&cityLength), sizeof(cityLength));
        outFile.write(city.c_str(), cityLength);

        size_t districtLength = district.size();
        outFile.write(reinterpret_cast<const char*>(&districtLength), sizeof(districtLength));
        outFile.write(district.c_str(), districtLength);
    }

    void loadFromFile(std::ifstream& inFile) {
        // Считываем длину строк и сами строки из файла
        size_t countryLength, cityLength, districtLength;
        inFile.read(reinterpret_cast<char*>(&countryLength), sizeof(countryLength));
        char* buffer1 = new char[countryLength + 1];
        inFile.read(buffer1, countryLength);
        buffer1[countryLength] = '\0';
        country = std::string(buffer1);
        delete[] buffer1;

        inFile.read(reinterpret_cast<char*>(&cityLength), sizeof(cityLength));
        char* buffer2 = new char[cityLength + 1];
        inFile.read(buffer2, cityLength);
        buffer2[cityLength] = '\0';
        city = std::string(buffer2);
        delete[] buffer2;

        inFile.read(reinterpret_cast<char*>(&districtLength), sizeof(districtLength));
        char* buffer3 = new char[districtLength + 1];
        inFile.read(buffer3, districtLength);
        buffer3[districtLength] = '\0';
        district = std::string(buffer3);
        delete[] buffer3;
    }
};
#endif