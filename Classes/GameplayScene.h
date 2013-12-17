#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameObjects\Scenery\Platform.h"
#include "GameObjects\Characters\MainCharacter\MainCharacter.h"

class Gameplay : public cocos2d::Layer
{
private:
	//box2d definitions
	b2World *mWorld;

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Gameplay);

	void update(float dt);
	void updateRects();
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);

	MainCharacter* mMainCharacter;
	CCRect mMainCharacterRect;

	Platform* mPlatform;
	Platform* mPlatform2;
	CCRect mPlatformRect;
	CCRect mPlatformRect2;

	Action* moveAction;

};

#endif // __HELLOWORLD_SCENE_H__
