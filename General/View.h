#pragma once

#include "Fwd.h"

#include <LaggyDx/IObject3.h>
#include <LaggyDx/LaggyDxFwd.h>


class View : public Dx::IObject3
{
public:
  View(const Dx::IResourceController& i_resourceController);

  void setObject(Object& i_object);

  virtual Sdk::Vector3F getPosition() const override;
  virtual Sdk::Vector3F getRotation() const override;
  virtual Sdk::Vector3F getScale() const override;

  virtual const Dx::IModel& getModel() const override;
  virtual const Dx::ITextureResource* getTextureResource() const override;

private:
  Object* d_object = nullptr;

  const Dx::IResourceController& d_resourceController;

  const Dx::IModel* d_model = nullptr;
  const Dx::ITextureResource* d_textureResource = nullptr;

  const Dx::Animation* getAnimation() const;
  void checkAnimation() const;
};
