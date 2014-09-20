#include "CollisionManager.h"

CollisionManager::CollisionManager(std::vector<GameObject*> *p_vObjectVector)
{
	m_vObjectVector = p_vObjectVector;
}

void CollisionManager::Update()
{
	for (int i = 0; i < m_vObjectVector->size(); i++)
	{
		for (int y = i + 1; y < m_vObjectVector->size(); y++)
		{
			CheckCollision(m_vObjectVector->at(i), m_vObjectVector->at(y));
		}
	}
}

void CollisionManager::InsertVector(std::vector<GameObject*> *p_vObjectVector)
{
	m_vObjectVector = p_vObjectVector;
}

void CollisionManager::removeCurrentVector()
{
	m_vObjectVector = nullptr;
}

void CollisionManager::CheckCollision(GameObject *object1, GameObject *object2)
{

}

bool CollisionManager::CheckBoxToBox(GameObject *object1, GameObject *object2)
{
	return false;
}

bool CollisionManager::CheckBoxToCircle(GameObject *object1, GameObject *object2)
{
	return false;
}

bool CollisionManager::CheckCircleToCircle(GameObject *object1, GameObject *object2)
{
	float r1 = object1->GetHeight();
	float r2 = object2->GetHeight();

	sf::Vector2f p1 = object1->GetPos();
	sf::Vector2f p2 = object2->GetPos();

	if (sqrtf(fabs(p1.x - p2.x) * fabs(p1.x - p2.x) + fabs(p1.y - p2.y) * fabs(p1.y - p2.y)) < r1 + r2)
	{
		return true;
	}

	return false;
}

bool CollisionManager::CheckPolygonCollision(GameObject *object1, GameObject *object2)
{
	return false;
}