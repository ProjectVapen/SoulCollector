#pragma once
/*
	TypeAttributeBase

	‘®«î•ñŠî’êƒNƒ‰ƒX

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

