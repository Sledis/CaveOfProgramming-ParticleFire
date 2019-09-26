#include "Particle.h"
#include <stdlib.h>;
#include <time.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
namespace caveofprogramming {
	Particle::Particle():m_x(0), m_y(0){
		m_direction = (((double)rand() / RAND_MAX))*2*M_PI;
		m_speed = 0.04 * rand() / RAND_MAX;
		
		m_speed *= m_speed;
		time_t timer;
		birth = time(&timer);
	}

	void Particle::init() {
		m_x=(0);
		m_y=(0);
		m_direction = (((double)rand() / RAND_MAX)) * 2 * M_PI;
		m_speed = 0.04 * rand() / RAND_MAX;
		time_t timer;
		birth = time(&timer);
		m_speed *= m_speed;
	}


	Particle::~Particle(){}

	void Particle::update(int interval) {
		time_t timer2;
		time(&timer2);
		double excessLife = difftime(timer2, birth) - 10;
		if (excessLife > 0) {
			if (rand() < (RAND_MAX*excessLife )/300) {
				m_x = -1;
				m_y = -1;
				m_speed = 0;
				
			}
		}

		m_direction += interval * 0.00005*(excessLife);

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;

		if ((m_x < -1 || m_x>1 || m_y < -1 || m_y>1)) {
			//init();
		}
		//else if ((m_x < -1 || m_x>1 || m_y < -1 || m_y>1) && rand() > RAND_MAX / 10) {
			//m_speed = 0;
		//}
		if (rand() < RAND_MAX / 250) {
			init();
		}
	}
}
