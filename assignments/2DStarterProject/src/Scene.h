#pragma once
class SceneNode;

class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();
	void SetRoot(SceneNode * sceneRoot);
	SceneNode * GetRoot();

private:
	SceneNode * m_scene_root;
};

