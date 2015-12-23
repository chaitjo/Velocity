//Execute this program to create/clear the highscore database file (Highscores.dat).

#include <fstream.h>

void main()
{
	ofstream f;
	f.open("Highscores.dat",ios::trunc);
	f.close();
}
