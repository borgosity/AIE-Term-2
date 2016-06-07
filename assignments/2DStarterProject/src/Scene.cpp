#pragma once
#include "Scene.h"
#include "SceneNode.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::UpdateTransforms()
{
	m_scene_root->UpdateTransforms();
}

void Scene::SetRoot(SceneNode * sceneRoot)
{
	m_scene_root = sceneRoot;
}

SceneNode * Scene::GetRoot()
{
	return m_scene_root;
}
