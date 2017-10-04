#ifndef LIST
#define LIST
#include <string>
#include<vector>
using namespace std;

struct Weather_Event
{
	string ID;
	string Location;
	string Description;
};

class WeatherDatabase
{
private:
	vector <Weather_Event> The_Stack;
public:
	void Print_Database();
	bool SearchLocation(string loc);
};




#endif