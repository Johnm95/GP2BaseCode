#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Common.h"
#include "GameObject.h"

class IComponent
{
public:
	typedef shared_ptr<IComponent> ComponentSharedPtr;
public:
	virtual ~IComponent(){};

	virtual const string& getType()=0;

	virtual void onUpdate()=0;
	virtual void onPreRender()=0;
	virtual void onRender()=0;
	virtual void onPostRender()=0;
	virtual void onInit()=0;
	virtual void setOwner(shared_ptr<GameObject> pOwner)=0;
};

class Component:public IComponent
{
public:
	Component()
	{
		m_Type="Component";
	}
	virtual ~Component(){};

	const string& getType(){return m_Type;};

	virtual void onUpdate(){};
	virtual void onPreRender(){};
	virtual void onRender(){};
	virtual void onPostRender(){};
	virtual void onInit(){};
	void setOwner(shared_ptr<GameObject> pOwner)
	{
		m_pOwner=pOwner;
	};
protected:
	string m_Type;
	shared_ptr<GameObject> m_pOwner;
};
#endif
