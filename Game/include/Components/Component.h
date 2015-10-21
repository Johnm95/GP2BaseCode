#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Common.h"

class IComponent
{
public:
	typedef shared_ptr<IComponent> ComponentSharedPtr;
public:
	virtual ~IComponent(){};

	virtual const string& getName()=0;
	virtual const string& getType()=0;

	virtual void onUpdate()=0;
	virtual void onRender()=0;
	virtual void onInit()=0;

};

class Component:public IComponent
{
public:
	Component(const string& name,const string& type)
	{
		m_Name=name;
		m_Type=type;
	}
	virtual ~Component();

	const string& getName(){return m_Name;};
	const string& getType(){return m_Type;};

	virtual void onUpdate(){};
	virtual void onRender(){};
	virtual void onInit(){};
private:
	string m_Name;
	string m_Type;

};
#endif
