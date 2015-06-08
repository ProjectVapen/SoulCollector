#include "Application.h"

#include <windows.h>



INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT){
	
	std::unique_ptr<Application> app = std::make_unique<Application>();

	if (!app)
	{
		MessageBox(0, "Application¶¬Ž¸”s!ƒAƒvƒŠ‚ðI—¹‚µ‚Ü‚·", NULL, MB_OK);
		return 0;
	}
	app->Run(hInstance);

	return 0;
}