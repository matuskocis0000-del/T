#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <algorithm>

using namespace geode::prelude;

class $modify(RageEditionMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto winSize = CCDirector::get()->getWinSize();

        // Keep the real Geometry Dash buttons usable, but replace the stock background.
        if (auto stockBG = this->getChildByID("main-menu-bg")) {
            stockBG->setVisible(false);
        }

        auto rageBG = CCSprite::create("rage-menu.png"_spr);
        if (rageBG) {
            auto imageSize = rageBG->getContentSize();
            auto scaleX = winSize.width / imageSize.width;
            auto scaleY = winSize.height / imageSize.height;
            rageBG->setScale(std::max(scaleX, scaleY));
            rageBG->setPosition(winSize.width / 2.f, winSize.height / 2.f);
            rageBG->setOpacity(185);
            this->addChild(rageBG, -1000);
            rageBG->setID("rage-background"_spr);
        }

        // A small title is added to the actual, clickable main menu.
        auto title = CCLabelBMFont::create("RAGE EDITION", "bigFont.fnt");
        if (title) {
            title->setScale(0.55f);
            title->setPosition(winSize.width / 2.f, winSize.height - 28.f);
            title->setOpacity(235);
            title->setID("rage-title"_spr);
            this->addChild(title, 50);
        }

        return true;
    }
};
