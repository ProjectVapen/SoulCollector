#pragma once
/*
	Application

	���C�����[�v����
	�Q�[�������Ȃǂ��s��
	�Q�[���S�̂̊Ǘ���
*/
#include "AppData.h"
#include "AppManager.h"
#include "Controller.h"
#include "Window.h"
#include "DirectAppBase.h"
#include <memory>
#include <windows.h>
class Application:
	public DirectAppBase
{
	private:

		HINSTANCE m_hInstance;
		HWND m_hWnd;
		
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

};

