#pragma once

#include "SFML/Graphics.hpp"
#include <functional>
#include <map>

class InputHandler
{
public:
	enum Inputs
	{
		FORWARD,
		BACKWARDS,
		LEFT,
		RIGHT
	};

public:
	InputHandler();

	//Function that maps a function to an defined input
	void MapFunctionToInput(Inputs p_eInput, std::function<void()> m_fFunction);

	//Function that maps an input to a key
	void MapInputToKey(sf::Keyboard::Key m_pKey, Inputs p_eInput);

	//Function that runs function from a key and returns whether it succeeded or not
	bool RunFunctionFromInput(Inputs p_eInput);

	//Function that runs function from a key and returns whether it succeeded or not
	bool RunFunctionFromKey(sf::Keyboard::Key m_pKey);

	//Function that sets a input to be the next one rebound to the next key obtained by an event 
	void RebindOnNextKeyEvent(Inputs p_eInput);

private:
	std::map<Inputs, std::function<void()>> m_mInputFunctions;
	std::map<sf::Keyboard::Key, Inputs> m_mKeyBindings;

	bool m_bRebindMode;

	Inputs m_eRebindInput;
};