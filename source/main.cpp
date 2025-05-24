/*
 * main.cpp
 * 
 * Simple solar system simulation.
 * 
 * 16-04-2025 by madpl
 */
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>
#include <string>
#include "defines.hpp"
#include "body.hpp"
#include "myGui.hpp"


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(Width, Height), "Solar System v0.5.0");

	window.setPosition({150, 100});
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, Width, Height));
	view.setCenter(0, 0);

	sf::Texture backgroundTexture;
	if(not backgroundTexture.loadFromFile("./background.jpg"))
	{
		std::cerr << "backgroung loading failed!\n";
		
		return -1;
	}

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setColor(sf::Color(255, 255, 255, 64));

	sf::Vector2u windowSize = window.getSize();
	sf::Vector2u textureSize = backgroundTexture.getSize();

	float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
	float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
	backgroundSprite.setScale(scaleX, scaleY);

	myGui gui(window ,SliderSizeX, SliderSizeY, SliderDistY);

	std::vector<Body> bodies = {
		{"Sun", 1.989e30, {0, 0}, {0, 0}, 12, sf::Color(255, 223, 0)},
		{"Mercury", 3.285e23, {5.7e10, 0}, {0, 4.79e4}, 4, sf::Color(216, 191, 216)},
		{"Venus", 4.867e24, {1.08e11, 0}, {0, 3.5e4}, 6, sf::Color(238, 232, 170)},
		{"Earth", 5.972e24, {1.496e11, 0}, {0, 2.98e4}, 6, sf::Color::Blue},
		{"Mars", 6.39e23, {2.279e11, 0}, {0, 2.41e4}, 5, sf::Color(188, 39, 50)},
		{"Jupiter", 1.898e27, {7.78e11, 0}, {0, 1.31e4}, 10, sf::Color(205, 133, 63)},
		{"Saturn", 5.683e26, {1.433e12, 0}, {0, 9.7e3}, 9, sf::Color(210, 180, 140)},
		{"Uranus", 8.681e25, {2.877e12, 0}, {0, 6.8e3}, 8, sf::Color(73, 216, 230)},
		{"Neptune", 1.024e26, {4.5e12, 0}, {0, 5.4e3}, 8, sf::Color(0, 0, 139)}
	};

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			gui.handleEvent(event);
			
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		float guiZoom = gui.getZoomSlider()->getValue();
		float panX = gui.getPanXSlider()->getValue();
		float panY = gui.getPanYSlider()->getValue();
		double scale = guiZoom * 1e-9;
		view.setCenter(panX, panY);
		window.setView(view);
		
		std::vector<vecDouble_t> accelerations(bodies.size());
		for(size_t i = 0; i < bodies.size(); ++i)
		{
			vecDouble_t acc(0, 0);
			
			for(size_t j = 0; j < bodies.size(); ++j)
			{
				if(i != j)
					acc += computeAccel(bodies[i], bodies[j]);
			}
			
			accelerations[i] = acc;
		}
		
		for(size_t i = 0; i < bodies.size(); ++i)
		{
			bodies[i].getVelocity() += accelerations[i] * TIME_STEP;
			bodies[i].updatePosition();
		}
		
		window.clear(sf::Color(0x80, 0x80, 0x80));
		
		window.setView(window.getDefaultView());
		window.draw(backgroundSprite);
		window.setView(view);
		
		for(auto& body : bodies)
		{
			body.updateShape(scale);
			window.draw(body.getShape());
		}
		
		gui.draw();
		window.display();
	}

	return 0;
}
