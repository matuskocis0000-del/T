#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Definícia vlastného popup okna
class RageMenuPopup : public GeodeSquarePopup {
protected:
    bool setup() override {
        this->setTitle("Rage Menu");

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        
        // Pridanie textu do menu
        auto label = CCLabelBMFont::create("Vitaj v Rage Mode!", "bigFont.fnt");
        label->setScale(0.5f);
        label->setPosition(m_mainLayer->getContentSize().width / 2, m_mainLayer->getContentSize().height / 2 + 30);
        m_mainLayer->addChild(label);

        // Pokus o načítanie obrázka zo zložky resources
        auto sprite = CCSprite::create("resources/rage-menu.png");
        if (sprite) {
            sprite->setPosition(m_mainLayer->getContentSize() / 2 - ccp(0, 20));
            sprite->setScale(0.5f);
            m_mainLayer->addChild(sprite);
        }

        return true;
    }

public:
    static RageMenuPopup* create() {
        auto ret = new RageMenuPopup();
        if (ret && ret->init(240.f, 180.f)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

// Modifikácia hlavného menu hry
class $modify(MenuLayer) {
    bool init() override {
        if (!MenuLayer::init()) return false;

        // Načítanie hlavnej ikony módu
        auto buttonSprite = CCSprite::create("logo.png");
        if (!buttonSprite) {
            buttonSprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
        }

        auto rMenuBtn = CCMenuItemSpriteExtra::create(
            buttonSprite,
            this,
            menu_selector(MenuLayer::onRageMenu)
        );

        // Pridanie tlačidla do spodného riadku menu
        auto bottomMenu = this->getChildByID("bottom-menu");
        if (bottomMenu) {
            bottomMenu->addChild(rMenuBtn);
            bottomMenu->updateLayout();
        }

        return true;
    }

    void onRageMenu(CCObject* sender) {
        if (auto popup = RageMenuPopup::create()) {
            popup->show();
        }
    }
};
