#pragma once
#include<fstream>
#include"VideoData.h"
#include"Print.h"
#include<vector>
#include <iostream>
using namespace std;

void GetGenres(vector<Genre>& genres, string fileName)
{
    if (fileName.length() < 5) return;
    Genre genre;
    ifstream inp(fileName);
    while (inp >> genre.GenreName >> genre.RestrictionsByAge) {
        genres.push_back(genre);
    }
    inp.close();
}

void WriteFilms(const vector<Film>& films, string fileName)
{
    if (fileName.length() < 5) return;
    ofstream out(fileName);
    for (const auto& film : films) {
        out << film.FilmName << endl;
        out << film.Director << endl;
        out << film.FilmGenre.GenreName << endl;
        out << film.FilmGenre.RestrictionsByAge << endl;
        out << film.Raiting << endl;
        out << film.PriceForDisk << endl;
    }
    out.close();
}

void WriteGenres(const vector<Genre>& genres, string fileName)
{
    if (fileName.length() < 5) return;
    ofstream out(fileName);
    for (const auto& genre : genres) {
        out << genre.GenreName << endl;
        out << genre.RestrictionsByAge << endl;
    }
    out.close();
}

vector<Film> GetFilms(string fileName)
{
    vector<Film> films;
    if (fileName.length() < 5) return films;
    ifstream inp(fileName);
    Film film;
    Genre genre;
    while (inp >> film.FilmName >> film.Director >> genre.GenreName >> genre.RestrictionsByAge >> film.Raiting >> film.PriceForDisk) {
        film.FilmGenre = genre;
        films.push_back(film);
    }
    inp.close();
    return films;
}

void SearchName(const vector<Film>& films, const string& name) {
    bool exists = false;
    for (size_t i = 0; i < films.size(); ++i) {
        if (films[i].FilmName == name) {
            PrintFilm(films, i);
            exists = true;
        }
    }
    if (!exists) {
        cout << "Movie doesn't exist" << endl;
    }
}

void SearchGenre(const vector<Film>& films, const string& genrename) {
    bool exists = false;
    for (size_t i = 0; i < films.size(); ++i) {
        if (films[i].FilmGenre.GenreName == genrename) {
            PrintFilm(films, i);
            exists = true;
        }
    }
    if (!exists) {
        cout << "No films found in this genre." << endl;
    }
}

void SearchDir(const vector<Film>& films, const string& dir) {
    bool exists = false;
    for (size_t i = 0; i < films.size(); ++i) {
        if (films[i].Director == dir) {
            PrintFilm(films, i);
            exists = true;
        }
    }
    if (!exists) {
        cout << "No films found for this director." << endl;
    }
}

void SearchPop(const vector<Film>& films, double pop) {
    bool exists = false;
    for (size_t i = 0; i < films.size(); ++i) {
        if (films[i].Raiting == pop) {
            PrintFilm(films, i);
            exists = true;
        }
    }
    if (!exists) {
        cout << "No films found with this rating." << endl;
    }
}

void SearchMostPopularInGenre(const vector<Film>& films, const string& genreName) {
    Film mostPopular;
    bool found = false;
    double highestRating = -1.0;

    for (size_t i = 0; i < films.size(); ++i) {
        if (films[i].FilmGenre.GenreName == genreName) {
            if (films[i].Raiting > highestRating) {
                highestRating = films[i].Raiting;
                mostPopular = films[i];
                found = true;
            }
        }
    }
    if (found) {
        PrintFilm(films, find(films.begin(), films.end(), mostPopular) - films.begin());
    }
    else {
        cout << "No films found in this genre." << endl;
    }
}
void Author()
{
    cout << "Program Developer Information:" << endl;
    cout << "Name: Mariia Krysa" << endl;
    cout << "Email: mariya.orestivna@gmail.com" << endl;
    cout << "GitHub: https://github.com/sibidibidibidi" << endl;
}