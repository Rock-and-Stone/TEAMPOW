#pragma once

#define PI 3.14156f
#define PI2 PI * 2

//이미지 회전할때 편하게 하려고
#define PI8		float(PI / 8.0f)
#define PI16	float(PI / 16.0f)
#define PI32	float(PI / 32.0f)
#define PI64	float(PI / 64.0f)
#define PI128	float(PI / 128.0f)

//TWENTY NINE
namespace TN_UTILS
{
	float getDistance(float x1, float y1, float x2, float y2);

	float getAngle(float x1, float y1, float x2, float y2);
}