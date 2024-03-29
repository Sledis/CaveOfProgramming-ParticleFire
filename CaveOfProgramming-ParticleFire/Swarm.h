#pragma once

#include "Particle.h"
namespace caveofprogramming {
	class Swarm
	{
	private:
		Particle* m_pParticles;
		int lastTime;
	public:
		Swarm();
		~Swarm();
		void update(int elapsed);
		const static int NPARTICLES = 5000;
		const Particle* const getParticles() { return m_pParticles; };
	};
}
