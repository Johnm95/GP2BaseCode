#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <vector>
#include <map>
#include <string>
#include <memory>

using namespace std;

class IComponent;

class GameObject
{
public:
	typedef shared_ptr<GameObject> GameObjectSharedPtr;
	typedef vector<GameObjectSharedPtr> ChildGameObjects;

	//move this to components
	typedef shared_ptr<IComponent> ComponentSharedPtr;
	typedef map<string, IComponent> Components;

	GameObject();
	~GameObject();

	void addChild(GameObjectSharedPtr Child);
	void addComponent(ComponentSharedPtr Component);

	ComponentSharedPtr getComponent(const string &name);
	GameObjectSharedPtr getChild(int index);
	int getNumberOfChildren()
	{
		m_Children.size();
	};

private:
	ChildGameObjects m_Children;
	Components m_Components;
};

#endif