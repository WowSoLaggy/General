#include "stdafx.h"
#include "View.h"

#include "Prototype.h"
#include "Tile.h"

#include <LaggyDx/FbxResource.h>
#include <LaggyDx/IResourceController.h>


View::View(const Dx::IResourceController& i_resourceController)
  : d_resourceController(i_resourceController)
{
}


void View::setObject(const Object& i_object)
{
  d_object = &i_object;

  d_fbxResource = &d_resourceController.getFbxResource(d_object->getPrototype().modelFilepath);
  d_textureResource = &d_resourceController.getTextureResource(d_object->getPrototype().textureFilepath);
}


Sdk::Vector3F View::getPosition() const
{
  CONTRACT_EXPECT(d_object);
  return d_object->getPosition();
}
const Sdk::Vector3F& View::getRotation() const
{
  CONTRACT_EXPECT(d_object);
  return d_object->getRotation();
}
const Sdk::Vector3F& View::getScale() const
{
  CONTRACT_EXPECT(d_object);
  return d_object->getScale();
}

const Dx::VertexBuffer& View::getVertexBuffer() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getVertexBuffer();
}
const Dx::IndexBuffer& View::getIndexBuffer() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getIndexBuffer();
}
const Dx::IMaterialSequence& View::getMaterials() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getMaterials();
}
const Dx::ITextureResource& View::getTextureResource() const
{
  CONTRACT_ASSERT(d_textureResource);
  return *d_textureResource;
}
