/*
 * body.cpp
 * 
 * 24-05-2025 by madpl
 */
#include <cmath>
#include "defines.hpp"
#include "body.hpp"


Body::Body(std::string n, double m, vecDouble_t pos,
			vecDouble_t vel, float radius, sf::Color color):
	m_name(n),
	m_mass(m),
	m_position(pos),
	m_velocity(vel)
{
	m_shape.setRadius(radius);
	m_shape.setFillColor(color);
	m_shape.setOrigin(radius, radius);
}


void Body::updatePosition()
{
	m_position += m_velocity * TIME_STEP;
}


void Body::updateShape(double scale)
{
	m_shape.setPosition(m_position.x * scale, m_position.y * scale);
}


double Body::getMass() const
{
	return m_mass;
}


const sf::CircleShape& Body::getShape() const
{
	return m_shape;
}


vecDouble_t& Body::getVelocity() // modyficable
{
	return m_velocity;
}
