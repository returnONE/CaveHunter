#include "GameplayScene.h"
#include "DTech/FiniteStateMachine/Utils/TimeCounter.h"
#include "DTech/FiniteStateMachine/Messaging/MessageDispatcher.h"
#include "GameObjects\Characters\MainCharacter\States\TestStates.h"
#include "Box2D\Box2D.h"

#define PTM_RATIO 32.0

using namespace MOC::Utils;
using namespace MOC::Messaging;

USING_NS_CC;

Scene* Gameplay::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    Gameplay *layer = Gameplay::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Gameplay::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	// --- box2d definitions
	b2Vec2 gravity = b2Vec2(0.0f, -1.0f);
	bool doSleep = false;
	mWorld = new b2World(gravity);
	// ---

	// --- create the first body
	//b2BodyDef groundBodyDef; 
	//groundBodyDef.position.Set(0.0f, -10.0f); 
	//
	//b2Body* groundBody = mWorld->CreateBody(&groundBodyDef);

	//b2PolygonShape groundBox; 
	//groundBox.SetAsBox(50.0f, 10.0f);
	// ---

	// load sprite sheet to be used on this scene
	SpriteBatchNode* spriteSheet = SpriteBatchNode::create("TexturePacker/spritesheet.png");
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TexturePacker/spritesheet.plist");
	this->addChild(spriteSheet);
	// ---

	//instancia manual ou toda classe filha (MainCharacter, Platform, etc) tem que ter seus overrides próprios pra instanciar seu próprio tipo
	mMainCharacter = new MainCharacter();
	mMainCharacter->initWithInitialState("main_character.png", mWorld, new TestStateB());
	//mMainCharacter->SetYVelocity(1);
	mMainCharacter->setPosition(Point(200,300));
	spriteSheet->addChild(mMainCharacter, 0);

	mPlatform = new Platform();
	mPlatform->initWithInitialState("platform.png", mWorld, new TestStateB());
	mPlatform->setPosition(Point(100,100));
	spriteSheet->addChild(mPlatform, 0);

	mPlatform2 = new Platform();
	mPlatform2->initWithInitialState("platform.png", mWorld, new TestStateB());
	mPlatform2->setPosition(Point(238,100));
	spriteSheet->addChild(mPlatform2, 0);

	moveAction = CCMoveTo::create( 1, Point( mMainCharacter->getPositionX(), -120));

	//mMainCharacter->runAction(moveAction);
	
	this->schedule( schedule_selector(Gameplay::update));

	this->setTouchEnabled(true);
    
    return true;
}

void Gameplay::update(float dt)
{
	CCLayer::update(dt);
	TimeCounter::Instance()->Update(dt);
	MessageDispatcher::Instance()->DispatchDelayedMessages();
}

void Gameplay::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	if(touches->count() > 0)
	{
		if( ( mMainCharacter->GetEntity()->GetFSM()->isInState(TestStateA() )) /*== typeid(TestStateA())*/ ) {
			mMainCharacter->GetEntity()->GetFSM()->ChangeState(new TestStateB());
		}
		else {
			mMainCharacter->GetEntity()->GetFSM()->ChangeState(new TestStateA());
		}
	}
}


void Gameplay::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
