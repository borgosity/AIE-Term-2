#pragma once
#include "SceneNode.h"



SceneNode::SceneNode()
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::SetParent(SceneNode * parent)
{
	m_parent = parent;
}

void SceneNode::AddChild(SceneNode * newChild)
{
	if (m_children.back())
	{
		newChild->SetParent(m_children.back());
		m_children.push_back(newChild);
	}
	else
	{
		newChild->SetParent(newChild);
		m_children.push_back(newChild);
	}
}

void SceneNode::RemoveChild(SceneNode * removeChild)
{
	std::vector<SceneNode*>::iterator sniter;
	sniter = std::find(m_children.begin(), m_children.end(), removeChild);
	if (sniter != m_children.end())
	{	
		if (sniter != m_children.back)
		{
			(*sniter++)->SetParent(*sniter--);
			m_children.erase(sniter);	
		}
		else
		{
			m_children.erase(sniter);
		}
	}

}

void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
	{
		m_global_transform = m_local_transform * m_parent->m_global_transform;
	}
	else
	{
		m_global_transform = m_local_transform;
	}

	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->UpdateTransforms();
	}
}