# Velocity
Velocity is a 2D arcade game made in C++ using the graphics.h library. 

Players control a red and blue coloured car dashing through a never ending highway, and must dodge the striped barriers by switching lanes till they eventually crash. A timer is used to calculate the score. To increase difficulty, the ‘velocity’ of the car keeps increasing when it attains scores which are multiples of 25.

This was a project for my highschool CS course. We were restricted to working with the ancient **TurboC++ compiler**, hence some of the code may be redundant now! However, the concepts demonstrated in coding a simple 2D game are still relevant.

**About the files:**
* `main.cpp` : Main driver program to run Velocity.
* `vars.h` : Contains global variables and structure definitions for the player and enemies.
* `gfx.h` : Contains function definitions to generate the game environment.
* `scores.h` : Contains function definitions for appending to/diplaying a highscores database.
* `hs_file.cpp` : Program to create/clear the highscore database file.

# Instructions
1. Place all the files from the Velocity folder into the BIN folder of your local TurboC++ directory.
2. Compile `hs_file.cpp` using TurboC++ to create the empty highscores database file (Compiling it again will clear the highscores in the database).
3. Compile `main.cpp` using TurboC++ to play the game.

# Screenshots
Retro menu/splash screen
![alt tag](https://raw.githubusercontent.com/ckjoshi9/Velocity/master/Screenshots/screenshot1.jpg)

Gameplay screenshot
![alt tag](https://raw.githubusercontent.com/ckjoshi9/Velocity/master/Screenshots/screenshot2.jpg)

Retro game-over screen
![alt tag](https://raw.githubusercontent.com/ckjoshi9/Velocity/master/Screenshots/screenshot3.jpg)

# Features
* The entire game runs during a while loop sequence called the ‘main game loop’. To set the rate at which the screen updates itself, or the frames-per-second (FPS), time delays are used at end of each iteration of the loop.

* The car has a fixed vertical position at the bottom of the screen and can have one of three horizontal positions at the center of each of the lanes. The barricades have a fixed, but randomly selected lane each. They keep progressing vertically downward, giving the illusion that the car is speeding forward. Once a barricade has crossed the car without collision, it is regenerated at the top of a new lane. This process is repeated till the player crashes.

* By seeding the randomization function with the current system time, we ensured that we got completely arbitrary values. These are used to determine the entry lane of each new barricade onto the screen once it has been crossed.

* System time is also used to keep score using a simple timer which increases every second. The number of seconds that have passed since the player started playing is displayed as the player's score. The speed of the car is increased when it attains scores which are multiples of 25 by decreasing the time delays at the end of each iteration of the main game loop.

* A self updating highscores leaderboard is maintained in a binary file. If a new player beats one of the top ten scores, their name is automatically added to an ordered list, the contents of which are displayed after every round of play.

# Authors
* Chaitanya Joshi
* Rachiitesh Kumar
