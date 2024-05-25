#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include<iostream>
#include"Client.h"

using namespace std;
namespace Project {

	class Application {
	public:
		Client client;
		string transactionType;
		Application() {
			client = Client();
			transactionType = "unknown";
		}
		Application(Client cl, string tt) {
			client = cl;
			transactionType = tt;
		}

	};
}
#endif
