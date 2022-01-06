#include "stdafx.h"
#include "TileView.h"

#include "Tile.h"

#include <LaggyDx/FbxResource.h>
#include <LaggyDx/IResourceController.h>


TileView::TileView(const Dx::IResourceController& i_resourceController)
{
  d_fbxResource = &i_resourceController.getFbxResource("plane.fbx");
  d_textureResource = &i_resourceController.getTextureResource("tile_grass.png");
}


void TileView::setTile(const Tile& i_tile)
{
  d_tile = &i_tile;
}


Sdk::Vector3F TileView::getPosition() const
{
  CONTRACT_EXPECT(d_tile);
  return d_tile->getPosition();
}
const Sdk::Vector3F& TileView::getRotation() const
{
  CONTRACT_EXPECT(d_tile);
  return d_tile->getRotation();
}
const Sdk::Vector3F& TileView::getScale() const
{
  CONTRACT_EXPECT(d_tile);
  return d_tile->getScale();
}

const Dx::VertexBuffer& TileView::getVertexBuffer() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getVertexBuffer();
}
const Dx::IndexBuffer& TileView::getIndexBuffer() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getIndexBuffer();
}
const Dx::IMaterialSequence& TileView::getMaterials() const
{
  const auto* fbxResource = dynamic_cast<const Dx::FbxResource*>(d_fbxResource);
  CONTRACT_ASSERT(fbxResource);

  return fbxResource->getMaterials();
}
const Dx::ITextureResource& TileView::getTextureResource() const
{
  CONTRACT_ASSERT(d_textureResource);
  return *d_textureResource;
}
