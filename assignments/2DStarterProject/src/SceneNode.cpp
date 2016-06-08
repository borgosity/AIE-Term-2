#pragma once
#include "SceneNode.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "yaml-cpp\yaml.h"


/*****************************************************************************************************************

******************************************************************************************************************/
SceneNode::SceneNode()
{
	m_parent = nullptr;
}
/*****************************************************************************************************************

******************************************************************************************************************/
SceneNode::~SceneNode()
{
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::SetParent(SceneNode * parent)
{
	if (m_parent == nullptr)
	{
		m_parent = parent;
	}
	else
	{
		m_parent = nullptr;
		m_parent = parent;
	}
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::AddChild(SceneNode * newChild)
{
	if (m_children.empty())
	{
		m_children.push_back(newChild);
	}
	else
	{
		m_children.push_back(newChild);
	}
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::AddChild(SceneNode * newChild, SceneNode * parent)
{
	if (m_children.empty())
	{
		m_children.push_back(newChild);
		newChild->SetParent(parent);
	}
	else
	{
		m_children.push_back(newChild);
		newChild->SetParent(parent);
	}
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::RemoveChild(SceneNode * removeChild)
{
	std::list<SceneNode*>::iterator sniter;
	sniter = std::find(m_children.begin(), m_children.end(), removeChild);
	if (sniter != m_children.end())
	{	
		m_children.erase(sniter);
	}

}
/*****************************************************************************************************************

******************************************************************************************************************/
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

	for (std::list<SceneNode*>::iterator i = m_children.begin(); i != m_children.end(); i++)
	{
		(*i)->UpdateTransforms();
	}
}
/*****************************************************************************************************************

******************************************************************************************************************/
std::string SceneNode::SaveStateYAML()
{
	std::ostringstream yamlString;
	yamlString << (std::string(m_nodeName) + std::string("LT")) << ":";
	yamlString << "\n- " << m_local_transform.m_column1->m_x << "\n- " << m_local_transform.m_column1->m_y << "\n- " << m_local_transform.m_column1->m_z;
	yamlString << "\n- " << m_local_transform.m_column2->m_x << "\n- " << m_local_transform.m_column2->m_y << "\n- " << m_local_transform.m_column2->m_z;
	yamlString << "\n- " << m_local_transform.m_column3->m_x << "\n- " << m_local_transform.m_column3->m_y << "\n- " << m_local_transform.m_column3->m_z << "\n";
	yamlString << (std::string(m_nodeName) + std::string("GT")) << ":";
	yamlString << "\n- " << m_global_transform.m_column1->m_x << "\n- " << m_global_transform.m_column1->m_y << "\n- " << m_global_transform.m_column1->m_z;
	yamlString << "\n- " << m_global_transform.m_column2->m_x << "\n- " << m_global_transform.m_column2->m_y << "\n- " << m_global_transform.m_column2->m_z;
	yamlString << "\n- " << m_global_transform.m_column3->m_x << "\n- " << m_global_transform.m_column3->m_y << "\n- " << m_global_transform.m_column3->m_z << "\n";

	return yamlString.str();
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::SetNodeName(const char * nodeName)
{
	m_nodeName = nodeName;
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::SetLocalTransform(float c1x, float c1y, float c1z, float c2x, float c2y, float c2z, float c3x, float c3y, float c3z)
{
	m_local_transform.m_column1->m_x = c1x;
	m_local_transform.m_column1->m_y = c1y;
	m_local_transform.m_column1->m_z = c1z;

	m_local_transform.m_column2->m_x = c2x;
	m_local_transform.m_column2->m_y = c2y;
	m_local_transform.m_column2->m_z = c2z;

	m_local_transform.m_column3->m_x = c3x;
	m_local_transform.m_column3->m_y = c3y;
	m_local_transform.m_column3->m_z = c3z;
}
/*****************************************************************************************************************

******************************************************************************************************************/
void SceneNode::SetGlobalTransform(float c1x, float c1y, float c1z, float c2x, float c2y, float c2z, float c3x, float c3y, float c3z)
{
	m_global_transform.m_column1->m_x = c1x;
	m_global_transform.m_column1->m_y = c1y;
	m_global_transform.m_column1->m_z = c1z;

	m_global_transform.m_column2->m_x = c2x;
	m_global_transform.m_column2->m_y = c2y;
	m_global_transform.m_column2->m_z = c2z;

	m_global_transform.m_column3->m_x = c3x;
	m_global_transform.m_column3->m_y = c3y;
	m_global_transform.m_column3->m_z = c3z;
}
/*****************************************************************************************************************

******************************************************************************************************************/
const char * SceneNode::GetNodeName()
{
	return m_nodeName;
}
/*****************************************************************************************************************

******************************************************************************************************************/
const std::list<SceneNode*>& SceneNode::GetChildren()
{
	return m_children;
}
