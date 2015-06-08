#pragma once
/*
	ManagementScene

	Scene�N���X�Ǘ��N���X
*/
#include "SceneBase.h"
#include "SceneBattle.h"
#include "SceneStart.h"
#include "SceneTitle.h"
#include <memory>
class ManagementScene
{
	public:
		ManagementScene();
		~ManagementScene();

		std::unique_ptr<SceneBase> m_pBase;
};

