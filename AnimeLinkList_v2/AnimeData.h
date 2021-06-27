#ifndef ANIMEDATA 
#define ANIMEDATA
#include <iostream>
using namespace std;

class AnimeData
{
	private:
		string title;
		int rating;
	public: 
		AnimeData(string, int);
		string getTitle();
		int getRating();
};

#endif 
