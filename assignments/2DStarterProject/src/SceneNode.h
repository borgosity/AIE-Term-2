#pragma once
#include <list>

#include "MtxVec4.h"

class SceneNode
{
public:
	SceneNode();
	~SceneNode();
	 
	void SetParent(SceneNode * parent);
	void AddChild(SceneNode * newChild);
	void AddChild(SceneNode * newChild, SceneNode * parent);
	void RemoveChild(SceneNode * removeChild);
	void UpdateTransforms();
	std::string SaveStateYAML();

	void SetNodeName(const char * nodeName);
	void SetLocalTransform(float c1x, float c1y, float c1z, float c2x, float c2y, float c2z, float c3x, float c3y, float c3z);
	void SetGlobalTransform(float c1x, float c1y, float c1z, float c2x, float c2y, float c2z, float c3x, float c3y, float c3z);

	const char * GetNodeName();
	const std::list<SceneNode*>& GetChildren();

protected:
	
	// list of children
	std::list<SceneNode*> m_children;
	SceneNode * m_parent;

	// transform relative to parent
	Matrix3 m_local_transform;

	// transform relative to world origin recalculated every frame
	Matrix3 m_global_transform;

	// node name for game saves
	const char * m_nodeName;
};

