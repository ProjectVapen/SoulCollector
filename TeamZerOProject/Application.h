#pragma once
/*
	Application

	���ۂ̃��C�����[�v����
	���ۂ̃Q�[�������Ȃǂ��s��
*/
#include "AppData.h"
#include "AppManager.h"
#include "Controller.h"
#include "Window.h"
#include <memory>
#include <windows.h>
class Application
{
	private:

		HINSTANCE m_hInstance;
		HWND m_hWnd;
		char RootPath[1124];
	public:
		Application();
		~Application();
		
		std::unique_ptr<AppData>	m_pAppData;
		std::unique_ptr<AppManager>	m_pAppManager;
		std::unique_ptr<Controller> m_pController;
		std::unique_ptr<Window>		m_pWindow;
		
		HRESULT Init();
		void Run(HINSTANCE);
		void AppMainLoop();
		void InitDirectory(char* root);

};

