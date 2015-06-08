#pragma once
/*
	TypeCardAttack

	攻撃カード管理クラス

	基底クラス:TypeCardAttack
*/
typedef enum _ECard{
	eAttack,
	eDefense,
	eMagic
}eCard;

#include "TypeCardBase.h"
class TypeCardAttack :
	public TypeCardBase
{
	protected:
		eCard Card;

	public:
		TypeCardAttack();
		~TypeCardAttack();
};

