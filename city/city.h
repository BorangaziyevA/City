#pragma once
#include<iostream>

using namespace std;

class city
{
	char* name ;
	int population;
	int cityFoundation;

public:

	city(const char* name, int population, int cityFoundation);
	city(const city& obj);
	city(city&& obj);
	~city();

	int getPopulation() const;
	int getYear() const;
	char* getName() const;
	void setPopulation(int x);
	void setYear(int x);
	void setName(const char* obj);
	void print() const;
	void clear();

	city& operator=(const city& obj);
	city& operator=(city&& obj);
};

ostream& operator<<(ostream& os, const city& obj);
istream& operator>>(istream& is, city& obj);