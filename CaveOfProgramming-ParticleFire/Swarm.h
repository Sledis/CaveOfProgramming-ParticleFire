#pragma once

#include "Particle.h"
namespace caveofprogramming {
	class Swarm
	{
	private:
		Particle* m_pParticles;
	public:
		Swarm();
		~Swarm();
		void update();
		const static int NPARTICLES = 1000;
		const Particle* const getParticles() { return m_pParticles; };
	};
}
