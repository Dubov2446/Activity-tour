// FILE: main.cpp
//
// AUTHOR: Josue Lopez
//
// Course/Class: CS302-002
//
// DATE: 6th November 2023
//
// Program: CS302-002-program2
//
// Function(s):
//   void tour_option():
//     - creates nodes with tour as the datatype and allows user to move around
//	 and manipulate the structure (DLL).
//
//   void tour_menu():
//     - provides a menu with options about what they are allowed to choose.
//       Explains to the user what they're options are and how to move around.
//
//   void game_option():
//     - creates nodes with Game as the datatype and allows user to move around
//	 and manipulate the structure (DLL).
//
//   void game_description():
//     - Provides the user with a quick text description about how the game works.
//
//   void easy_question():
//     - Provides the easy question for the game to the user.
//
//   void medium_question():
//     - Provides the medium question for the game to the user.
//
//   void hard_question():
//     - Provides the hard question for the game to the user.
//
//   void movie_option():
//     - creates nodes with Movie as the datatype and allows user to move around
//	 and manipulate the structure (DLL).
//
//   void movie_menu():
//     - provides a menu with options about what they are allowed to choose.
//       Explains to the user what they're options are and how to move around.
//
//   void goodbye_message();
//     - provides the user with a clear message stating the end of the program.
//
//   void print_shopping_bag(const list<string>& shopping_bag);
//     - prints the contents of the users 'shopping bag' when they're in the
//       tour option.
//
//   void activity_choice_menu();
//     - provides the user with the different options and allows them to choose
//       from them (tour, game, or movie).
//
#include "activity.h"
#include "dll.h"

#include <iostream> // cout, endl, cin
#include <list> // list
#include <vector> // vector
#include <string> // string
#include <cstdlib> // rand, srand, null
#include <ctime> // time
#include <algorithm> // generate

void tour_option();
void tour_menu();

void game_option();
void game_description();
void easy_question();
void medium_question();
void hard_question();

void movie_option();
void movie_menu();

void goodbye_message();
void print_shopping_bag(const list<string>& shopping_bag);
void activity_choice_menu();

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::generate;

int main()
{
	srand(time(NULL));
	int choice{int()};

	do
	{
		cout << endl;
		activity_choice_menu();
		cin >> choice;
		cin.ignore(256, '\n');
		cout << endl;

		switch(choice)
		{
			case 1: tour_option();
				break;
			case 2: game_option();
				break;
			case 3:	movie_option();
				break;
			default:
				cout << "Invalid option, try again";
				choice = 0;
				break;
		}
	}
	while(choice < 1 && choice > 3);

	goodbye_message();

	return 0;
}

void tour_menu()
{
	cout << "WELCOME TO TOUR MENU!" << endl;
	cout << "1 - Buy an item at this stop" << endl;
	cout << "2 - Go to next stop" << endl;
	cout << "3 - Got to previous stop" << endl;
	cout << "4 - Get tour info for this spot" << endl;
	cout << "5 - show items bought" << endl;
	cout << "6 - stop tour" << endl;
	return;
}

void tour_option()
{
	Dll<Tour> my_tour;
	list<string> shopping_bag;

	my_tour.tour_create();

	int user_choice{0};
	string item_to_buy{""};

	do
	{
		cout << endl;
		tour_menu();
		cin >> user_choice;
		cin.ignore(256, '\n');

		switch(user_choice)
		{
			case 1:
				cout << endl << "Enter item to buy: ";
				getline(cin, item_to_buy);
				shopping_bag.push_back(item_to_buy);
				cout << endl << "'" << item_to_buy << "'" << " has been bought!";
				break;
			case 2:
				cout << endl;
				if(++my_tour)
					cout << "We have move onto the next stop" << endl;
				else
					cout << "We are already at the last stop" << endl;
				break;
			case 3:
				cout << endl;
				if(--my_tour)
					cout << "We have moved back a stop" << endl;
				else
					cout << "We are already at the first stop" << endl;
				break;
			case 4:
				cout << endl;
				my_tour.display();
				break;
			case 5:
				cout << endl;
				print_shopping_bag(shopping_bag);
				break;
			case 6:
				break;
			default:
				cout << "\nInvalid entry, try again.";
				user_choice = 0;
				break;
		}
		cout << endl;
	}
	while(user_choice != 6);
	return;
}

void game_description()
{
	cout << "WELCOME TO THE GAME!" << endl;
	cout << "Rules are simple. There are 3 levels" << endl;
	cout << "You'll be asked a series of trivia questions";
	cout << " that get progressively harder" << endl;
	cout << "If you get the answer right, you progress to the next level";
	cout << endl << "If you get it wrong you go back a level" << endl;
	cout << "Oh, and there are random boost or traps that can send" << endl;
	cout << "you can back OR forward a level automatically!" << endl;
	return;
}

void game_option()
{
	vector<int> vec(20);
	std::generate(vec.begin(), vec.end(), rand);
	Dll<Game> my_game;
	my_game.game_create();
	cout << endl;
	game_description();
	cout << endl;

	int current_level{1};
	int user_choice{0};
	bool still_playing{true};

	while(still_playing)
	{
		if(current_level == 1)
		{
			easy_question();
			cin >> user_choice;
			cout << endl;
			if(user_choice == 0)
				still_playing = false;
			else if(user_choice == 2)
			{
				if(++my_game)
					cout << "\nCORRECT, MOVE ON TO LVL 2!\n" << endl;
				++current_level;
			}
			else if(user_choice != 0 && user_choice != 2)
				cout << endl << "Wrong answer, try again" << endl;
		}
		else if(current_level == 2)
		{
			medium_question();
			cin >> user_choice;
			if(user_choice == 0)
				still_playing = false;
			else if(user_choice == 1)
			{
				cout << "\nCORRECT, MOVE ON TO LVL 3!\n" << endl;
				++my_game;
				++current_level;
			}
			else if(user_choice != 0 && user_choice != 1)
				cout << endl << "Wrong answer, try again" << endl;
		}
		else if(current_level == 3)
		{
			hard_question();
			cin >> user_choice;
			if(user_choice == 0)
				still_playing = false;
			else if(user_choice == 4)
			{
				cout << "\nYOU DID OMG YOU WON OMG OMG SO IMPRESSIVE\n" << endl;
				still_playing = false;
				++current_level;
			}
			else if(user_choice != 0 && user_choice != 4)
				cout << endl << "Wrong answer, try again" << endl;
		}

		// if random number is even, you go back a lvl, if num is EXACTLY 10 you go up a lvl
		// going up is more rare so less chance of it occuring.

		if(still_playing && current_level == 2)
		{
			if(vec[rand() % vec.size()] % 2 == 0 && --my_game)
			{
				cout << "\nOHH NOO YOU GOT A BOOBYTRAP, go BACK one level....\n";
				cout << endl;
				--current_level;
			}
			else if(vec[rand() % vec.size()] == 10 && ++my_game)
			{
				cout << "\nYOU GOT A POWER BOOST! PROCEED UP A LEVEL!\n" << endl;
				++current_level;
			}
		}
	}
	return;
}

void easy_question()
{
	cout << endl << "QUESTION 1:" << endl;
	cout << "How many bones are there in the human body?" << endl;
	cout << "1 - 210" << endl;
	cout << "2 - 206" << endl;
	cout << "3 - 203" << endl;
	cout << "4 - 213" << endl;
	cout << endl << "0 - to end game" << endl;
	return;
}

void medium_question()
{
	cout << endl << "QUESTION 2:" << endl;
	cout << "What date did Frédéric François Chopin die?" << endl;
	cout << "1 - October 17, 1849" << endl;
	cout << "2 - March 21, 1823" << endl;
	cout << "3 - March 26, 1792" << endl;
	cout << "4 - January 12, 1802" << endl;
	cout << endl << "0 - to end game" << endl;
	return;
}

void hard_question()
{
	cout << endl << "QUESTION 3:" << endl;
	cout << "Who is known for the following quote: " << endl;
	cout << "'It is better to be feared than loved, if you cannot have both'" << endl;
	cout << "1 - Leonardo da Vinci" << endl;
	cout << "2 - Aristotle" << endl;
	cout << "3 - H.P. Lovecraft" << endl;
	cout << "4 - Niccolo Machiavelli" << endl;
	cout << endl << "0 - to end game" << endl;
	return;
}

void movie_menu()
{
	cout << "WELCOME TO MOVIE MARATHON MENU!" << endl;
	cout << "1 - Watch next movie" << endl;
	cout << "2 - Watch previous movie" << endl;
	cout << "3 - Get current movie info" << endl;
	cout << "4 - stop movie watching marathon" << endl;
	return;
}

void movie_option()
{
	Dll<Movie> movie_marathon;

	movie_marathon.movie_create();

	int user_choice{0};

	do
	{
		cout << endl;
		movie_menu();
		cin >> user_choice;
		cin.ignore(256, '\n');

		switch(user_choice)
		{
			case 1:
				if(++movie_marathon)
					cout << "\nYou have moved onto the next movie";
				else
					cout << "\nYou're already watching the last movie";
				cout << endl;
				break;

			case 2:
				if(--movie_marathon)
					cout << "\nYou have gone back to the previous movie";
				else
					cout << "\nYou're already watching the first movie";
				cout << endl;
				break;
			case 3:
				cout << endl << "Current movie: " << endl;
				movie_marathon.display();
				cout << endl;
				break;
			case 4:
				break;
			default:
				cout << "\nInvalid entry, try again...." << endl;
				user_choice = 0;
		}
		cout << endl;
	}
	while(user_choice != 4);

	return;
}

void goodbye_message()
{
	cout << endl << "Your activity has ended. Bye." << endl;
	return;
}

void activity_choice_menu()
{
	cout << endl;
	cout << "Activty menu option" << endl;
	cout << "1 - Tour" << endl;
	cout << "2 - Game" << endl;
	cout << "3 - Movie" << endl;
	return;
}

void print_shopping_bag(const list<string>& shopping_bag)
{
	if(shopping_bag.size() == 0)
	{
		cout << "You haven't bought anything yet....";
		return;
	}

	cout << endl << "Items you've bought: " << endl;
	for(const auto& item : shopping_bag)
		cout << item << endl;
	cout << endl;
	return;
}
