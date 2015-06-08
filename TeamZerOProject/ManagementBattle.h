#pragma once
/*
	ManagementBattle

	Battleクラス管理クラス
*/
#include "BattleCard.h"
#include "BattleEnemy.h"
#include "BattleMedium.h"
#include "BattlePlayer.h"
#include <memory>
class ManagementBattle
{
	public:
		ManagementBattle();
		~ManagementBattle();

		std::unique_ptr<BattleCard>   m_pBattleCard;
		std::unique_ptr<BattleEnemy>  m_pBattleEnemy;
		std::unique_ptr<BattleMedium> m_pBattleMedium;
		std::unique_ptr<BattlePlayer> m_pBattlePlayer;
};

