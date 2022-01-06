#pragma once

#include <LaggySdk/Vector.h>


class Object
{
public:
  virtual ~Object() = default;

  virtual Sdk::Vector3F getPosition() const;
  virtual const Sdk::Vector3F& getRotation() const;
  virtual const Sdk::Vector3F& getScale() const;
  virtual void setPosition(Sdk::Vector3F i_position);
  virtual void setRotation(Sdk::Vector3F i_rotation);
  virtual void setScale(Sdk::Vector3F i_scale);

private:
  Sdk::Vector3F d_position;
  Sdk::Vector3F d_rotation;
  Sdk::Vector3F d_scale = Sdk::Vector3F::identity();
};
