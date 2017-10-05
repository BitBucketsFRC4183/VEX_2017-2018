#if !defined(UTILITIES_H)
#define UTILITIES_H

#define EVER (;;)
#define DIM(x) (sizeof(x)/sizeof(x[0]))

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
