#pragma once
#include "SceneNode.h"

class Texture;
class SpriteBatch;

class Sprite : public SceneNode
{
public:
	Sprite(const char* texturePath, float sizeW = 50.0f, float sizeH = 50.0f, float orientation = 0.0f);
	~Sprite();

	void SetLocalTransform(Matrix3 mat3);
	void SetOrientation(Matrix3 mat3);

	void Update(float dt);
	void Draw(SpriteBatch* spritebatch);

private:
	Texture* m_sprite;
	Matrix3 m_orientation;
	float m_width;
	float m_height;
};

