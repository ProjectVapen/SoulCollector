#include "Window.h"
#include "MainLoop.h"
extern MainLoop mainLoop;
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
Window::Window() :
_windowWidth(1280),
_windowHeight(720),
_appName("Test")
{
}


Window::~Window()
{
}

HRESULT Window::InitWindow(HINSTANCE hInstance,
	INT iX, INT iY, INT iWidth, INT iHeight, LPCSTR WindowName)
{
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


	w_hWnd = CreateWindow(WindowName, WindowName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0,
		iWidth + 10 + GetSystemMetrics(SM_CXDLGFRAME) * 2,
		iHeight + 10 + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
		NULL, NULL,
		hInstance, NULL);
	mainLoop.Hwnd(w_hWnd);
	if (!mainLoop.Hdc())
	{
		return E_FAIL;
	}

	ShowWindow(mainLoop.Hwnd(), SW_SHOW);
	UpdateWindow(mainLoop.Hwnd());

	return S_OK;
}



int Window::WindowWidth()const{
	return  _windowWidth;
}

int Window::WindowHeight()const{
	return  _windowHeight;
}

LPCSTR Window::AppName()const{
	return  _appName;
}