#include "stdafx.h"
#include<iostream>
#include"WeatherDatabase.h"
#include<fstream>
#include<sstream>
using namespace std;

vector<string> File();

int main()
{
	vector<string> test = File();
	vector<Weather_Event> next;
	Weather_Event nu;
	for (int i = 0; i < test.size(); i++)
	{
		if ((test.at(i))[0] == 'C' && (test.at(i)[1] == 'A') && (test.at(i)[2] == 'Z'))
		{
			istringstream CAZID(test.at(i));
			string s, loc;
			bool justTag = true;
			
			while (getline(CAZID, s, ' '))
			{
				int indent = s.size();
				int full = test.at(i).size();
				if (justTag)
				{
					nu.ID = s;
					loc = test.at(i).substr((indent), (full - indent));
					nu.Location = loc;
					next.push_back(nu);
				}
				justTag = false;
			}
		}
	}

	for (int i = 0; i < next.size(); i++)
	{
		cout << next.at(i).ID <<endl<<"At"<<next.at(i).Location <<endl;
	}

	return 0;
}

vector<string> File()
{
	vector<string> Stack;
	string input;
	ifstream infile("data.txt");
	if (!infile)
	{
		cout << "Unable to open data input" << endl;
		return Stack;
	}
	while (getline(infile, input))
	{
		Stack.push_back(input);
	}
	infile.close();
	return Stack;
}
