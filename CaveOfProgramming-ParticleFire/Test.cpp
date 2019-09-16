//Using SDL
#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace caveofprogramming;

int main(int argc, char* args[])
{
	srand(time(NULL));
	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing sdl." << endl;
	}

	Swarm swarm;

	while (true) {


		//draw particles.

		int elapsed = SDL_GetTicks();
		screen.clear();
		swarm.update();

		unsigned char green = (1 + sin(elapsed * 0.0001)) * 0.5 * 256;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 0.5 * 256;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 0.5 * 256;
		

		const Particle* const pParticles = swarm.getParticles();
		
		for (int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);

		}

		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();

	return 0;

}