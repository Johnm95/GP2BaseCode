#include "GameObject.h"


GameObject::GameObject()
{
	m_Name="GameObject";
	m_Children.clear();
	m_Components.clear();
}

GameObject::~GameObject()
{

}

void GameObject::addChild(GameObjectSharedPtr Child)
{
	m_Children.push_back(Child);
}

void GameObject::addComponent(Component::ComponentSharedPtr Component)
{
	//check to see if Component exists, if it does, don't add
	m_Components[Component->getType()]=Component;
}

Component::ComponentSharedPtr GameObject::getComponent(const string &type)
{
	return m_Components[type];
}

GameObject::GameObjectSharedPtr GameObject::getChild(int index)
{
	return m_Children[index];
}

int GameObject::getNumberOfChildren()
{
	return m_Children.size();
};
