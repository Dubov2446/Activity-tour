// FILE: activity.h
//
// AUTHOR: Josue Lopez
//
// Course/Class: CS302-002
//
// DATE: 6th November 2023
//
// Program: CS302-002-program2
//
// ****** ACTIVITY CLASS ******
// Activity():
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating an Activity object and passing in
//     no values to the constructor.
//
// ~Activity():
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//
// Activity(const Activity& to_copy):
//   - Copy constructor that accepts a previously existing Activity object
//     as an argument, and creates a copy of it.
//
// Activity& operator = (const Activity& to_copy);
//   - Copy assignment operator that accepts a previously existing Activity object
//     as an argument and creates a copy of it. Use it if you want to create a copy,
//     but beware this will delete all data in object you're copy to.
//
// bool operator == (const Activity& rhs) const;
//   - Use to compare if two Activity objects are the same by comparing the data
//     in each and seeing if they're the same.
//
// bool operator != (const Activity& rhs) const;
//   - Use to compare if two Activity objects are not the same by comparing the date
//     in each and seeing if they're different.
//
// friend ostream& operator << (ostream& output, const Activity& to_display);
//   - Use to output data of an Activity object. cout << my_activity;
//
// friend istream& operator >> (istream& input, Activity& to_input);
//   - Use to input data to an Activity object. cin >> my_activity;
//
// ****** TOUR CLASS ******
//
// Tour();
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating a Tour object and passing in
//     no values to the constructor.
//
// ~Tour();
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//
// bool operator == (const Tour& rhs) const;
//   - Use to compare if two Tour objects are the same by comparing the data
//     in each and seeing if they're the same.
//
// bool operator != (const Tour& rhs) const;
//   - Use to compare if two Tour objects are not the same by comparing the date
//     in each and seeing if they're different.
//
// friend ostream& operator << (ostream& output, const Tour& to_display);
//   - Use to output data of a Tour object. cout << my_tour;
//
// friend istream& operator >> (istream& input, Tour& to_input);
//   - Use to input data of a Tour object. cin >> my_tour;
//
// ****** GAME CLASS ******
//
// Game();
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating a Game object and passing in
//     no values to the constructor.
//
// ~Game();
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//
// bool operator == (const Game& rhs) const;
//   - Use to compare if two Game objects are the same by comparing the data
//     in each and seeing if they're the same.
//
// bool operator != (const Game& rhs) const;
//   - Use to compare if two Game objects are not the same by comparing the date
//     in each and seeing if they're different.
//
// friend ostream& operator << (ostream& output, const Game& to_display);
//   - Use to output data of a Game object. cout << my_game;
//
// friend istream& operator >> (istream& input, Game& to_input);
//   - Use to input data to a Game object. cin >> my_game;
//
// ****** MOVIE CLASS ******
//
// Movie();
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating a Movie object and passing in
//     no values to the constructor.
//
// ~Movie();
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//
// Movie(const Movie& to_copy);
//   - Copy constructor that accepts a previously existing Activity object
//     as an argument, and creates a copy of it.
//
// Movie& operator = (const Movie& to_copy);
//   - Copy assignment operator that accepts a previously existing Movie object
//     as an argument and creates a copy of it. Use it if you want to create a copy,
//     but beware this will delete all data in object you're copy to.
//
// bool operator == (const Movie& rhs) const;
//   - Use to compare if two Movie objects are the same by comparing the data
//     in each and seeing if they're the same.
//
// bool operator != (const Movie& rhs) const;
//   - Use to compare if two Movie objects are not the same by comparing the date
//     in each and seeing if they're different.
//
// friend ostream& operator << (ostream& output, const Movie& to_display);
//   - Use to output data of a Movie object. cout << my_movie;
//
// friend istream& operator >> (istream& input, Movie& to_input);
//   - Use to input data to a Movie object. cin >> my_movie;

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <string>

using namespace std;

class Activity
{
	public:
		Activity();
		~Activity();

		Activity(const Activity& to_copy);
		Activity& operator = (const Activity& to_copy);

		// member functions and operators
		bool operator == (const Activity& rhs) const;
		bool operator != (const Activity& rhs) const;

		friend ostream& operator << (ostream& output, const Activity& to_display);
		friend istream& operator >> (istream& input, Activity& to_input);
	private:
		char* date;
};


class Tour : public Activity
{
	public:
		Tour();
		~Tour();

		bool operator == (const Tour& rhs) const;
		bool operator != (const Tour& rhs) const;

		friend ostream& operator << (ostream& output, const Tour& to_display);
		friend istream& operator >> (istream& input, Tour& to_input);
	private:
		string location;
};


class Game : public Activity
{
	public:
		Game();
		~Game();

		bool operator == (const Game& rhs) const;
		bool operator != (const Game& rhs) const;

		friend ostream& operator << (ostream& output, const Game& to_display);
		friend istream& operator >> (istream& input, Game& to_input);
	private:
		string game_name;
};


class Movie : public Activity
{
	public:
		Movie();
		~Movie();
		Movie(const Movie& to_copy);
		Movie& operator = (const Movie& to_copy);

		// member functions and operators below
		bool operator == (const Movie& rhs) const;
		bool operator != (const Movie& rhs) const;

		friend ostream& operator << (ostream& output, const Movie& to_display);
		friend istream& operator >> (istream& input, Movie& to_input);
	private:
		char* movie_title;
};

#endif // ACTIVITY_H
