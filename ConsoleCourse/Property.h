#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H
#include<iostream>
#include"Address.h"

using namespace std;

class Property {
private:

public:
	Address address;
	int numRooms;
	bool amenities;
	Property() {
		address = Address();
		numRooms = 0;
		amenities = false;
	}

	Property(Address ad, int nr, bool amen) {
		address = ad;
		numRooms = nr;
		amenities = amen;
	}



};
#endif