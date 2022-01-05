#pragma once

#include <LaggySdk/Vector.h>


class Object
{
public:
  virtual ~Object() = default;

  const Sdk::Vector3F& getPosition() const;
  const Sdk::Vector3F& getRotation() const;
  const Sdk::Vector3F& getScale() const;
  void setPosition(Sdk::Vector3F i_position);
  void setRotation(Sdk::Vector3F i_rotation);
  void setScale(Sdk::Vector3F i_scale);

private:
  Sdk::Vector3F d_position;
  Sdk::Vector3F d_rotation;
  Sdk::Vector3F d_scale = Sdk::Vector3F::identity();
};
