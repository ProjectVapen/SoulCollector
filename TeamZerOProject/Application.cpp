#define _CRT_SECURE_NO_WARNINGS

#include "Application.h"
#include "defineh.h"
#include <string.h>
Application::Application(){

	SecureZeroMemory(this, sizeof(Application));
	RootPath[1024] = { 0 };
	m_pAppData = std::make_unique<AppData>();
	m_pAppManager = std::make_unique<AppManager>();
	m_pWindow = std::make_unique<Window>();
}


Application::~Application(){
}

void Application::Run(HINSTANCE hInstance){

	char dir[512];
	GetCurrentDirectory(sizeof(dir), dir);
	InitDirectory(dir);

	m_hInstance = hInstance;

	if (FAILED(Init()))
	{
		return;
	}
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	//メッセージループ
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
			AppMainLoop();
		}
	}

}

void Application::InitDirectory(char* root){
	strcpy(RootPath, root);
}

HRESULT Application::Init(){
	m_pWindow = std::make_unique<Window>();

	if (!m_pWindow)
	{
		return E_FAIL;
	}
	MFAIL(m_pWindow->InitWindow(m_hInstance, 0, 0, m_pWindow->WindowWidth(),
		m_pWindow->WindowHeight(), m_pWindow->AppName()),"ウィンドウ作成失敗");	

	m_hWnd = m_pWindow->hWND();

	return 0;
}

void Application::AppMainLoop(){

}