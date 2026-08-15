#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() override {
        if (!MenuLayer::init()) return false;

        auto buttonSprite = CCSprite::create("logo.png");
        if (!buttonSprite) {
            buttonSprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
        }

        auto rMenuBtn = CCMenuItemSpriteExtra::create(
            buttonSprite,
            this,
            menu_selector(MenuLayer::onRageMenu)
        );

        auto bottomMenu = this->getChildByID("bottom-menu");
        if (bottomMenu) {
            bottomMenu->addChild(rMenuBtn);
            bottomMenu->updateLayout();
        }

        return true;
    }

    void onRageMenu(CCObject* sender) {
        FLAlertLayer::create("Rage Menu", "Modifikacia bola uspesne nacitana!", "OK")->show();
    }
};
