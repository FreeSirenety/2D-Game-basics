#include "GameObject.h"
#include <vector>

class CollisionManager
{
public:
	CollisionManager(std::vector<GameObject*> *p_vObjectVector);

	void Update();

	void InsertVector(std::vector<GameObject*> *p_vObjectVector);

	void removeCurrentVector();

	void CheckCollision(GameObject *object1, GameObject *object2);

	bool CheckBoxToBox(GameObject *object1, GameObject *object2);

	bool CheckBoxToCircle(GameObject *object1, GameObject *object2);

	bool CheckCircleToCircle(GameObject *object1, GameObject *object2);

	bool CheckPolygonCollision(GameObject *object1, GameObject *object2);

private:
	std::vector<GameObject*> *m_vObjectVector;
};