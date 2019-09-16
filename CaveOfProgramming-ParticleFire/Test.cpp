//Using SDL
#include <iostream>
#include <SDL.h>
#include "Screen.h"
using namespace std;
using namespace caveofprogramming;

int main(int argc, char* args[])
{
	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing sdl" << endl;
	}

	
	screen.setPixel(400, 300, 255, 255, 255);
	
	screen.update();



	while (true) {



		if (screen.processEvents() == false) {
			break;
		}
	}



	
	screen.close();

	return 0;

}