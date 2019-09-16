#pragma once

namespace caveofprogramming {
	class Particle
	{
	public:
		double m_x;
		double m_y;
		double m_xspeed;
		double m_yspeed;
	
		Particle();
		~Particle();
		void update();
	};
}

