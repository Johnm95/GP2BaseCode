#include "Components/Material.h"

Material::Material()
{
  m_Type="Material";
}

Material::~Material()
{

}

void Material::onPreRender()
{
    bind();
}

void Material::bind()
{
  m_pShader->useProgram();

  GLint ambientMaterialLocation=m_pShader->getUniformLocation("ambientMaterial");
  GLint diffuseMaterialLocation=m_pShader->getUniformLocation("diffuseMaterial");
  GLint specularMaterialLocation=m_pShader->getUniformLocation("specularMaterial");
  GLint specularPowerLocation=m_pShader->getUniformLocation("specularPower");

  m_pShader->setUniform4fv(ambientMaterialLocation,m_AmbientColour);
  m_pShader->setUniform4fv(diffuseMaterialLocation,m_DiffuseColour);
  m_pShader->setUniform4fv(specularMaterialLocation,m_SpecularColour);
  m_pShader->setUniform1f(specularPowerLocation,m_SpecularPower);
}
