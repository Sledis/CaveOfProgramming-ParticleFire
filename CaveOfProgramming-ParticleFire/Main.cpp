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
	const double halfScreenHeight = Screen::SCREEN_HEIGHT / 2;
	const double halfScreenWidth = Screen::SCREEN_WIDTH / 2;

	while (true) {


		//draw particles.

		int elapsed = SDL_GetTicks();
		
		swarm.update(elapsed);

		unsigned char green = 128+(1 + sin(elapsed * 0.00000000001)) * 0.5 * 64;
		unsigned char red = 128+(1 + sin(elapsed * 0.0006)) * 0.5 * 64;
		unsigned char blue = 128+(1 + sin(elapsed * 0.0007)) * 0.5 * 64;
		

		const Particle* const pParticles = swarm.getParticles();
		
		for (int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * halfScreenWidth;
			int y = particle.m_y * halfScreenWidth+halfScreenHeight;

			screen.setPixel(x, y, red, green, blue);

		}
		screen.boxBlur();
		

		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();

	return 0;

}