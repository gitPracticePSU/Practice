/*This is assignment 3 for Karla Fant's CS 163 online section by Colleen Toth due on 11/12/2013. This program requires
us to manage a music library using hash tables inorder to insert, remove, display, and create a table among other data structures.
The table will be implemented using chaining, ie an array of linked lists, with a has function of our own design to map each item to 
a location. We are to monitor collisions (keeping in mind that we should strive to have as few collisions as possible, while still being practical
with available memory). The table as well as linear linked lists, and arrays will be used in this program.This is the main function file (Toth_Colleen-Assignment3_main.cpp) 
and contains the "client" (in this case out test) program to call the function and be used for testing. it includes the library file (Toth_Colleen-Assignment3.h).

INPUT:
OUTPUT:  */

//**************************************************************************************************************************************************************************************


#include "Toth_Colleen-Assignment3.h"



int main ()
{
	//Variable definitions:
	int choice;
	char temp_name[SIZE];
	char temp_album[SIZE];
	char * temp_songs[SIZE];
	char temp_playlist[SIZE];
	char temp_length[SIZE];
	int num_of_songs;
	music artist;
	table hash_table;
	int result;
	
	welcome();
	
	
	do
	{
		choice = menu();
	
		if (choice == 1)
		{
			get_artist_info(temp_name, temp_album, temp_songs, temp_playlist, temp_length, num_of_songs);
			result = hash_table.add(temp_name, temp_album, temp_songs, temp_playlist, temp_length, num_of_songs);
			if (result == 0)
				cout << endl << "Could not add artist. Please try again." << endl << endl;
			else
				cout << endl << "Artist successfully added" << endl << endl;
		
		}
		if (choice == 2)
		{
			cout  << endl << endl << "Please enter the name of the artist you'd like to remove" << endl;
			cin.get(temp_name, SIZE, '\n');
			cin.ignore(100,'\n');
			result = hash_table.remove(temp_name);
			if (result == 0)
				cout << endl << endl << "Artist not found. Please try again" << endl;
			
		}	
		if (choice == 3)
		{
			cout  << endl << endl << "Please enter the name of the artist you'd like to display." << endl;
			cin.get(temp_name, SIZE, '\n');
			cin.ignore(100,'\n');
			result = hash_table.find(temp_name);
			if (result == 0)
				cout << endl << endl << "Artist not found. Please try again" << endl << endl;
		}
		if (choice == 4)
		{
			result = hash_table.display();
			if (result == 0)
				cout << endl << "There are no artists in your Music Library. Please add an artist." << endl << endl;
			
		}
		
	
	}
	while (choice != 5);
	






return 0;
}





