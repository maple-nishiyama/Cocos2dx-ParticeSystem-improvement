//
//  NParticleSystemQuad.h
//  androidtest
//
//  Created by 西山 大輔 on 2014/10/26.
//
//

#ifndef __androidtest__NParticleSystemQuad__
#define __androidtest__NParticleSystemQuad__

#include "cocos2d.h"

class NParticleSystemQuad : public cocos2d::ParticleSystemQuad {
	
public:
	static NParticleSystemQuad* create(const std::string& filename);
	virtual void update(float dt) override;
	std::function<void(NParticleSystemQuad*)> onFinishListener;
};

#endif /* defined(__androidtest__NParticleSystemQuad__) */
