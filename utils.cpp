#include "pch.h"
#include "utils.h"

namespace TN_UTILS
{
	float getDistance(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		return sqrtf(x * x + y * y);
	}

	float getAngle(float x1, float y1, float x2, float y2)
	{
		//float angle = -atan2f(y2 - y1, x2 - x1);

		float x = x2 - x1;
		float y = y2 - y1;

		float h = sqrtf(x * x + y * y);

		float angle = acosf(x / h);

		if (y2 > y1)
		{
			angle = PI * 2 - angle;
			if (angle >= PI * 2) angle -= PI * 2;
		}


		return angle;
	}
}