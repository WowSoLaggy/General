#include "stdafx.h"
#include "MenuCreator.h"

#include "GameController.h"

#include <LaggyDx/Button.h>
#include <LaggyDx/IFontResource.h>
#include <LaggyDx/Label.h>
#include <LaggyDx/Layout.h>


MenuCreator::MenuCreator(GameController& i_gameController, Sdk::Vector2I i_resolution)
  : d_gameController(i_gameController)
  , d_resolution(std::move(i_resolution))
{
}


void MenuCreator::clearAll(Dx::IControl& i_parent) const
{
  i_parent.removeChildren();
}

void MenuCreator::createMainMenu(Dx::IControl& i_parent) const
{
  auto label = [&]()
  {
    auto ctrl = std::make_shared<Dx::Label>();
    ctrl->setFont("play.spritefont");
    i_parent.addChild(ctrl);
    return ctrl;
  };
  auto button = [&](std::shared_ptr<Dx::Layout> i_parentLayout)
  {
    auto ctrl = std::make_shared<Dx::Button>();
    ctrl->setFont("play.spritefont");
    ctrl->setTextureName(Dx::ButtonState::Normal, "btn_normal.png");
    ctrl->setTextureName(Dx::ButtonState::Hover, "btn_light.png");
    ctrl->setTextureName(Dx::ButtonState::Pressed, "btn_pressed.png");
    i_parentLayout->addChild(ctrl);
    return ctrl;
  };


  {
    auto versionLabel = label();
    versionLabel->setText("Welcome to General!");
    const auto textSize = versionLabel->getFontResource()->getStringRect(versionLabel->getText());
    versionLabel->setPosition({ float(d_resolution.x - textSize.width()) / 2.0f, 32 });
  }


  auto layoutButtons = std::make_shared<Dx::Layout>();
  i_parent.addChild(layoutButtons);
  layoutButtons->setSize({ (float)d_resolution.x, (float)d_resolution.y });
  layoutButtons->setOffset(32);
  layoutButtons->setOffsetFromBorder(64);


  {
    auto btnNewGame = button(layoutButtons);
    btnNewGame->setText("New Game");
    btnNewGame->setOnPress(std::bind(&GameController::onNewGameClick, d_gameController));
  }

  {
    auto btnExitGame = button(layoutButtons);
    btnExitGame->setText("Exit Game");
    btnExitGame->setOnPress(std::bind(&GameController::onExitClick, d_gameController));
  }
}
