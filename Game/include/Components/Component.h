#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Common.h"

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

};

class Component:public IComponent
{
public:
	Component()
	{
		m_Type="Component";
	}
	virtual ~Component();

	const string& getType(){return m_Type;};

	virtual void onUpdate(){};
	virtual void onPreRender(){};
	virtual void onRender(){};
	virtual void onPostRender(){};
	virtual void onInit(){};
protected:
	string m_Type;
};
#endif
