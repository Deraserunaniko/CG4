#include "Particle.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <numbers>
#include "Math.h"

//using namespace MathUtility;

void Particle::Initialize(Model* model) {

	// NULLポインタチェック
	assert(model);
	model_ = model;

	worldTransform_.Initialize();

	upData_ = new UpData();
	assert(upData_);

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}
void Particle::Update() {
	if (upData_) {
		upData_->WorldTransformUpData(worldTransform_);
	}

	// 移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	worldTransform_.TransferMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}
void Particle::Draw(Camera& camera) {
	
	model_->Draw(worldTransform_, camera, &objectColor_); 
}
