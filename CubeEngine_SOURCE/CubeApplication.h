#pragma once
#include "commoninclude.h"
#include "cubeGameObject.h"

namespace cube
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// �÷��̾�
		//float mX;
		//float mY;
		GameObject mPlayer;

	};
}

