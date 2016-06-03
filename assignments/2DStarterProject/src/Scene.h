#pragma once
class SceneNode;

class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();
	void SetRoot(SceneNode * sceneRoot);

private:
	SceneNode * m_scene_root;
};

