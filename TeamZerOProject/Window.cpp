#include "Window.h"
#include "Application.h"

Window::Window() :
m_windowWidth(1280),
m_windowHeight(720),
m_appName("SoulCollector")
{

}

Window g_windowMain;//インスタンス化


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_windowMain.m_pWindow->MsgProc(hWnd, uMsg, wParam, lParam);
}

Window::~Window()
{
}

HRESULT Window::InitWindow(HINSTANCE hInstance,
	INT iX, INT iY, INT iWidth, INT iHeight, LPCSTR WindowName)
{
	g_windowMain.m_pWindow = std::make_unique<Window>();

	WNDCLASSEX wc;

	SecureZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;

	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wc.lpszClassName = WindowName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wc);

	//DirectXの描画領域を指定
	RECT rect = { 0, 0, m_windowWidth, m_windowHeight };

	m_hWnd = CreateWindow(WindowName, WindowName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT,
		rect.right -rect.left,rect.bottom-rect.top,
		NULL, NULL,
		hInstance, NULL);

	if (!m_hWnd)
	{
		return E_FAIL;
	}

	//ウインドウの表示
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
	
	return S_OK;
}

LRESULT Window::MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch ((char)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

int Window::WindowWidth()const{
	return  m_windowWidth;
}

int Window::WindowHeight()const{
	return  m_windowHeight;
}

LPCSTR Window::AppName()const{
	return  m_appName;
}

HWND Window::hWND(){
	return m_hWnd;
}