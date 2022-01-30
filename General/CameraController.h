#pragma once

#include <LaggyDx/ICamera.h>


class CameraController
{
public:
  CameraController();

  Dx::ICamera& getCamera();
  const Dx::ICamera& getCamera() const;

  void moveRightStart();
  void moveRightStop();
  void moveLeftStart();
  void moveLeftStop();
  void moveUpStart();
  void moveUpStop();
  void moveDownStart();
  void moveDownStop();
  void rotateCwStart();
  void rotateCwStop();
  void rotateCcwStart();
  void rotateCcwStop();

  void zoomIn();
  void zoomOut();

  void resetCamera();

  void update(double i_dt);

private:
  std::unique_ptr<Dx::ICamera> d_camera;

  bool d_moveRight = false;
  bool d_moveLeft = false;
  bool d_moveUp = false;
  bool d_moveDown = false;
  bool d_rotateCw = false;
  bool d_rotateCcw = false;

  void createDefaultCamera();
};
