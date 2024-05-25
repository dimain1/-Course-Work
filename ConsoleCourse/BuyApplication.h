#pragma once
#ifndef BUYAPPLICATION_H
#define BUYAPPLICATION_H
#include<fstream>
#include"Application.h"
#include"BuyProperty.h"

using namespace std;

class BuyApplication : public Project::Application
{

public:
    BuyProperty property;
    BuyApplication() {
        client = Client();
        property = BuyProperty();
    }
    BuyApplication(Client c, BuyProperty p) {
        client = c;
        property = p;
    }
    void saveToFile(const std::string& filename) const {
        // Проверка, существует ли файл
        std::ifstream inFile(filename, std::ios::binary);
        size_t numObjects = 0;

        if (inFile.is_open()) {
            inFile.read(reinterpret_cast<char*>(&numObjects), sizeof(numObjects));
            inFile.close();
        }

        numObjects++; // Увеличиваем количество объектов

        // Теперь открываем файл для записи и перезаписываем количество объектов
        std::ofstream outFile(filename, std::ios::binary | std::ios::in | std::ios::out);
        if (!outFile.is_open()) {
            // Если файл не существует, создаем его и записываем начальное количество объектов
            outFile.open(filename, std::ios::binary | std::ios::trunc);
            outFile.write(reinterpret_cast<const char*>(&numObjects), sizeof(numObjects));
        }
        else {
            // Перезаписываем количество объектов
            outFile.seekp(0);
            outFile.write(reinterpret_cast<const char*>(&numObjects), sizeof(numObjects));
            outFile.seekp(0, std::ios::end);
        }

        // Записываем данные экземпляра класса SaleApplication в файл
        property.saveToFile(outFile);
        client.saveToFile(outFile);

        outFile.close();
        std::cout << "Данные успешно сохранены." << std::endl << std::endl;
    }
    void saveToFile( std::ofstream& outFile) const {
        property.saveToFile(outFile);
        client.saveToFile(outFile);

    }
    void loadFromFile(std::ifstream& inFile) {
        property.loadFromFile(inFile);
        client.loadFromFile(inFile);
    }
    void viewApplications(int i) {
        string result = to_string(i) + ") " + to_string(property.numRooms) + "-к. " + to_string(property.minPrice) + "-" + to_string(property.maxPrice) + "р." + "\n";
        result += "Расположение: " + property.address.country + "  г." + property.address.city + "  р-н " + property.address.district + "\n";
        result += "Покупатель: " + client.secondName + " " + client.name;
        cout << result << endl << endl;
    }
};


#endif
