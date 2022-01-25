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


void View::setObject(Object& i_object)
{
  d_object = &i_object;

  d_fbxResource = &d_resourceController.getFbxResource(d_object->getPrototype().modelFilepath);
  d_textureResource = &d_resourceController.getTextureResource(d_object->getPrototype().textureFilepath);

  checkAnimation();
}


const Dx::Animation* View::getAnimation() const
{
  if (!d_object->hasAnimation())
    return nullptr;

  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  const auto& animations = fbxResource->getAnimations();
  const auto it = animations.find(d_object->getAnimation());
  if (it == animations.end())
    return nullptr;

  return &it->second;
}

void View::checkAnimation() const
{
  CONTRACT_EXPECT(d_object);

  if (const auto* animation = getAnimation())
  {
    if (d_object->getAnimationTime() >= animation->length)
      d_object->onAnimationEnd(animation->length);
  }
}


Sdk::Vector3F View::getPosition() const
{
  CONTRACT_EXPECT(d_object);

  const auto ownPos = d_object->getPosition();

  if (const auto* animation = getAnimation())
  {
    const auto animPos = animation->getTranslation(d_object->getAnimationTime());
    return ownPos + animPos;
  }

  return ownPos;
}

Sdk::Vector3F View::getRotation() const
{
  CONTRACT_EXPECT(d_object);

  const auto ownRot = d_object->getRotation();

  if (const auto* animation = getAnimation())
  {
    const auto animRot = animation->getRotation(d_object->getAnimationTime());
    return ownRot + animRot;
  }

  return ownRot;
}

Sdk::Vector3F View::getScale() const
{
  CONTRACT_EXPECT(d_object);
  
  const auto ownScale = d_object->getScale();

  if (const auto* animation = getAnimation())
  {
    const auto animScale = animation->getScale(d_object->getAnimationTime());
    return ownScale * animScale;
  }

  return ownScale;
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
