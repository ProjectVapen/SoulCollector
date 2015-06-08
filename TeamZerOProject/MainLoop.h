#pragma once
/*
	MainLoop.h

	メインループクラス
	Applicationやウィンドウを呼び出す

*/

#include <memory>

#include "Window.h"
#include "Application.h"

class MainLoop
{

private:

	HWND m_hWnd;					//デバイスの取得

	HDC m_hdc;						//デバイスコンテキスト
	HDC m_hdc_MainBuffer;			//互換デバイスコンテキスト
	HBITMAP m_hb_BackBuffer;		//互換ビットマップ
	PAINTSTRUCT m_ps;				//ペイント構造体

	TCHAR str[255];

public:
	MainLoop();
	~MainLoop();

	std::unique_ptr<Window> _window;
	std::unique_ptr<Application> _app;


	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);


	int MainRun();

	//ゲッターとセッターは
	//オーバーロードさせている(日本語難しい)
	HWND Hwnd();
	void Hwnd(HWND);

	HDC Hdc();
	void Hdc(HDC);

	HDC MainBuffer();
	void MainBuffer(HDC);

	HBITMAP BackBuffer();

	PAINTSTRUCT Paintter();

};

