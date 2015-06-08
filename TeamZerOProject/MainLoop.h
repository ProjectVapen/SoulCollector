#pragma once
/*
	MainLoop.h

	���C�����[�v�N���X
	Application��E�B���h�E���Ăяo��

*/

#include <memory>

#include "Window.h"
#include "Application.h"

class MainLoop
{

private:

	HWND m_hWnd;					//�f�o�C�X�̎擾

	HDC m_hdc;						//�f�o�C�X�R���e�L�X�g
	HDC m_hdc_MainBuffer;			//�݊��f�o�C�X�R���e�L�X�g
	HBITMAP m_hb_BackBuffer;		//�݊��r�b�g�}�b�v
	PAINTSTRUCT m_ps;				//�y�C���g�\����

	TCHAR str[255];

public:
	MainLoop();
	~MainLoop();

	std::unique_ptr<Window> _window;
	std::unique_ptr<Application> _app;


	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);


	int MainRun();

	//�Q�b�^�[�ƃZ�b�^�[��
	//�I�[�o�[���[�h�����Ă���(���{����)
	HWND Hwnd();
	void Hwnd(HWND);

	HDC Hdc();
	void Hdc(HDC);

	HDC MainBuffer();
	void MainBuffer(HDC);

	HBITMAP BackBuffer();

	PAINTSTRUCT Paintter();

};

