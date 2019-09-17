#pragma once

namespace caveofprogramming {
	class Particle
	{
	public:
		double m_x;
		double m_y;
		double m_speed;
		double m_direction;
	
		Particle();
		~Particle();
		void update(int interval);
		void init();
		double birth;
	};
}

