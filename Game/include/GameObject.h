#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Common.h"

#include "Components/Component.h"

using namespace std;

class GameObject
{
public:
	typedef shared_ptr<GameObject> GameObjectSharedPtr;
	typedef vector<GameObjectSharedPtr> ChildGameObjects;
	typedef map<string, IComponent::ComponentSharedPtr> Components;

	GameObject();
	~GameObject();

	void addChild(GameObjectSharedPtr Child);
	void addComponent(Component::ComponentSharedPtr Component);

	Component::ComponentSharedPtr getComponent(const string &type);
	GameObjectSharedPtr getChild(int index);
	int getNumberOfChildren();

private:
	string m_Name;
	ChildGameObjects m_Children;
	Components m_Components;
};

#endif
