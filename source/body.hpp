/*
 * body.hpp
 * 
 * 24-05-2025 by madpl
 */
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "defines.hpp"


class Body
{
public:
	Body(std::string n, double m, vecDouble_t pos,
			vecDouble_t vel, float radius, sf::Color color);
 
	void updatePosition();
	void updateShape(double scale);
	
	// getters
	double getMass() const;
	const sf::CircleShape& getShape() const;
	vecDouble_t& getVelocity();
	
	friend vecDouble_t computeAccel(const Body& a, const Body& b);
	
private:
	sf::CircleShape m_shape;
	std::string m_name;
	double m_mass;
	vecDouble_t m_position;
	vecDouble_t m_velocity;
};
