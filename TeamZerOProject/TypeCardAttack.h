#pragma once
/*
	TypeCardAttack

	�U���J�[�h�Ǘ��N���X

	���N���X:TypeCardAttack
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

