#include "AnimeData.h"

AnimeData::AnimeData(string j , int k)
{
	title = j;
	rating = k;
} 

string AnimeData::getTitle()
{
	return title;
}

int AnimeData::getRating()
{
	return rating;
}

