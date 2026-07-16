#pragma once
#include <KamataEngine.h>
#include "UpData.h"
using namespace KamataEngine;

class Particle 
{
public:
	void Initialize(Model* model);

	void Update();

	void Draw(Camera& camera);

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;

	UpData* upData_ = nullptr;
};
