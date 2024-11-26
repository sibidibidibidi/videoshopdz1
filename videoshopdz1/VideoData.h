#pragma once
#include <string>
using namespace std;

struct Genre {
	string GenreName;
	int RestrictionsByAge;
};

struct Film {
	string FilmName;
	string Director;
	Genre FilmGenre;
	double Raiting;
	double PriceForDisk;
};