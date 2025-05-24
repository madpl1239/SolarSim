/*
 * acceleration.cpp
 * 
 * 24-05-2025 by madpl
 */
#include "acceleration.hpp"


vecDouble_t computeAccel(const Body& a, const Body& b)
{
	vecDouble_t diff = b.m_position - a.m_position;
	double distance = std::hypot(diff.x, diff.y);
	
	if(distance == 0)
		return {0, 0};
	
	double force = G * a.m_mass * b.m_mass / (distance * distance);
	double angle = std::atan2(diff.y, diff.x);
	
	return {force * std::cos(angle) / a.m_mass, force * std::sin(angle) / a.m_mass};
}
