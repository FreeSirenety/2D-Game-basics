#include "Object.h"

Object::Object()
{
	m_sTag = "none";
}

void Object::SetTag(std::string p_sTag)
{
	m_sTag = p_sTag;
}

std::string Object::GetTag()
{
	return m_sTag;
}