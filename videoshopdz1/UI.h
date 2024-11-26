#pragma once
#include<iostream>
#include<vector>
#include"EnterKeyboard.h"
#include"windows.h"
using namespace std;

vector<Genre> genres;
vector<Film> films;
string fileName = "films.txt";
string genreName = "genres.txt";

int ShowMenuFilms()
{
    int command;
    cout << "0. Exit" << endl;
    cout << "1. Enter movies from keyboard" << endl;
    cout << "2. Choose movies from menu file" << endl;
    cout << "3. Enter movies and choose only genres from menu file" << endl;
    cout << "4. Write movies to file" << endl;
    cout << "5. Write genres to file" << endl;
    cout << "6. Search by Name" << endl;
    cout << "7. Search by Genre" << endl;
    cout << "8. Search by Director" << endl;
    cout << "9. Search by Popularity" << endl;
    cout << "10. Print movies" << endl;
    cout << "11. Most popular film in genre" << endl; 
    cout << "12. Author Information" << endl;        
    cin >> command;
    return command;
}


void Start()
{
    int command = -1;
    while (command != 0)
    {
        command = ShowMenuFilms();
        switch (command) {
        case 1: {
            int count;
            Film film;
            cout << "Enter count of movies: "; cin >> count;
            for (int i = 0; i < count; i++) {
                film = EnterFilm();
                films.push_back(film);
            }
            break;
        }
        case 2: {
            vector<Film> filmsFromFile = GetFilms(fileName);
            PrintFilms(filmsFromFile);
            int movie;
            while (movie != 0) {
                cout << "Enter the number of movie to add (0 to stop): "; cin >> movie;
                if (movie > 0) {
                    films.push_back(filmsFromFile[movie - 1]);
                }
            }
            break;
        }
        case 3: {
            int count;
            Film film;
            cout << "Enter count of movies: "; cin >> count;
            for (int i = 0; i < count; i++) {
                film = EnterFilmWOGenre(genres);
                films.push_back(film);
            }
            break;
        }
        case 4: {
            vector<Film> moviesToFile;
            int count;
            Film film;
            cout << "Enter count of movies: "; cin >> count;
            for (int i = 0; i < count; i++) {
                film = EnterFilm();
                moviesToFile.push_back(film);
            }
            WriteFilms(moviesToFile, fileName);
            break;
        }
        case 5: {
            vector<Genre> genresToFile;
            int count;
            Genre genre;
            cout << "Enter count of genres: "; cin >> count;
            for (int i = 0; i < count; i++) {
                genre = EnterGenre();
                genresToFile.push_back(genre);
            }
            WriteGenres(genresToFile, genreName);
            break;
        }
        case 6: {
            cin.ignore();
            string name;
            cout << "Enter movie name: "; getline(cin, name);
            SearchName(films, name);
            break;
        }
        case 7: {
            string genreName;
            cout << "Enter genre name: "; getline(cin, genreName);
            SearchGenre(films, genreName);
            break;
        }
        case 8: {
            string dir;
            cout << "Enter director name: "; getline(cin, dir);
            SearchDir(films, dir);
            break;
        }
        case 9: {
            double pop;
            cout << "Enter popularity rating: "; cin >> pop;
            SearchPop(films, pop);
            break;
        }
        case 10: {
            PrintFilms(films);
            break;
        }
        case 11: {  
            string genreName;
            cout << "Enter genre name to find the most popular film: ";
            cin.ignore();
            getline(cin, genreName);
            SearchMostPopularInGenre(films, genreName);
            break;
        }
        case 12: { 
            Author();
            break;
        }
        default: {
            cout << "Invalid command" << endl;
            break;
        }
        }
    }
}
