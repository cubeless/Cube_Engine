#include "CubeApplication.h"

namespace cube
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
				
	}
	Application::~Application()
	{
		int a = 0;
	}

	void Application::Initialize(HWND hwnd)
	{
		// 편하게 가져다 쓰기위해 
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0, 0);
	}
	void Application::Run()
	{
		update();
		LateUpdate();
		Render();
	}
	void Application::update()
	{
		mPlayer.update();

		// 내가 오른쪽 키를 입력받았으면 X 좌표가 플러스
		// 왼쪽은 X가 마이너스
		// 위아래는 Y가 플러스/ 마이너스
		
		// cubeGameObject의 Update로 이동
		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();

		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01f;
		//}

		//mPlayer.SetPosition(x, y);

	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);

	}
	
}