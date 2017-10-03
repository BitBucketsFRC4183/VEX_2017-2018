#if !defined(UTILITIES_H)
#define UTILITIES_H

#define EVER (;;)

float max(float x, float y)
{
	float retval = x;
	if (x < y)
	{
		retval = y;
	}
	return retval;
}

#endif // ROBOTMAP_H
