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
	void MapFunctionToInput(Inputs p_eInput, std::function<void()> m_fFunction, bool pressed);

	//Function that maps an input to a key
	void MapInputToKey(sf::Keyboard::Key m_pKey, Inputs p_eInput, bool pressed);

	//Function that runs function from a key and returns whether it succeeded or not
	bool RunFunctionFromInput(Inputs p_eInput, bool pressed);

	//Function that runs function from a key and returns whether it succeeded or not
	bool RunFunctionFromKey(sf::Keyboard::Key m_pKey, bool pressed);

	//Function that sets a input to be the next one rebound to the next key obtained by an event 
	void RebindOnNextKeyEvent(Inputs p_eInput, bool pressed);

private:
	std::map<Inputs, std::function<void()>> m_mPressedInputFunctions;
	std::map<sf::Keyboard::Key, Inputs> m_mPressedKeyBindings;

	std::map<Inputs, std::function<void()>> m_mReleasedInputFunctions;
	std::map<sf::Keyboard::Key, Inputs> m_mReleasedKeyBindings;

	bool m_bRebindMode;

	Inputs m_eRebindInput;
};