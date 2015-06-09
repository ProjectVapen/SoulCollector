#pragma once
#include "DirectAppBase.h"
#include "Window.h"

typedef struct _SD3D_Init{
	HWND hWnd;
}sD3D_Init;

class MyDirect3D :
	public DirectAppBase
{
	private:
		
		HWND m_hWnd;
		ID3D11Device* m_pDevice;
		ID3D11DeviceContext* m_pDeviceContext;
		IDXGISwapChain* m_pSwapChain;
		ID3D11RenderTargetView* m_pBackBuffer_TexRTV;
		ID3D11DepthStencilView* m_pBuckBuffer_DSTexDSV;
		ID3D11Texture2D* m_pBuckBuffer_DSTex;
		ID3D11DepthStencilState* m_pBuckBuffer_DSTexState;
		ID3D11BlendState* m_pBlendState;

		ID3D11RasterizerState* m_pRasterizerState;
	public:
		MyDirect3D();
		~MyDirect3D();

		HRESULT Init(sD3D_Init*);
		void ShowFPS();
		void Clear();

		HRESULT Present();
		HRESULT InitShader();
};

