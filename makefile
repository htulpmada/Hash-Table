all:
	g++ -Wall -std=c++11 Project4.cpp HashTable.h Record.h -o project4

clean:
	rm project4