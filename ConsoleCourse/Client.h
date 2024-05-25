#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<fstream>

using namespace std;

class Client {
public:
	string name;
	string secondName;
	Client() {
		name = "unknown";
		secondName = "unknown";
	}
	Client(string n, string sn) : name(n), secondName(sn) {}
    void saveToFile(std::ofstream& outFile) const {
        // Записываем длину строк и сами строки в файл
        size_t nameLength = name.size();
        outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        outFile.write(name.c_str(), nameLength);

        size_t secondNameLength = secondName.size();
        outFile.write(reinterpret_cast<const char*>(&secondNameLength), sizeof(secondNameLength));
        outFile.write(secondName.c_str(), secondNameLength);
    }

    void loadFromFile(std::ifstream& inFile) {
        // Считываем длину строк и сами строки из файла
        size_t nameLength, secondNameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* buffer1 = new char[nameLength + 1];
        inFile.read(buffer1, nameLength);
        buffer1[nameLength] = '\0';
        name = std::string(buffer1);
        delete[] buffer1;

        inFile.read(reinterpret_cast<char*>(&secondNameLength), sizeof(secondNameLength));
        char* buffer2 = new char[secondNameLength + 1];
        inFile.read(buffer2, secondNameLength);
        buffer2[secondNameLength] = '\0';
        secondName = std::string(buffer2);
        delete[] buffer2;
    }
};
#endif