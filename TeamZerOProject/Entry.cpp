#include "Application.h"

#include <windows.h>



INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT){
	
	std::unique_ptr<Application> app = std::make_unique<Application>();

	if (!app)
	{
		MessageBox(0, "Application生成失敗!アプリを終了します", NULL, MB_OK);
		return 0;
	}

	app->Run(hInstance);

	return 0;
}