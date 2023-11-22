//===========================================================================
// Prog4Main.c
//
// Purpose: Demonstration of programming assignment 4
// Author: Dr. Rick Coleman
//===========================================================================
#include <iostream>
#include <string.h>
#include "GameGraph.h"
using namespace std;

#define DataFile "gamelayout.txt"

void makeUpper(char *line);

//#define GRADING

int main(int argc, char **argv)
{
	GameGraph	*game;
	bool		done = false;
#ifndef GRADING
	char		command[64];
#endif
	double		grade = 0.0;
	double		maxGrade = 0.0;
	char		ans;

	game = new GameGraph();

	cout << "Welcome to the demonstration of Programming Assignment 4\n";
	cout << "for CS 221,  This is a Dungeons and Dragons style role \n";
	cout << "playing game.  At the prompt enter enter your commands.\n\n";

	game->LoadGame(DataFile);	// Load the game
	game->PrintAll();

//	game->describeRoom(0); // Initial description
#ifdef GRADING

//	game->PrintAll();			// Print all info for testing
	cout << "\nDoes print all output look correct (Y or N)?";
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking loadGame = " << grade << " out of " << maxGrade << endl;

	// Test GO EAST - Move from room 0 to room 1
	cout << "\nTesting GO EAST...\n";
	game->doCommand("GO EAST");
	cout << "\nDid you see the description for Room 1 (Statue Room)?\n";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO EAST = " << grade << " out of " << maxGrade << endl;

	// Test GO SOUTH - Move from room 1 to room 4
	cout << "\nTesting GO SOUTH...\n";
	game->doCommand("GO SOUTH");
	cout << "\nDid you see the description for Room 4 (Priest's Quarters)?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO SOUTH = " << grade << " out of " << maxGrade << endl;

	// Test GO UP - Move from room 4 to room 16
	cout << "\nTesting GO UP...\n";
	game->doCommand("GO UP");
	cout << "\nDid you see the description for Room 16 (Chief Mage of Ursamigaras)?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO SOUTH = " << grade << " out of " << maxGrade << endl;

	// Test GO NORTH - Move from room 16 to room 13
	cout << "\nTesting GO NORTH...\n";
	game->doCommand("GO NORTH");
	cout << "\nDid you see the description for Room 13 (Ceremonial Chamber)?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO NORTH = " << grade << " out of " << maxGrade << endl;

	// Test GO WEST - Move from room 13 to room 12
	cout << "\nTesting GO WEST...\n";
	game->doCommand("GO WEST");
	cout << "\nDid you see the description for Room 12 (Grand Master of Gorm)?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO WEST = " << grade << " out of " << maxGrade << endl;

	// Retest GO UP - Move from room 12 to room 18
	cout << "\nCalling GO UP again to position for next test...\n";
	game->doCommand("GO UP");
	cout << "Previous command should move into room 18 (Secret Room)?\n";

	// Test GO DOWN - Move from room 18 to room 12
	cout << "\nTesting GO DOWN...\n";
	game->doCommand("GO DOWN");
	cout << "\nDid you see the description for Room 12 (Grand Master of Gorm)?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 3.0;
	}
	maxGrade += 3.0;
	cout << "Grade after checking GO DOWN = " << grade << " out of " << maxGrade << endl;

	// Test TAKE
	cout << "\nTesting TAKE...\n";
	game->doCommand("TAKE SWORD");
	cout << "\nDid you see a message \"TAKE NOT IMPLEMENTED\"?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 2.0;
	}
	maxGrade += 2.0;
	cout << "Grade after checking TAKE = " << grade << " out of " << maxGrade << endl;

	// Test FIGHT
	cout << "\nTesting FIGHT...\n";
	game->doCommand("FIGHT TROLL");
	cout << "\nDid you see a message \"FIGHT NOT IMPLEMENTED\"?";
	cin.ignore(5, '\n');
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
	{
		grade += 2.0;
	}
	maxGrade += 2.0;
	cout << "Grade after checking FIGHT = " << grade << " out of " << maxGrade << endl;

	cout << "\n\nFinal grade = " << grade << endl;

#else
	while(!done)
	{
	cout << "\n========== Program 4 Demonstration ============\n";
		cout << "What do you want to do?  ";
		cin.getline(command, 64, '\n');
		makeUpper(command);
		cout << "\t" << command << "\n";
		if((game->doCommand(command))) done = true;
	cout << "\n===============================================\n\n";
	}
#endif
	cout << "\nPress the Enter key to terminate this demonstration.\n";
	getchar();
	return 0;
}

//--------------------------------------
// makeUpper()
// Converts input line to all upper case
//--------------------------------------
void makeUpper(char *line)
{
	char *temp;

	temp = line;
	while(*temp != '\0') 
	{
		*temp = toupper(*temp);
		temp++;
	}
}