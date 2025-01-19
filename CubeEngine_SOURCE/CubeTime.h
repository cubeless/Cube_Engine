#pragma once
#include "commoninclude.h"

namespace cube
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return deltaTimeValue; }

	private:
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER preFrequency;
		static LARGE_INTEGER currentFrequency;
		static float deltaTimeValue;

	};
}


