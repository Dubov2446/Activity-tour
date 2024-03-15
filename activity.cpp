// FILE: activity.cpp
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
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this.
//
// ~Activity():
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you new to set them to their 0 equivalant value(s).
//
// Activity(const Activity& to_copy):
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to now assign them to be able to make a
//    copy of whatever is being passed in.
//
// Activity& operator = (const Activity& to_copy);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to free any memory they are taking or
//    just set them to their default values, whichever is appropriate.
//
// bool operator == (const Activity& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// bool operator != (const Activity& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// friend ostream& operator << (ostream& output, const Activity& to_display);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly display the contents they hold.
//
// friend istream& operator >> (istream& input, Activity& to_input);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly take input for them.
//
// ****** TOUR CLASS ******
//
// Tour();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this.
//
// ~Tour();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you new to set them to their 0 equivalant value(s).
//
// bool operator == (const Tour& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// bool operator != (const Tour& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// friend ostream& operator << (ostream& output, const Tour& to_display);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly display the contents they hold.
//
// friend istream& operator >> (istream& input, Tour& to_input);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly take input for them.
//
// ****** GAME CLASS ******
//
// Game();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this.
//
// ~Game();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you new to set them to their 0 equivalant value(s).
//
// bool operator == (const Game& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// bool operator != (const Game& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// friend ostream& operator << (ostream& output, const Game& to_display);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly display the contents they hold.
//
// friend istream& operator >> (istream& input, Game& to_input);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly take input for them.
//
// ****** MOVIE CLASS ******
//
// Movie();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this.
//
// ~Movie();
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you new to set them to their 0 equivalant value(s).
//
// Movie(const Movie& to_copy);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to now assign them to be able to make a
//    copy of whatever is being passed in.
//
// Movie& operator = (const Movie& to_copy);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to free any memory they are taking or
//    just set them to their default values, whichever is appropriate.
//
// bool operator == (const Movie& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// bool operator != (const Movie& rhs) const;
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly compare their data.
//
// friend ostream& operator << (ostream& output, const Movie& to_display);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly display the contents they hold.
//
// friend istream& operator >> (istream& input, Movie& to_input);
//  - You will need to change if new private member variables are added,
//    otherwise, no maintainance is required for this. If new private member
//    variables are added, you need to properly take input for them.


#include "activity.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//************************ ACTIVITY CLASS PORTION BELOW *****************************

Activity::Activity() : date{nullptr} {}

Activity::~Activity()
{
	if(date)
	{
		delete [] date;
		date = nullptr;
	}
}

Activity::Activity(const Activity& to_copy)
{
	if(to_copy.date)
	{
		date = new char[strlen(to_copy.date) + 1];
		strcpy(date, to_copy.date);
	}
}

Activity& Activity::operator = (const Activity& to_copy)
{
	if(this != &to_copy)
	{
		if(to_copy.date)
		{
			if(date)
				delete [] date;
			date = new char[strlen(to_copy.date) + 1];
			strcpy(date, to_copy.date);
		}
	}
	return *this;
}

bool Activity::operator == (const Activity& rhs) const
{
	if(!rhs.date || !date)
		return false;
	if(strcmp(rhs.date, date) == 0)
		return true;
	return false;
}

bool Activity::operator != (const Activity& rhs) const
{
	if(!rhs.date || !date)
		return false;
	if(strcmp(rhs.date, date) != 0)
		return true;
	return false;
}

ostream& operator << (ostream& output, const Activity& to_display)
{
	if(to_display.date)
		output << to_display.date << " ";
	return output;
}

istream& operator >> (istream& input, Activity& to_input)
{
	string temp{string()};

	cout << "Enter date: ";
	getline(cin, temp);

	if(to_input.date)
		delete [] to_input.date;

	to_input.date = new char[temp.length() + 1];

	strcpy(to_input.date, temp.c_str());

	return input;
}


//************************ TOUR CLASS PORTION BELOW *****************************


Tour::Tour() : location{string()} {}

Tour::~Tour()
{
	location = string();
}

bool Tour::operator == (const Tour& rhs) const
{
	if(location == rhs.location && Activity::operator==(rhs))
		return true;
	return false;
}

bool Tour::operator != (const Tour& rhs) const
{
	if(location != rhs.location && Activity::operator!=(rhs))
		return true;
	return false;
}

ostream& operator << (ostream& output, const Tour& to_display)
{
	output << static_cast<const Activity&> (to_display);
	output << to_display.location << " ";
	return output;
}

istream& operator >> (istream& input, Tour& to_input)
{
	input >> static_cast<Activity&> (to_input);
	cout << "Enter location name: ";
	getline(cin, to_input.location);
	return input;
}


//************************ GAME CLASS PORTION BELOW *****************************


Game::Game() : game_name{string()} {}

Game::~Game()
{
	game_name = string();
}

bool Game::operator == (const Game& rhs) const
{
	if(game_name == rhs.game_name && Activity::operator==(rhs))
		return true;
	return false;
}

bool Game::operator != (const Game& rhs) const
{
	if(game_name != rhs.game_name && Activity::operator!=(rhs))
		return true;
	return false;
}

ostream& operator << (ostream& output, const Game& to_display)
{
	output << static_cast<const Activity&> (to_display);
	output << to_display.game_name << " ";
	return output;
}

istream& operator >> (istream& input, Game& to_input)
{
	input >> static_cast<Activity&> (to_input);
	cout << "Enter Game name: ";
	getline(cin, to_input.game_name);
	return input;
}


//************************ MOVIE CLASS PORTION BELOW *****************************


Movie::Movie() : movie_title{nullptr} {}

Movie::~Movie()
{
	if(movie_title)
	{
		delete [] movie_title;
		movie_title = nullptr;
	}
}

Movie::Movie(const Movie& to_copy) : Activity(to_copy)
{
	if(to_copy.movie_title)
	{
		movie_title = new char[strlen(to_copy.movie_title) + 1];
		strcpy(movie_title, to_copy.movie_title);
	}
}

Movie& Movie::operator = (const Movie& to_copy)
{
	if(this != &to_copy)
	{
		if(to_copy.movie_title)
		{
			if(movie_title)
				delete [] movie_title;

			static_cast<Activity&>(*this) = to_copy;
			movie_title = new char[strlen(to_copy.movie_title) + 1];
			strcpy(movie_title, to_copy.movie_title);
		}
	}
	return *this;
}

bool Movie::operator == (const Movie& rhs) const
{
	if(!movie_title || !rhs.movie_title) // if no valid data, false is returned
		return false;
	if(strcmp(movie_title, rhs.movie_title) == 0 && Activity::operator==(rhs))
		return true;
	return false;
}

bool Movie::operator != (const Movie& rhs) const
{
	if(!movie_title || !rhs.movie_title) // if no valid data, false is returned
		return false;
	if(strcmp(movie_title, rhs.movie_title) != 0 && Activity::operator!=(rhs))
		return true;
	return false;
}

ostream& operator << (ostream& output, const Movie& to_display)
{
	output << static_cast<const Activity&> (to_display);
	if(to_display.movie_title)
		output << to_display.movie_title << " ";
	return output;
}

istream& operator >> (istream& input, Movie& to_input)
{
	input >> static_cast<Activity&> (to_input);
	string temp{string()};

	cout << "Enter movie title: ";
	getline(cin, temp);

	if(to_input.movie_title)
		delete [] to_input.movie_title;

	to_input.movie_title = new char[temp.length() + 1];

	strcpy(to_input.movie_title, temp.c_str());

	return input;
}
