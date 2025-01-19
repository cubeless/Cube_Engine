#include "cubeGameObject.h"
#include "Cubeinput.h" //���� ���ʿ�� ���� cpp�� �߰�

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

		// Ű �ΰ��� ���ÿ� ������ �� ���
		// if (Input::GetKey(eKeyCode::A) && Input::GetKey(eKeyCode::D))

		//�� �ڵ�� ��ü
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
		//�Ķ� �귯�� dc�� ���� �׸��� ��� �귯���� ��ȯ
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		//�ٽ� ��� ���� �귯���� ����
		SelectObject(hdc, oldBrush);
		//�Ķ� �귯�� ����
		DeleteObject(blueBrush);

		// ����
		/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(redPen);*/

		// �⺻������ ���� ���Ǵ� GDI ������Ʈ�� �̸� DC �ȿ� ����� �δµ�
		// �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.
		/*HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);

		Rectangle(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, oldPen);

		Rectangle(mHdc, 500, 500, 600, 600);*/
	}
}