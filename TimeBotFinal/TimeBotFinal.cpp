// TimeBotFinal.cpp : Defines the entry point for the console application.
//
//all the items to be included from the visual studio presets/library
#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <windows.h>

//using namespace std
using namespace std;
//declare the functions to be used
string askText(string prompt);
void numberOfTimesRun(int*const numberOfTimesRunOne, int*const numberOfTimesRunTwo);

//void initializing the wait and seconds functions
void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLK_TCK;
	while (clock() < endwait) {}
}

//main program
int main()
{
	//initializing and setting all variables and ints
	int timesUsed = 0;
	int timesLeftInOneDay = 96;
	int time = 100;
	int n;
	string userName = "";
	string& name = userName;
	//asking the user to enter their name
	userName = askText("Please enter your name: ");

	//write out they story/explain the reason for the program
	//displays what the program is meant to do and a little explanation of the reason why
	//that fits the backstory
	speak("Welcome to the Time Lord Protocals user " + name + ".");
	speak("This resulted from the research that stated that the more you sit the faster you will die.");
	speak("You can find this research and more similar posts by searching Your Chair is Killing You in a googly search bar.");
	speak("This resulted in the creation of a 15 minute timer that will prompt the user to get up and move every 15 minutes.");
	speak("This also results in " + name + " gaining the opportunity to give the progam a try");
	speak("to see if the difference between moving around every 15 minutes and sitting all day can actually make a difference.");
	speak("\nWould you like to run the Time Lord Protocals Y/N\n");
	//pauses the system so the user can read the vabove printouts and choose to continue or not
	system("pause");
	{
		//if y is pressed do the following
		if (GetAsyncKeyState('Y'))
		{
		start:
			//display the number of times the program has been ran in this instance
			//and how many more times it cam be ran before it has been on for 24 hours
			speak("Calling number of times run and number of times left till it has run for 24 hours");
			numberOfTimesRun(&timesUsed, &timesLeftInOneDay);
			speak("\nNumber of times run:  ");
			printf("%d", timesLeftInOneDay);
			speak("\nNumber of times left till it has run for 24 hours:  ");
			printf("%d", timesUsed);

			//displays the amount of seconds till time to walk
			speak("\nSeconds until time to get up an walk for a bit.\n");
			//as long as n is more the 0 it will run the timer
			for (n = 900; n > 0; n--)
			{
				printf("%d seconds left ", n);
				wait(1);
			}
			//displays the text prompting the user to take a walk so that they don't die/be out of shape
			speak("\nTake a brief hike so that you don't die!!!!!");
			//adds one to the times used and removes one from the 24 hour timer
			--timesLeftInOneDay;
			++timesUsed;
			//pauses the system so the user can take a walk and then start the program again or exit the program
			system("pause");
			//Move program execution back up to // Display the simulation # is staring to the recruit. 
			goto start;
		}
		//if any other key is typed in then Y it will exit the program
		if (GetAsyncKeyState('N')) {
			// Otherwise 
			return 0;
		}
	}
	//{
	//	int move_on;
	//	printf("Press enter to continue.");
	//	move_on = getchar();
	//	return(0);
	//}

	return 0;
}
