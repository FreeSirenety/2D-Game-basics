#include "InputHandler.h"

InputHandler::InputHandler()
{
	m_bRebindMode = false;
}

//Function that maps a function to an defined input
void InputHandler::MapFunctionToInput(Inputs p_eInput, std::function<void()> m_fFunction)
{

	//if (m_fFunction != NULL && p_eInput != NULL)
	{
		std::pair<Inputs, std::function<void()>> pair(p_eInput, m_fFunction);

		auto it = m_mInputFunctions.find(p_eInput);

		if (it != m_mInputFunctions.end())
		{
			m_mInputFunctions.erase(it);
		}

		m_mInputFunctions.insert(pair);
	}
}

//Function that maps an input to a key
void InputHandler::MapInputToKey(sf::Keyboard::Key m_pKey, Inputs p_eInput)
{
	//if (m_pKey != NULL && p_eInput != NULL)
	{
		std::pair<sf::Keyboard::Key, Inputs> pair(m_pKey, p_eInput);

		auto it = m_mKeyBindings.find(m_pKey);

		if (it != m_mKeyBindings.end())
		{
			m_mKeyBindings.erase(it);
		}

		m_mKeyBindings.insert(pair);
	}
}

//Function that runs function from a key and returns whether it succeeded or not
bool InputHandler::RunFunctionFromInput(Inputs p_eInput)
{
	auto it = m_mInputFunctions.find(p_eInput);

	if (it != m_mInputFunctions.end())
	{
		it->second();

		return true;
	}

	return false;
}

//Function that runs function from a key and returns whether it succeeded or not
bool InputHandler::RunFunctionFromKey(sf::Keyboard::Key m_pKey)
{
	if (m_bRebindMode)
	{
		MapInputToKey(m_pKey, m_eRebindInput);

		m_bRebindMode = false;

		return false;
	}

	auto it = m_mKeyBindings.find(m_pKey);

	if (it != m_mKeyBindings.end())
	{
		auto it2 = m_mInputFunctions.find(it->second);

		if (it2 != m_mInputFunctions.end())
		{
			it2->second();

			return true;
		}
	}

	return false;
}

//Function that sets a input to be the next one rebound to the next key obtained by an event 
void InputHandler::RebindOnNextKeyEvent(Inputs p_eInput)
{
	m_bRebindMode = true;

	m_eRebindInput = p_eInput;
}