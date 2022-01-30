#pragma once

#include <LaggySdk/Math.h>
#include <LaggySdk/Vector.h>


class CameraSettings
{
public:
  static constexpr Sdk::Vector3F Up = { 0.0f, 0.0f, 1.0f };
  static constexpr float Distance = 5;
  static constexpr float Yaw = Sdk::degToRad(-90.0f);
  static constexpr float Pitch = Sdk::degToRad(45.0f);
  static constexpr double SpeedLinear = 15;
  static constexpr double SpeedAngular = 3;
  static constexpr float ZoomInMultiplier = 0.9f;
  static constexpr float ZoomOutMultiplier = 1.11111111111f;
};
