#pragma once
#include <windows.h>
#include <memory>
/*
	Window

	�E�B���h�E�����N���X

*/
class Window
{
	private:
		//CreateWindow�̌��ʂ��i�[���Ă����̂ɕK�v
		//�i�[���MainLoop��HWND�̃Z�b�^�[�ɓn��
		HWND m_hWnd;

		const int m_windowWidth;
		const int m_windowHeight;
		const LPCSTR m_appName;

	public:

		Window();
		~Window();
		 
		std::unique_ptr<Window> m_pWindow;


		//�E�B���h�E�̍쐬
		HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCSTR);

		int WindowWidth()const;
		int WindowHeight()const;
		LPCSTR AppName()const;
		HWND hWND();
		
		LRESULT MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

};

