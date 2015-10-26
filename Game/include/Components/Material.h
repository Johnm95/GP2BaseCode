#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Common.h"
#include "Component.h"

class Material:public Component
{
public:
  Material();
  virtual ~Material();

  void onPreRender();

  void setAmbientColour(const vec4& colour)
  {
    m_AmbientColour=colour;
  };

  void setDiffuseColour(const vec4& colour)
  {
    m_DiffuseColour=colour;
  };

  void setSpecularColour(const vec4& colour)
  {
    m_SpecularColour=colour;
  };

  void setSpecularPoowe(float power)
  {
    m_SpecularPower=power;
  };

protected:
  virtual void bind();
protected:
  vec4 m_AmbientColour;
  vec4 m_DiffuseColour;
  vec4 m_SpecularColour;
  float m_SpecularPower;
};

#endif
