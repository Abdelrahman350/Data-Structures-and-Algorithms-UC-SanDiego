/*
 * networkSimulation.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: Abdelrahman
 */


#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long int ulint;
class Packet;

class Packet{
public:
	ulint A; // The arrival time
	ulint P; // The processing time

	Packet(){ // Default constructor
		A = 0;
		P = 0;
	}
	Packet(ulint x, ulint y){ // Parameterized constructor
		A = x;
		P = y;
	}
};

class Request{
private:
	std::vector <Packet> R;
	ulint numberPackets;
public:
	Request(){
		numberPackets = 0;
	}
	Request(ulint x){
		numberPackets = x;
	}
	void readRequest(){

		R.resize(numberPackets);
		for(ulint i = 0; i < numberPackets; ++i){
			Packet temp;
			std::cin >> temp.A;
			std::cin >> temp.P;
			R.push_back(temp);
		}
	}
};

int main(){
	ulint bufferSize = 0;
	ulint numberPackets = 0;

	std::cin >> bufferSize;
	std::cin >> numberPackets;

	Request request(numberPackets);
	request.readRequest();

}


