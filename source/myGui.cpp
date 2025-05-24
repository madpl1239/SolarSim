 /*
  * myGui.hpp
  *
  * 24-05-2025 by madpl
  */
#include "myGui.hpp"


myGui::myGui(sf::RenderWindow& window, int SliderSizeX, int SliderSizeY, int SliderDistY):
	m_gui(window)
{
	// GUI sliders
	m_zoomSlider = tgui::Slider::create(0.05f, 0.5f);
	m_zoomSlider->setPosition(20, 20);
	m_zoomSlider->setSize(SliderSizeX, SliderSizeY);
	m_zoomSlider->setStep(0.05f);
	m_zoomSlider->setMinimum(0.1f);
	m_zoomSlider->setMaximum(2.0f);
	m_zoomSlider->setValue(0.2f);
	m_zoomSlider->getRenderer()->setTrackColor(tgui::Color(80, 80, 80));
	m_zoomSlider->getRenderer()->setTrackColorHover(tgui::Color(110, 110, 110));
	m_zoomSlider->getRenderer()->setThumbColor(tgui::Color(255, 0, 0, 150));
	m_zoomSlider->getRenderer()->setThumbColorHover(tgui::Color(255, 0, 0, 100));
	m_zoomSlider->getRenderer()->setBorderColor(tgui::Color(0, 0, 0));
	m_gui.add(m_zoomSlider, "zoomSlider");
	
	m_panXSlider = tgui::Slider::create(-800, 800);
	m_panXSlider->setPosition(20, 60 + SliderDistY);
	m_panXSlider->setSize(SliderSizeX, SliderSizeY);
	m_panXSlider->setValue(0);
	m_panXSlider->setStep(10.0f);
	m_panXSlider->getRenderer()->setTrackColor(tgui::Color(80, 80, 80));
	m_panXSlider->getRenderer()->setTrackColorHover(tgui::Color(110, 110, 110));
	m_panXSlider->getRenderer()->setThumbColor(tgui::Color(0, 255, 0, 150));
	m_panXSlider->getRenderer()->setBorderColor(tgui::Color(0, 0, 0));
	m_panXSlider->getRenderer()->setThumbColorHover(tgui::Color(0, 255, 0, 100));
	m_gui.add(m_panXSlider, "panXSlider");
	
	m_panYSlider = tgui::Slider::create(-450, 450);
	m_panYSlider->setPosition(20, 100 + SliderDistY * 2);
	m_panYSlider->setSize(SliderSizeX, SliderSizeY);
	m_panYSlider->setValue(0);
	m_panYSlider->setStep(10.0f);
	m_panYSlider->getRenderer()->setTrackColor(tgui::Color(80, 80, 80));
	m_panYSlider->getRenderer()->setTrackColorHover(tgui::Color(110, 110, 110));
	m_panYSlider->getRenderer()->setThumbColor(tgui::Color(0, 0, 255, 150));
	m_panYSlider->getRenderer()->setThumbColorHover(tgui::Color(0, 0, 255, 100));
	m_panXSlider->getRenderer()->setBorderColor(tgui::Color(0, 0, 0));
	m_gui.add(m_panYSlider, "panYSlider");
}


myGui::~myGui()
{
	m_gui.removeAllWidgets();
}


void myGui::handleEvent(sf::Event& e)
{
	m_gui.handleEvent(e);
}


void myGui::draw()
{
	m_gui.draw();
}


tgui::Slider::Ptr myGui::getZoomSlider() const
{
	return m_zoomSlider;
}


tgui::Slider::Ptr myGui::getPanXSlider() const
{
	return m_panXSlider;
}


tgui::Slider::Ptr myGui::getPanYSlider() const
{
	return m_panYSlider;
}
