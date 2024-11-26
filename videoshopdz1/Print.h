#pragma once
#include<iostream>
#include"VideoData.h"
#include<vector>
#include <windows.h>
using namespace std;
void PrintGenres(vector<Genre> genres)
{
	cout << "" << endl;
	for (int i = 0; i < genres.size(); i++)
	{
		cout << i + 1 << ". " << genres[i].GenreName << genres[i].RestrictionsByAge << endl;
	}
	cout << "" << endl;
}
void PrintFilms(vector<Film> films)
{
	cout << "" << endl;
	for (int i = 0; i < films.size(); i++)
	{
		cout << "" << i + 1 << "" << endl;
		cout << " " << films[i].FilmName << endl;
		cout << " " << films[i].Director << endl;
		cout << " " << films[i].FilmGenre.GenreName << endl;
		cout << " " << films[i].FilmGenre.RestrictionsByAge << endl;
		cout << " " << films[i].Raiting << endl;
		cout << " " << films[i].PriceForDisk << " UAH" << endl;
	}
}
void PrintFilm(vector<Film>films, int i) {
	cout << "" << i + 1 << "" << endl;
	cout << " " << films[i].FilmName << endl;
	cout << " " << films[i].Director << endl;
	cout << " " << films[i].FilmGenre.GenreName << endl;
	cout << " " << films[i].FilmGenre.RestrictionsByAge << endl;
	cout << " " << films[i].Raiting << endl;
	cout << " " << films[i].PriceForDisk << " UAH" << endl;
}
