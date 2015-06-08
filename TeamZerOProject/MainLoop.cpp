#include "MainLoop.h"
#include "FrameRate.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

MainLoop mainLoop;	//インスタンス化

MainLoop::MainLoop()
{
}

MainLoop::~MainLoop()
{
}



FrameRate frameRate(100);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT){

	SecureZeroMemory(&mainLoop._window, sizeof(Window));

	mainLoop._window = std::make_unique<Window>();


	if (mainLoop._window != nullptr)
	{
		if (SUCCEEDED(mainLoop._window->InitWindow(hInstance, 0, 0,
			mainLoop._window->WindowWidth(), mainLoop._window->WindowHeight(), mainLoop._window->AppName())))
		{

			mainLoop.MainRun();

		}
	}

	return 0;
}
/////
///////
//////////


LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{

	return mainLoop.MsgProc(hWnd, Msg, wParam, lParam);
}

/////
////////
///////////
LRESULT MainLoop::MsgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){

	switch (Msg)
	{

	case WM_USER + 1:

		InvalidateRect(hWnd, NULL, false);
		break;

	case WM_PAINT:

		m_hdc = BeginPaint(hWnd, &m_ps);

		frameRate.GetFrameRate();

	

		EndPaint(hWnd, &m_ps);

		break;

	case WM_CREATE:

		m_hdc = GetDC(hWnd);

		/////////////////////////////////////////////////
		//バックバッファの作成
		//互換デバイスコンテキストの作成
		m_hdc_MainBuffer = CreateCompatibleDC(m_hdc);
		//互換ビットマップの作成
		m_hb_BackBuffer = CreateCompatibleBitmap(m_hdc, mainLoop._window->WindowWidth(), mainLoop._window->WindowHeight());
		////////////////////////////////////////////////////

		SelectObject(m_hdc_MainBuffer, m_hb_BackBuffer);

		m_hdc = CreateCompatibleDC(NULL);

		ReleaseDC(hWnd, m_hdc);

		break;


	case WM_DESTROY:

		DeleteDC(m_hdc_MainBuffer);

		DeleteObject(m_hb_BackBuffer);

		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int MainLoop::MainRun(){

	MSG msg = { 0 };

	SecureZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SendMessage(m_hWnd, WM_USER + 1, 0, 0);

			Sleep(20);
		}
	}

	return msg.wParam;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//////
/////////
////////////
HWND MainLoop::Hwnd(){
	return m_hWnd;
}

void MainLoop::Hwnd(HWND hWnd){
	m_hWnd = hWnd;
}


HDC MainLoop::Hdc(){
	return m_hdc;
}

void MainLoop::Hdc(HDC hdc){
	m_hdc = hdc;
}

HDC MainLoop::MainBuffer(){
	return m_hdc_MainBuffer;
}
void MainLoop::MainBuffer(HDC hdc_MainBuffer){
	m_hdc_MainBuffer = hdc_MainBuffer;
}


HBITMAP MainLoop::BackBuffer(){
	return m_hb_BackBuffer;
}

PAINTSTRUCT MainLoop::Paintter(){
	return m_ps;
}