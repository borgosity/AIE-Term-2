#pragma once

#include "SpriteBatch.h"
#include "Texture.h"

#include "MtxVec3.h"
#include "Sprite.h"
#include "GameDef.h"



Sprite::Sprite(const char* texturePath, float sizeW, float sizeH, float orientation)
{
	m_sprite = new Texture(texturePath);
	m_orientation.setRotateZ(orientation);
	m_width = sizeW;
	m_height = sizeH;
}

Sprite::~Sprite()
{
	delete m_sprite;
}

void Sprite::SetLocalTransform(Matrix3 mat3)
{
	m_local_transform = mat3;
}

void Sprite::SetOrientation(Matrix3 mat3)
{
	m_orientation = mat3;
}

void Sprite::Update(float dt)
{
	//modify player based on rotation
	m_global_transform.m_column1->m_x = 1.0f;
	m_global_transform.m_column1->m_y = 0.0f;
	m_global_transform.m_column1->m_z = 0.0f;

	m_global_transform.m_column2->m_x = 0.0f;
	m_global_transform.m_column2->m_y = 1.0f;
	m_global_transform.m_column2->m_z = 0.0f;

	m_global_transform *= m_orientation;

}

void Sprite::Draw(SpriteBatch* spritebatch)
{
	spritebatch->drawSpriteTransformed3x3(m_sprite, (float*)m_global_transform, m_width, m_height);
}
