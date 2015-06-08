#pragma once
#include <windows.h>
/*
	Window

	�E�B���h�E�����N���X

*/
class Window
{
private:
	//CreateWindow�̌��ʂ��i�[���Ă����̂ɕK�v
	//�i�[���MainLoop��HWND�̃Z�b�^�[�ɓn��
	HWND w_hWnd;

	const int _windowWidth;
	const int _windowHeight;
	const LPCSTR _appName;

public:

	Window();
	~Window();

	//�E�B���h�E�̍쐬
	HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCSTR);

	int WindowWidth()const;
	int WindowHeight()const;
	LPCSTR AppName()const;
};

