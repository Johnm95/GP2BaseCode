#include "Components/Transform.h"

void Transform::onUpdate()
{
  //build the matrices
  m_TranlationMatrix=translate(mat4(1.0f),m_Position);
  m_ScaleMatrix=scale(mat4(1.0f),m_Scale);

  m_RotationalMatrix=rotate(mat4(1.0f),m_Rotation.x,vec3(1.0f,0.0f,0.0f))*
  rotate(mat4(1.0f),m_Rotation.y,vec3(0.0f,1.0f,0.0f))*
  rotate(mat4(1.0f),m_Rotation.z,vec3(0.0f,0.0f,1.0f));

  m_ModelMatrix=m_ScaleMatrix*m_RotationalMatrix*m_TranlationMatrix;
}
