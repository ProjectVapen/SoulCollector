#pragma once
/*
	TypeAttributeBase

	���������N���X

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

