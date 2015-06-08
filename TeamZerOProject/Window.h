#pragma once
#include <windows.h>
#include <memory>
/*
	Window

	ウィンドウ生成クラス

*/
class Window
{
	private:
		//CreateWindowの結果を格納しておくのに必要
		//格納後はMainLoopのHWNDのセッターに渡す
		HWND m_hWnd;

		const int m_windowWidth;
		const int m_windowHeight;
		const LPCSTR m_appName;

	public:

		Window();
		~Window();
		 
		std::unique_ptr<Window> m_pWindow;


		//ウィンドウの作成
		HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCSTR);

		int WindowWidth()const;
		int WindowHeight()const;
		LPCSTR AppName()const;
		HWND hWND();
		
		LRESULT MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

};

