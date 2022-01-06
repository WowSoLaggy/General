#pragma once

#include "Fwd.h"

#include <LaggyDx/IObject3.h>
#include <LaggyDx/LaggyDxFwd.h>


class TileView : public Dx::IObject3
{
public:
  TileView(const Dx::IResourceController& i_resourceController);

  void setTile(const Tile& i_tile);

  virtual Sdk::Vector3F getPosition() const override;
  virtual const Sdk::Vector3F& getRotation() const override;
  virtual const Sdk::Vector3F& getScale() const override;

  virtual const Dx::VertexBuffer& getVertexBuffer() const override;
  virtual const Dx::IndexBuffer& getIndexBuffer() const override;
  virtual const Dx::IMaterialSequence& getMaterials() const override;
  virtual const Dx::ITextureResource& getTextureResource() const override;

private:
  const Tile* d_tile = nullptr;

  const Dx::IFbxResource* d_fbxResource = nullptr;
  const Dx::ITextureResource* d_textureResource = nullptr;
};
