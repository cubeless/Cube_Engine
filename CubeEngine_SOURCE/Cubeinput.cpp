#include "Cubeinput.h"

namespace cube
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		// typedef unsigned int		UINT;  ���ϴ� �̸����� ������ 
		// typedef unsigned __int64 size_t;
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// Ű�� ���� ���
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}

			// Ű�� �ȴ��� ���
			else
			{
				// ���� �����ӿ� ������ �־��� up
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}
}

