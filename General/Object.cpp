#include "stdafx.h"
#include "Object.h"


Sdk::Vector3F Object::getPosition() const { return d_position; }
const Sdk::Vector3F& Object::getRotation() const { return d_rotation; }
const Sdk::Vector3F& Object::getScale() const { return d_scale; }
void Object::setPosition(Sdk::Vector3F i_position) { d_position = std::move(i_position); }
void Object::setRotation(Sdk::Vector3F i_rotation) { d_rotation = std::move(i_rotation); }
void Object::setScale(Sdk::Vector3F i_scale) { d_scale = std::move(i_scale); }
