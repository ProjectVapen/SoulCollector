#pragma once
/*
	TypeAttributeBase

	属性情報基底クラス

*/

typedef enum _EAttribute{
	eFire,
	eWater,
	eWind
}eAttribute;
class TypeAttributeBase
{
	protected:
		
		eAttribute Attribute;

	public:
		TypeAttributeBase();
		~TypeAttributeBase();
};

