#pragma once

#include <LaggySdk/Math.h>
#include <LaggySdk/Vector.h>


class TileSettings
{
public:
  static constexpr int MaxStructures = 3;
  static constexpr int MaxArmies = 6;

  static constexpr Sdk::Vector3F StructureOffsets[MaxStructures] {
    { 0.0f, 0.6f, 0.0f },
    { -0.6f, 0.1f, 0.0f },
    { 0.6f, 0.1f, 0.0f },
  };

  static constexpr float StructureRotations[MaxStructures] {
    Sdk::degToRad(0.0f),
    Sdk::degToRad(90.0f),
    Sdk::degToRad(-90.0f),
  };

  static constexpr Sdk::Vector3F ArmiesOffsets[MaxArmies] {
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
  };
};
