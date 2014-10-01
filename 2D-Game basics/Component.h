class GameObject;

class Component 
{
public:
	Component();

	virtual void Update(float p_fDeltaTime);

	void SetParent(GameObject *p_xParentObject);

	GameObject *GetParent();

protected:
	GameObject *m_xParentObject;
};