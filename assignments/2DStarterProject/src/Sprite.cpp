#pragma once

#include "SpriteBatch.h"
#include "Texture.h"

#include "MtxVec3.h"
#include "Sprite.h"



Sprite::Sprite(const char* szPath)
{
	m_sprite = new Texture(szPath);
}

Sprite::~Sprite()
{
	delete m_sprite;
}

void Sprite::SetLocalTransform(Matrix3 mat3)
{
	m_local_transform = mat3;
}

void Sprite::Update(float dt)
{

}

void Sprite::Draw(SpriteBatch* spritebatch)
{
	spritebatch->drawSpriteTransformed3x3(m_sprite, (float*)m_global_transform);
}
