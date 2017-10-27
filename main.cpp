#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
	string courses [12][5];
	bool toggledCourses[12][5];
	
	int cup;
	int course;
	int raceAmount;
	string temp;
	
	ifstream fin;
	fin.open("courses.txt");
	
	for (int i = 0; i < 12; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			fin >> toggledCourses[i][j];
		}
	}
	fin.close();
	
	fin.open("courseNames.txt");
	
	for (int i = 0; i < 12; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			getline(fin, courses[i][j]);
		}
	}
	
	for (int i = 0; i < 12; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			cout << left << setw(20) << courses[i][j] << " : " 
				 << setw(4) << toggledCourses[i][j];				 
		}
		cout << endl;
	}
	
	srand(time(NULL));
	int choice = 0;

	while (	choice != 4)
	{
		cout << "Options:" << endl
			 << "--------" << endl
			 << "1) Run all Cups " << endl
			 << "2) Toggle Races " << endl;
		cin >> choice;
		  printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" );
		
		if (choice == 1)
		{	
			cout << "How Many Races: ";
			cin >> raceAmount;
			cin.ignore();
			cout << "Enter for Next Race " << endl;
			for (int i = 0; i < raceAmount; i ++)
			{
				cup = rand() % 12;
				course = rand() % 4+1;
			
				while( toggledCourses[cup][course] != 1)
				{
					cup = rand() % 12;
					course = rand() % 4;
				}
					cout << courses[cup][0] << " : " 
						 << courses[cup][course];
					getline(cin, temp);
					cout << endl;
				}
			}	
			printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" );
		}
	}
	

