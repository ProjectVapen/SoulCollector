#pragma once
/*
	ManagementScene

	Sceneクラス管理クラス
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

