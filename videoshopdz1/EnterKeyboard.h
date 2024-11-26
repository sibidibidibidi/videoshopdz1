#pragma once
#include<iostream>
#include<vector>
#include"VideoData.h"
#include"DAL.h"
#include"Print.h"
using namespace std;

Film EnterFilm()
{
	Film film;
	Genre genre;
	cout << " ";
	cin >> film.FilmName;
	cout << " ";
	cin >> film.Director;
	cout << " "; cin >> genre.GenreName;
	cout << " "; cin >> genre.RestrictionsByAge;
	film.FilmGenre = genre;
	cout << " "; cin >> film.Raiting;
	cout << " "; cin >> film.PriceForDisk;
	return film;
}
Genre EnterGenre()
{
	Genre genre;
	cout << " "; cin >> genre.GenreName;
	cout << " "; cin >> genre.RestrictionsByAge;
	return genre;

}
Film EnterFilmWOGenre(vector<Genre> genre) {
	Film film;
	Genre selectedGenre;
	int genrenum;
	cout << " ";
	cin >> film.FilmName;
	cout << " ";
	cin >> film.Director;
	for (int i = 0;i < genre.size();i++) {
		cout << i + 1 << endl;
		cout << genre[i].GenreName << endl;
		cout << genre[i].RestrictionsByAge << endl;
	}
	while (true) {
		cout << "Choose the number of genre: "; cin >> genrenum;
		if (genrenum >= 1 && genrenum <= genre.size()) {
			break;
		}
		else {
			cout << "wrong number, try again" << endl;
			continue;
		}
	}
	selectedGenre = genre[genrenum - 1];
	film.FilmGenre = selectedGenre;
	cout << " "; cin >> film.Raiting;
	cout << " "; cin >> film.PriceForDisk;
	return film;
}