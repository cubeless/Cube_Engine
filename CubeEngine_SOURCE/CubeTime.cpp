#include "CubeTime.h"

namespace cube
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::preFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTimeValue = 0.0f;

	void Time::Initailize()
	{
		//CPU의 고유 진동수
		QueryPerformanceFrequency(&cpuFrequency); //& 주소값으로 접근

		//프로그램이 시작했을때 현재 진동수
		QueryPerformanceCounter(&preFrequency);


	}
	void Time::Update()
	{
		QueryPerformanceCounter(&currentFrequency);

		float differenceFrequency
			= static_cast<float>(currentFrequency.QuadPart - preFrequency.QuadPart);
		deltaTimeValue = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);
		preFrequency.QuadPart = currentFrequency.QuadPart; //이전 빈도수를 현재수치로 대입

	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTimeValue;

		float fps = 1.0f / deltaTimeValue;

		wchar_t str[50] = L""; //리터럴 (초기화)
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);
		TextOut(hdc, 0, 0, str, len);
	}
}
