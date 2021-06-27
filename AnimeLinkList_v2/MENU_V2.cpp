#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <istream>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include "AnimeData.h"/*this is for the constructor for title and rating and also
						 class for being able to be safe*/

using namespace std;
list <AnimeData> animeList;
string username = "" ;
string fileName = "";	// file name must be updated locally in each function


void add()// to add the input (rating , title name) to the user data
{
    string title;
    int rating;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //

    cout << "Please enter series title.\n";
    getline(cin, title);
    cout << "Please input rating (out of 5).\n";
    cin >> rating;

    AnimeData tempdata(title, rating);
    animeList.push_back(tempdata);
    system("cls");
}

void save()// each user have their own file, exp name.txt that will store (title name, rating)
{
	fileName = "User_data\\" + username + ".txt";
	ofstream regfile(fileName);
	list<AnimeData>::iterator it;
	for (it = animeList.begin(); it != animeList.end(); ++it){
		regfile << it->getTitle() <<","<< it->getRating() << endl;
	}
	regfile.close();	
}

void show() // showing the list that the user have made
{
	list<AnimeData>::iterator it;
	for (it = animeList.begin(); it != animeList.end(); ++it){
		cout << it->getTitle() <<","<< it->getRating() << endl;
	}
}

void load() // to load the data that are inside their respestive file and load it into the terminal
{
	fileName = "User_data\\" + username + ".txt";
	string text;
	ifstream ReadFile(fileName);
		while(getline (ReadFile,text))
		{	
			vector <string> tokens;
		    stringstream check1(text); // stringstream class check1
		    string intermediate;
		    
		    string temparr[] = {"","","0"};
		    int i = 0;
		    while(getline(check1, intermediate, ','))// Tokenizing w.r.t. space ' '
		    {
		        tokens.push_back(intermediate);
		        temparr[i] = intermediate;
		        i++;
		    }
			
			int rating = stoi(temparr[2]);	// convert from string to int
			AnimeData tempdata(temparr[0], rating);
			animeList.push_back (tempdata);	
		}
	ReadFile.close();
}

void delete_series() // searching the specific series(Need to match the same name)
{
	string seriesTitle;
	bool found = false;
	cout << "Which series title do you want to delete? " << endl;
	cin >> seriesTitle;
	
	list<AnimeData>::iterator it;
	
	for (it = animeList.begin(); it != animeList.end(); ++it)
	{
		if(it->getTitle() == seriesTitle)
		{
			it = animeList.erase(it);
			found = true;
			break;
		}
	}
	if (found == false)
	{
		cout << "The series title was not found :( "  << endl;
	}
	else
	{
		cout << "The series title has been deleted " << endl;
	}
}



/* Menu, this is the terminal gui menu using a while loop and also switchoice */
Menu()
{
	int choice;
	bool Open = true;
	
	load();
	
	while (Open != false){
	cout << "Welcome to Anime Linked-list\n";
	cout << "*******************************\n";
	cout << " 1 - Rate a series.\n";
	cout << " 2 - Delete rating.\n";
	cout << " 3 - Show your list.\n";
	cout << " 4 - Exit.\n";
	cout << " Enter your choice and press return: ";
	cin >> choice;
	switch (choice)
	{
		// This case switch is for the user to pick the menu choice //
		
		case 1:
			add();	// case 1 is for the user to add Title and Rating to the Data.txt //
			break;
		case 2:
			delete_series();
			break;
		case 3:
			show();
			cout << "*******************************\n";
			break;
			// case 3 is for the user to be able to see their ratings in the Data.txt //
		case 4:
			save();
			cout << "Thank you for using Anime Linked-list.\n";
			Open = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
	}
}
return 0;
}

//this is for the login part
login() // checking the inside of user.txt to see if the input match wiht the data//
//if the input doesnt match, the user name will be insert into the user.txt//
{
	int exist;
	string input,u;
	system("cls");
	cout << "Enter a username: ";
	cin >> input;
	username = input ;
	// this is for checking the user exist or no
	ifstream infile("User.txt", ios::app);
	while(infile >> u)//checking if the user exist or not
	{
		if(u == input)
		{
			exist = 1;
		}
	}
	infile.close();
	// it to go to the menu
	if(exist == 1)//if exist dont need to rewrite
	{
		Menu();
	}
	//this is for the user to register
	else // this is to add the user.
	{
		ofstream reg("User.txt", ios::app);
		reg << input << endl;
		system("cls");
		Menu();
	}
}

int main(){// start the program
	login();
}


