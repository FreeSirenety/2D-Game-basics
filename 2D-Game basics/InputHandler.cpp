#include "InputHandler.h"

InputHandler::InputHandler()
{
	m_bRebindMode = false;
}

//Function that maps a function to an defined input
void InputHandler::MapFunctionToInput(Inputs p_eInput, std::function<void()> m_fFunction, bool pressed)
{

	if (pressed)
	{
		std::pair<Inputs, std::function<void()>> pair(p_eInput, m_fFunction);

		auto it = m_mPressedInputFunctions.find(p_eInput);

		if (it != m_mPressedInputFunctions.end())
		{
			m_mPressedInputFunctions.erase(it);
		}

		m_mPressedInputFunctions.insert(pair);
	}
	else
	{
		std::pair<Inputs, std::function<void()>> pair(p_eInput, m_fFunction);

		auto it = m_mReleasedInputFunctions.find(p_eInput);

		if (it != m_mReleasedInputFunctions.end())
		{
			m_mReleasedInputFunctions.erase(it);
		}

		m_mReleasedInputFunctions.insert(pair);
	}
}

//Function that maps an input to a key
void InputHandler::MapInputToKey(sf::Keyboard::Key m_pKey, Inputs p_eInput, bool pressed)
{
	if (pressed)
	{
		std::pair<sf::Keyboard::Key, Inputs> pair(m_pKey, p_eInput);

		auto it = m_mPressedKeyBindings.find(m_pKey);

		if (it != m_mPressedKeyBindings.end())
		{
			m_mPressedKeyBindings.erase(it);
		}

		m_mPressedKeyBindings.insert(pair);
	}
	else
	{
		std::pair<sf::Keyboard::Key, Inputs> pair(m_pKey, p_eInput);

		auto it = m_mReleasedKeyBindings.find(m_pKey);

		if (it != m_mReleasedKeyBindings.end())
		{
			m_mReleasedKeyBindings.erase(it);
		}

		m_mReleasedKeyBindings.insert(pair);
	}
}

//Function that runs function from a key and returns whether it succeeded or not
bool InputHandler::RunFunctionFromInput(Inputs p_eInput, bool pressed)
{
	if (pressed)
	{
		auto it = m_mPressedInputFunctions.find(p_eInput);

		if (it != m_mPressedInputFunctions.end())
		{
			it->second();

			return true;
		}
	}
	else
	{
		auto it = m_mReleasedInputFunctions.find(p_eInput);

		if (it != m_mReleasedInputFunctions.end())
		{
			it->second();

			return true;
		}
	}

	return false;
}

//Function that runs function from a key and returns whether it succeeded or not
bool InputHandler::RunFunctionFromKey(sf::Keyboard::Key m_pKey, bool pressed)
{
	if (pressed)
	{
		if (m_bRebindMode)
		{
			MapInputToKey(m_pKey, m_eRebindInput, pressed);

			m_bRebindMode = false;

			return false;
		}

		auto it = m_mPressedKeyBindings.find(m_pKey);

		if (it != m_mPressedKeyBindings.end())
		{
			auto it2 = m_mPressedInputFunctions.find(it->second);

			if (it2 != m_mPressedInputFunctions.end())
			{
				it2->second();

				return true;
			}
		}
	}
	else
	{
		if (m_bRebindMode)
		{
			MapInputToKey(m_pKey, m_eRebindInput, pressed);

			m_bRebindMode = false;

			return false;
		}

		auto it = m_mReleasedKeyBindings.find(m_pKey);

		if (it != m_mReleasedKeyBindings.end())
		{
			auto it2 = m_mReleasedInputFunctions.find(it->second);

			if (it2 != m_mReleasedInputFunctions.end())
			{
				it2->second();

				return true;
			}
		}
	}
	return false;
}

//Function that sets a input to be the next one rebound to the next key obtained by an event 
void InputHandler::RebindOnNextKeyEvent(Inputs p_eInput, bool pressed)
{
	m_bRebindMode = true;

	m_eRebindInput = p_eInput;
}