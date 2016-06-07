#pragma once
#include "SceneNode.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



SceneNode::SceneNode()
{
	m_parent = nullptr;
}

SceneNode::~SceneNode()
{
}

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

void SceneNode::RemoveChild(SceneNode * removeChild)
{
	std::list<SceneNode*>::iterator sniter;
	sniter = std::find(m_children.begin(), m_children.end(), removeChild);
	if (sniter != m_children.end())
	{	
		//if (sniter != m_children.back)
		//{
		//	(*sniter++)->SetParent(*sniter--);
		//	m_children.erase(sniter);	
		//}
		//else
		//{
			m_children.erase(sniter);
		//}
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

	for (std::list<SceneNode*>::iterator i = m_children.begin(); i != m_children.end(); i++)
	{
		(*i)->UpdateTransforms();
	}
}

std::string SceneNode::SaveStateXML()
{
	std::ostringstream xmlString;
	xmlString << "<? xml version = \"1.0\" ?>";
	if (m_parent == nullptr)
	{
		xmlString << "<rootNode>\n";
	}

	if (!m_children.empty())
	{
		xmlString << "    <parentNode>\n";
	}
	xmlString << "        <nodeName>" << m_nodeName <<"</nodeName>\n";
	xmlString << "            <localTransform>\n";
	xmlString << "                <column1>\n";
	xmlString << "                   <x>" << m_local_transform.m_column1->m_x << "</x>" << "<y>" << m_local_transform.m_column1->m_y << "</y>" << "<z>" << m_local_transform.m_column1->m_z << "</z>\n";
	xmlString << "                </column1>\n";
	xmlString << "                <column2>\n";
	xmlString << "                   <x>" << m_local_transform.m_column2->m_x << "</x>" << "<y>" << m_local_transform.m_column2->m_y << "</y>" << "<z>" << m_local_transform.m_column2->m_z << "</z>\n";
	xmlString << "                </column2>\n";
	xmlString << "                <column3>\n";
	xmlString << "                   <x>" << m_local_transform.m_column3->m_x << "</x>" << "<y>" << m_local_transform.m_column3->m_y << "</y>" << "<z>" << m_local_transform.m_column3->m_z << "</z>\n";
	xmlString << "                </column3>\n";
	xmlString << "            </localTransform>\n";
	xmlString << "            <globalTransform>\n";
	xmlString << "                <column1>\n";
	xmlString << "                   <x>" << m_global_transform.m_column1->m_x << "</x>" << "<y>" << m_global_transform.m_column1->m_y << "</y>" << "<z>" << m_global_transform.m_column1->m_z << "</z>\n";
	xmlString << "                </column1>\n";
	xmlString << "                <column2>\n";
	xmlString << "                   <x>" << m_global_transform.m_column2->m_x << "</x>" << "<y>" << m_global_transform.m_column2->m_y << "</y>" << "<z>" << m_global_transform.m_column2->m_z << "</z>\n";
	xmlString << "                </column2>\n";
	xmlString << "                <column3>\n";
	xmlString << "                   <x>" << m_global_transform.m_column3->m_x << "</x>" << "<y>" << m_global_transform.m_column3->m_y << "</y>" << "<z>" << m_global_transform.m_column3->m_z << "</z>\n";
	xmlString << "                </column3>\n";
	xmlString << "            </globalTransform>\n";
	if (!m_children.empty())
	{
		xmlString << "        <children>\n";
		for (std::list<SceneNode*>::iterator i = m_children.begin(); i != m_children.end(); i++)
		{
			xmlString << (*i)->SaveStateXML();
		}
		xmlString << "        </children>\n";
	}

	if (!m_children.empty())
	{
		xmlString << "    </parentNode>\n";
	}

	if (m_parent == nullptr)
	{
		xmlString <<"</rootNode>\n";
	}

	return xmlString.str();
}

std::string SceneNode::SaveStateYAML()
{
	std::ostringstream xmlString;
	if (m_parent == nullptr)
	{
		xmlString << "rootNode:\n";
	}

	if (!m_children.empty())
	{
		xmlString << "    parentNode:\n";
	}
	xmlString << "        nodeName:" << m_nodeName << "\n";
	xmlString << "            localTransform:\n";
	xmlString << "                column1: {x: " << m_local_transform.m_column1->m_x << ", y: " << m_local_transform.m_column1->m_y << ", z: " << m_local_transform.m_column1->m_z << " }\n";
	xmlString << "                column2: {x: " << m_local_transform.m_column2->m_x << ", y: " << m_local_transform.m_column2->m_y << ", z: " << m_local_transform.m_column2->m_z << " }\n";
	xmlString << "                column3: {x: " << m_local_transform.m_column3->m_x << ", y: " << m_local_transform.m_column3->m_y << ", z: " << m_local_transform.m_column3->m_z << " }\n";
	xmlString << "            globalTransform: \n";
	xmlString << "                column1: {x: " << m_local_transform.m_column1->m_x << ", y: " << m_local_transform.m_column1->m_y << ", z: " << m_local_transform.m_column1->m_z << " }\n";
	xmlString << "                column2: {x: " << m_local_transform.m_column2->m_x << ", y: " << m_local_transform.m_column2->m_y << ", z: " << m_local_transform.m_column2->m_z << " }\n";
	xmlString << "                column3: {x: " << m_local_transform.m_column3->m_x << ", y: " << m_local_transform.m_column3->m_y << ", z: " << m_local_transform.m_column3->m_z << " }\n";
	if (!m_children.empty())
	{
		xmlString << "    children:\n";
		for (std::list<SceneNode*>::iterator i = m_children.begin(); i != m_children.end(); i++)
		{
			xmlString << (*i)->SaveStateYAML();
		}
	}

	return xmlString.str();
}

void SceneNode::SetNodeName(const char * nodeName)
{
	m_nodeName = nodeName;
}

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
