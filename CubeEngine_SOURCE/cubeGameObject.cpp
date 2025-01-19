#include "cubeGameObject.h"
#include "Cubeinput.h" //전부 알필요는 없다 cpp에 추가

namespace cube
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::update()
	{
		if (Input::GetKey(eKeyCode::A) or Input::GetKey(eKeyCode::Left))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D) or Input::GetKey(eKeyCode::Right))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W) or Input::GetKey(eKeyCode::Down))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S) or Input::GetKey(eKeyCode::Up))
		{
			mY += 0.01f;
		}

		// 키 두개를 동시에 눌러야 할 경우
		// if (Input::GetKey(eKeyCode::A) && Input::GetKey(eKeyCode::D))

		//위 코드로 대체
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	mX -= 0.01f;
		//	//
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	mX += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	mY -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	mY += 0.01f;
		//}

	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		//파랑 브러쉬 dc에 선택 그리고 흰색 브러쉬로 반환
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		//다시 흰색 원본 브러쉬로 선택
		SelectObject(hdc, oldBrush);
		//파란 브러쉬 삭제
		DeleteObject(blueBrush);

		// 예제
		/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);*/

		// 기본적으로 자주 사용되는 GDI 오브젝트를 미리 DC 안에 만들어 두는데
		// 그 오브젝트들을 스톡 오브젝트라고 한다.
		/*HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);

		Rectangle(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, oldPen);

		Rectangle(mHdc, 500, 500, 600, 600);*/
	}
}