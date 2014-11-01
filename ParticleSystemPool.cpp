//
//  ParticleSystemPool.cpp
//  androidtest
//
//  Created by 西山 大輔 on 2014/10/26.
//
//

#include "ParticleSystemPool.h"

ParticleSystemPool* ParticleSystemPool::create(std::string filename, size_t size) {
	auto pool = new ParticleSystemPool();
	if (pool && pool->init(filename, size)) {
		pool->autorelease();
		return pool;
	} else {
		CC_SAFE_DELETE(pool);
		return nullptr;
	}
}

bool ParticleSystemPool::init(std::string filename, size_t size) {
	for (int i = 0; i < size; i++) {
		auto particle = NParticleSystemQuad::create(filename);
		// 使い終わった時のコールバックを設定する
		particle->onFinishListener = [this](NParticleSystemQuad* sender) {
			// プールに戻す
			this->push(sender);
			sender->release();
		};
		// 表示が終わったら親から削除されるようにする！
		particle->setAutoRemoveOnFinish(true);
		// 停止状態で格納する
		particle->stopSystem();
		push(particle);
	}
	return true;
}

void ParticleSystemPool::push(NParticleSystemQuad* particle) {
	_pool.pushBack(particle);
}

NParticleSystemQuad* ParticleSystemPool::pop() {
	if (_pool.empty()) {
		CCLOG("プールが空です!");
		return nullptr;
	}
	auto particle = _pool.back();
	particle->retain();
	_pool.popBack();
	particle->resetSystem();
	return particle;
}