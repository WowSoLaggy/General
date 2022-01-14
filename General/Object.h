#pragma once

#include "Fwd.h"

#include <LaggySdk/Vector.h>


class Object
{
public:
  Object(const Prototype& i_prototype);
  virtual ~Object() = default;

  const Prototype& getPrototype() const;

  virtual Sdk::Vector3F getPosition() const;
  virtual const Sdk::Vector3F& getRotation() const;
  virtual const Sdk::Vector3F& getScale() const;
  virtual void setPosition(Sdk::Vector3F i_position);
  virtual void setRotation(Sdk::Vector3F i_rotation);
  virtual void setScale(Sdk::Vector3F i_scale);

private:
  const Prototype& d_prototype;

  Sdk::Vector3F d_position;
  Sdk::Vector3F d_rotation;
  Sdk::Vector3F d_scale = Sdk::Vector3F::identity();
};
