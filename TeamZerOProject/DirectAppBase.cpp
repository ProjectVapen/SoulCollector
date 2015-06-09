#include "DirectAppBase.h"


DirectAppBase::DirectAppBase()
{

}


DirectAppBase::~DirectAppBase()
{
}

void DirectAppBase::InitDirectory(std::string root){
	
	m_rootPath = root;
	
}

void DirectAppBase::SetRootDirectory(){
	
	SetCurrentDirectory(m_rootPath.c_str());
}

void DirectAppBase::SetSoundDirectory(){
	std::string tmp;
	tmp = m_rootPath;
	tmp = tmp + "ファイル名";
	SetCurrentDirectory(tmp.c_str());
}

void DirectAppBase::SetDataDirectory()
{
	std::string tmp;
	tmp = m_rootPath;
	tmp = tmp + "ファイル名";
	SetCurrentDirectory(tmp.c_str());
}
//
//
//
void DirectAppBase::SetVisualDirectory()
{
	std::string tmp;
	tmp = m_rootPath;
	tmp = tmp + "ファイル名";
	SetCurrentDirectory(tmp.c_str());
}
//
//
//
void DirectAppBase::SetShaderDirectory()
{
	std::string tmp;
	tmp = m_rootPath;
	tmp = tmp + "ファイル名";
	SetCurrentDirectory(tmp.c_str());
}