#include "city.h"



city::city(const char* name,int population,int cityFoundation)
{
	this->name = new char[strlen(name) + 1];
	this->population = population;
	this->cityFoundation = cityFoundation;
	strcpy_s(this->name, strlen(name) + 1, name);
}

city::city(const city& obj)
{
	this->population = obj.population;
	this->cityFoundation = obj.cityFoundation;

	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

}

city::city(city && obj)
{
	this->population = obj.population;
	this->cityFoundation = obj.cityFoundation;

	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

city::~city()
{
	this->clear();
}

int city::getPopulation() const
{
	return this->population;
}

int city::getYear()const
{
	return this->cityFoundation;
}

char * city::getName()const
{
	return this->name;
}

void city::setPopulation(int x)
{
	this->population = x;

}

void city::setYear(int x)
{
	this->cityFoundation = x;
}

void city::setName(const char * obj)
{
	this->clear();
	this->name = new char[strlen(obj) + 1];
	strcpy_s(this->name, strlen(obj) + 1, obj);
}

void city::print()const
{
	cout << this->name << " " << this->population << " " << this->cityFoundation << endl;
}

void city::clear()
{
	delete[] this->name;
	this->name = nullptr;
}

city& city::operator=(const city & obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->clear();

	if (obj.name == nullptr)
	{
		return *this;
	}

	this->population = obj.population;
	this->cityFoundation = obj.cityFoundation;
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

	return *this;
}

city & city::operator=(city && obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->clear();

	if (obj.name == nullptr)
	{
		return *this;
	}

	this->population = obj.population;
	this->cityFoundation = obj.cityFoundation;
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

	return *this;
}

ostream& operator<<(ostream& os, const city & obj)
{
	obj.print();
	return os;
}

istream & operator>>(istream & is, city & obj)
{
	char name[30];
	cout << "Name?" << endl;
	is >> name;
	obj.setName(name);
	cout << "Foundation year?" << endl;
	int year;
	cin >> year;
	obj.setYear(year);
	cout << "Population?" << endl;
	int pop;
	cin >> pop;
	obj.setPopulation(pop);

	return is;
}
