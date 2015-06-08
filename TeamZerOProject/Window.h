#pragma once
#include <windows.h>
/*
	Window

	ウィンドウ生成クラス

*/
class Window
{
private:
	//CreateWindowの結果を格納しておくのに必要
	//格納後はMainLoopのHWNDのセッターに渡す
	HWND w_hWnd;

	const int _windowWidth;
	const int _windowHeight;
	const LPCSTR _appName;

public:

	Window();
	~Window();

	//ウィンドウの作成
	HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCSTR);

	int WindowWidth()const;
	int WindowHeight()const;
	LPCSTR AppName()const;
};

