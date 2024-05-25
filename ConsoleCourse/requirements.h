#ifndef requirements_H
#define requirements_H
#include<string>
using namespace std;

#pragma region SaleRequerments
class SaleRequirements {
public:
	int saleMinPrice = 0;
	int saleMaxPrice = 0;
	int saleNumRooms = 0;
	int saleMinArea = 0;
	int saleMaxArea = 0;
	string SaleCountry = "";
	string SaleCity = "";
	string SaleDistrict = "";
	bool SaleAmenities = false;
};

#pragma endregion
#pragma region BuyRequerments
class BuyRequirements {
	int buyPrice = 0;
	int buyNumRooms = 0;
	string buyCountry = "";
	string buyCity = "";
	string buyDistrict = "";
	bool buyAmenities = false;
};
#pragma endregion
#pragma region TradeRequerments
class TradeRequirements {
	BuyRequirements feature;
	SaleRequirements offer;
};
#pragma endregion

#endif

