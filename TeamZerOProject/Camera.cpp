#include "Camera.h"

Camera::Camera()
{
	ZeroMemory(this, sizeof(Camera));
}

//
//
//
Camera::~Camera()
{
}
//
//
//
void Camera::SetCameraPosition(float x, float y, float z)
{
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_vectorPos = D3DXVECTOR3(x, y, z);
	SetViewProj();
}
//
//
//
void Camera::SetCameraPositionGaze(float x, float y, float z, float gx, float gy, float gz)
{
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_vectorPos = D3DXVECTOR3(x, y, z);
	m_GX = gx; 
	m_GY = gy;
	m_GZ = gz;

	m_canGaze = true;
	SetViewProj();
}
//
//
//
HRESULT Camera::SetViewProj()
{
	// ビュー
	if (!m_canGaze)
	{
		D3DXVECTOR3 vEyePt(m_X, m_Y, m_Z);//カメラ（視点）位置
		D3DXVECTOR3 vLookatPt(m_X, m_Y, m_Z + 1);//注視位置
		D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);//上方位置

		D3DXMatrixLookAtLH(&m_matrixView, &vEyePt, &vLookatPt, &vUpVec);
	}
	else
	{
		D3DXVECTOR3 vEyePt(m_X, m_Y, m_Z);//カメラ（視点）位置
		D3DXVECTOR3 vLookatPt(m_GX, m_GY, m_GZ);//注視位置
		D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);//上方位置

		D3DXMatrixLookAtLH(&m_matrixView, &vEyePt, &vLookatPt, &vUpVec);
	}
	m_canGaze = false;
	// プロジェクション

	D3DXMatrixPerspectiveFovLH(&m_matrixProj, D3DX_PI / 4, (FLOAT)m_windowWidth / (FLOAT)m_windowHeight, 0.1f, 1100.0f);

	return S_OK;
}
//
//
//
HRESULT Camera::Init(DWORD dwWidth, DWORD dwHeight)
{
	m_windowWidth = dwWidth;
	m_windowHeight = dwHeight;
	return S_OK;
}
