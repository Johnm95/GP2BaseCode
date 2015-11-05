#include "Components/Camera.h"
#include "Components/Transform.h"
#include "GameObject.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}


void Camera::onUpdate()
{
  //grab transform
  shared_ptr<Transform> t=static_pointer_cast<Transform>(m_pOwner->getComponent("Transform"));

  lookAt(t->getPosition(),m_LookAt,m_Up);
  perspective(m_FOV,m_AspectRatio,m_NearClip,m_FarClip);
}
