#pragma once
/*
	AppData

	データクラス管理クラス
*/
#include "DataCard.h"
#include "DataEnemy.h"
#include "DataMedium.h"
#include "DataPlayer.h"
#include <memory>
class AppData
{
	public:
		AppData();
		~AppData();

		std::unique_ptr<DataCard>	m_pDataCard;
		std::unique_ptr<DataEnemy>	m_pDataEnemy;
		std::unique_ptr<DataMedium>	m_pDataMedium;
		std::unique_ptr<DataPlayer>	m_pDataPlayer;
};

