#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    if ( !Layer::init() ) {
        return false;
    }

	// プールを生成してメンバー変数に持っておく
	_pool = ParticleSystemPool::create("particle.plist", 1000);
	_pool->retain();

	scheduleUpdate();
    return true;
}
/*
void HelloWorld::update(float dt) {
	// プールからオブジェクトを借りて、
	auto particle = _pool->pop();
	// パラメータを設定して、
	int x = rand() % 1136;
	int y = rand() % 640;
	particle->setPosition(x, y);
	// レイヤーに追加する
	this->addChild(particle);
}
 */

/*
void HelloWorld::update(float dt) {
	auto particle = ParticleSystemQuad::create("particle.plist");
	particle->setAutoRemoveOnFinish(true);
	this->addChild(particle);
}
*/

void HelloWorld::update(float dt) {
	for (int i = 0; i < 10; i++) {
		auto particle = _pool->pop();
		//auto particle = NParticleSystemQuad::create("particle.plist");
		//particle->setAutoRemoveOnFinish(true);
		if (!particle) {
			return;
		}
		int x = rand() % 1136;
		int y = rand() % 640;
		particle->setPosition(x, y);
		this->addChild(particle);
	}
}

HelloWorld::~HelloWorld() {
	CC_SAFE_RELEASE(_pool);
}
