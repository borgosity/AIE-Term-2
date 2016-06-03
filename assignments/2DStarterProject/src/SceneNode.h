#pragma once
#include <vector>

#include "MtxVec4.h"

class SceneNode
{
public:
	SceneNode();
	~SceneNode();
	 
	void SetParent(SceneNode * parent);
	void AddChild(SceneNode * newChild);
	void RemoveChild(SceneNode * removeChild);
	void UpdateTransforms();

protected:
	// list of children
	std::vector<SceneNode*> m_children;
	SceneNode * m_parent;
	// transform relative to parent
	Matrix4 m_local_transform;
	// transform relative to world origin
	// recalculated every frame
	Matrix4 m_global_transform;

};

