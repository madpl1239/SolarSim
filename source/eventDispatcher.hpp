/*
 * EventDispatcher.hpp
 * 
 * 17-06-2025 by madpl
 */
#pragma once

#include <SFML/Window/Event.hpp>
#include <functional>
#include <map>
#include <vector>


class EventDispatcher
{
public:
	using Callback_t = std::function<void(const sf::Event&)>;
	
	void subscribe(sf::Event::EventType type, Callback_t callbackFunc)
	{
		m_listeners[type].push_back(std::move(callbackFunc));
	}
	
	void dispatch(const sf::Event& event) const
	{
		auto it = m_listeners.find(event.type);
		
		if(it != m_listeners.end())
		{
			for(const auto& callback : it->second)
				callback(event);
		}
	}
	
private:
	std::map<sf::Event::EventType, std::vector<Callback_t>> m_listeners;
};
