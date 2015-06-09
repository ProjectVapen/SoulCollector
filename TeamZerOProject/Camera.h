#pragma once
#include "DirectAppBase.h"
#include "Window.h"
#include "MyDirect3D.h"
class Camera :
	public DirectAppBase
{
	std::unique_ptr<MyDirect3D> m_pD3D;

	float m_X;
	float m_Y;
	float m_Z;

	//íçéã
	float m_GX;
	float m_GY;
	float m_GZ;

	DWORD m_windowWidth;
	DWORD m_windowHeight;

	bool m_canGaze;//true =	íçéãÇ†ÇË

	D3DXVECTOR3 m_vectorPos;
	D3DXMATRIX m_matrixView;
	D3DXMATRIX m_matrixProj;

	HRESULT SetViewProj();
	public:
		Camera();
		~Camera();

		void SetCameraPosition(float x, float y, float z);

		//íçéãÉAÉä
		void SetCameraPositionGaze(float x, float y, float z, float gx, float gy, float gz);

		HRESULT Init(DWORD windowWidth, DWORD windowHeight);
};

