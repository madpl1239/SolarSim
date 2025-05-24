/*
 * myGui.hpp
 *
 * 24-05-2025 by madpl
 */
#pragma once

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>


class myGui
{
public:
	myGui(sf::RenderWindow& window, int sliderSizeX, int sliderSizeY, int sliderDistY);
	~myGui();

	void handleEvent(sf::Event& e);
	void draw();

	tgui::Slider::Ptr getZoomSlider() const;
	tgui::Slider::Ptr getPanXSlider() const;
	tgui::Slider::Ptr getPanYSlider() const;

private:
	tgui::Gui m_gui;
	tgui::Slider::Ptr m_zoomSlider;
	tgui::Slider::Ptr m_panXSlider;
	tgui::Slider::Ptr m_panYSlider;
};
