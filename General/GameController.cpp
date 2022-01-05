#include "stdafx.h"
#include "GameController.h"

#include "CreateSession.h"
#include "Game.h"
#include "GameEvents.h"

#include <LaggyDx/Button.h>
#include <LaggyDx/IFontResource.h>
#include <LaggyDx/Label.h>
#include <LaggyDx/Layout.h>


GameController::GameController(Game& i_game)
  : d_game(i_game)
{
  connectTo(d_game);
}


void GameController::processEvent(const Sdk::IEvent& i_event)
{
  if (dynamic_cast<const GameStartedEvent*>(&i_event))
    showMainMenu();
}


void GameController::showMainMenu()
{
  const auto& resolution = d_game.getRenderDevice().getResolution();

  auto label = [&]()
  {
    auto ctrl = std::make_shared<Dx::Label>();
    ctrl->setFont("play.spritefont");
    d_game.getForm().addChild(ctrl);
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
    versionLabel->setPosition({ float(resolution.x - textSize.width()) / 2.0f, 32 });
  }


  auto layoutButtons = std::make_shared<Dx::Layout>();
  d_game.getForm().addChild(layoutButtons);
  layoutButtons->setSize({ (float)resolution.x, (float)resolution.y });
  layoutButtons->setOffset(32);
  layoutButtons->setOffsetFromBorder(64);


  {
    auto btnNewGame = button(layoutButtons);
    btnNewGame->setText("New Game");
    btnNewGame->setOnPress(std::bind(&GameController::onNewGameClick, this));
  }

  {
    auto btnExitGame = button(layoutButtons);
    btnExitGame->setText("Exit Game");
    btnExitGame->setOnPress(std::bind(&GameController::onExitClick, this));
  }
}


void GameController::onNewGameClick()
{
  d_game.getForm().removeChildren();

  d_game.attachSession(createSession());
  d_game.attachSessionView();
}

void GameController::onExitClick()
{
  d_game.stop();
}
