#pragma once
/*
	AppManager

	Management�N���X�Ǘ��N���X
*/
#include "ManagementBattle.h"
#include "ManagementScene.h"
#include "ManagementStart.h"
#include "ManagementTitle.h"
#include <memory>
class AppManager
{
	public:
		AppManager();
		~AppManager();

		std::unique_ptr<ManagementBattle> m_pManageBattle;
		std::unique_ptr<ManagementScene> m_pManageScene;
		std::unique_ptr<ManagementStart> m_pManageStart;
		std::unique_ptr<ManagementTitle> m_pManageTitle;



};

