#include "Component.h"

class GameObject;

class CollisionComponent : public Component
{
public:
	CollisionComponent(GameObject *p_xParentObject, bool p_bIsActive);

	void SetActive(bool p_bIsActive);

	bool GetIsActive();

	virtual void Update(float p_fDeltaTime);

private:
	GameObject *m_xParentObject;

	bool m_bIsActive;

	float m_fRotation;
};