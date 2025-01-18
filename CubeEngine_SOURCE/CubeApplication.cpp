#include "CubeApplication.h"
#include "Cubeinput.h"

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
		// ���ϰ� ������ �������� 
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0, 0);

		// Ű���� ��ǲ �ʱ�ȭ
		Input::Initailize();
	}
	void Application::Run()
	{
		update();
		LateUpdate();
		Render();
	}
	void Application::update()
	{
		// Ű���� ��ǲ ������Ʈ
		Input::Update();

		mPlayer.update();

		// ���� ������ Ű�� �Է¹޾����� X ��ǥ�� �÷���
		// ������ X�� ���̳ʽ�
		// ���Ʒ��� Y�� �÷���/ ���̳ʽ�
		
		// cubeGameObject�� Update�� �̵�
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