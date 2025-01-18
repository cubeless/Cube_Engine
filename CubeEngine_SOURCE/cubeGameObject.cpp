#include "cubeGameObject.h"

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
		
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}

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