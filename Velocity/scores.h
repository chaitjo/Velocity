//Header file containing function definitions for appending to/diplaying a highscores database.

#ifndef __SOCREBOARD_FUNCTIONS_H_INCLUDED__
#define __SOCREBOARD_FUNCTIONS_H_INCLUDED__

#include <fstream.h>		//Input/Output stream class to operate on files.

#include "vars.h"			//Contains global variables and structure definitions for the player and enemies.

//Function to insert a players record into a .dat file which contains highscores.
void insert(pl record)
{
	ifstream fRead;
	fRead.open("Highscores.dat", ios::binary);

	fRead.seekg(0, ios::end);
	int size= fRead.tellg()/sizeof(player);

	int flag= 1;
	pl temp[10];
	
	fRead.seekg(0, ios::beg);
	for (int count=0; count<(size+1) && (count<10); count++)
	{
		fRead.read((char *)&temp[count], sizeof(player));

		if ((flag==1) && (player.score>temp[count].score))
		{
			temp[count+1]= temp[count];
			temp[count]= player;
			count++;
			flag= 0;
		}
	}

	if (size<10 && flag==1)
		temp[count+1]= player;

	fRead.close();

	ofstream fWrite;
	fWrite.open("Highscores.dat", ios::binary);

	for (count=0; count<size+1 && count<10; count++)
		fWrite.write((char *)&temp[count], sizeof(player));

	fWrite.close();
}

//Function to display highscores from a .dat file.
void displayScores()	
{
	ifstream f;
	f.open("Highscores.dat", ios::binary);

	cout<<endl<<endl<<endl;
	pl temp;
	int count= 1;
	while((f.read((char*)&temp, sizeof(temp))) && count<=10)
		cout<<"\t"<<count++<<". "<<temp.name<<"-> "<<temp.score<<endl;

	f.close();
}

#endif
