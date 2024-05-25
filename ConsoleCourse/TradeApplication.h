#pragma once
#ifndef TRADEAPPLICATION_H
#define TRADEAPPLICATION_H

#include"SaleApplication.h"
#include"BuyApplication.h"

class TradeApplication : public Project::Application {
public:
	SaleApplication have;
	BuyApplication need;
    TradeApplication() {
        client = Client();
        have = SaleApplication();
        need = BuyApplication();
    }
	TradeApplication(Client cl, SaleApplication SA, BuyApplication BA) {
		client = cl;
		have = SA;
		need = BA;
	}
    void saveToFile(const std::string& filename) const {
        std::ifstream inFile(filename, std::ios::binary);
        size_t numObjects = 0;

        if (inFile.is_open()) {
            inFile.read(reinterpret_cast<char*>(&numObjects), sizeof(numObjects));
            inFile.close();
        }

        numObjects++;

        std::ofstream outFile(filename, std::ios::binary | std::ios::in | std::ios::out);
        if (!outFile.is_open()) {
            outFile.open(filename, std::ios::binary | std::ios::trunc);
            outFile.write(reinterpret_cast<const char*>(&numObjects), sizeof(numObjects));
        }
        else {
            outFile.seekp(0);
            outFile.write(reinterpret_cast<const char*>(&numObjects), sizeof(numObjects));
            outFile.seekp(0, std::ios::end);
        }

        have.saveToFile(outFile);
        need.saveToFile(outFile);
        client.saveToFile(outFile);

        outFile.close();
        std::cout << "Данные успешно сохранены." << std::endl << std::endl;
    }
    void loadFromFile(std::ifstream& inFile) {
        have.loadFromFile(inFile);
        need.loadFromFile(inFile);
        client.loadFromFile(inFile);
    }
    void ViewApplications(int i) {
        std::string result = "          Обмен                            \n";
        result += to_string(i) + ") " + to_string(have.property.numRooms) + "-комнатная. " + to_string(have.property.area) + " М^2." + " Удобства - " + ((have.property.amenities) ? "Есть" : "Нет") + "\n";
        result += "Расположение: Страна - " + have.property.address.country + "  г." + have.property.address.city + "  р-н " + have.property.address.district + "\n";
        result += "Продавец: " + have.client.secondName + " " + have.client.name + " Цена " + to_string(have.property.price) + "р.";
        cout << result << endl << endl;
        result = "";
        result += "             На                            \n";
        result += to_string(i) + ") " + to_string(need.property.numRooms) + "-ккомнатная. " + to_string(need.property.minPrice) + "-" + to_string(need.property.maxPrice) + "р. Удобства - " + ((need.property.amenities) ? "Есть" : "Нет") + "\n";
        result += "Расположение: Страна - " + need.property.address.country + "  г." + need.property.address.city + "  р-н " + need.property.address.district + "\n";
        cout << result << endl << endl;
    }
};


#endif