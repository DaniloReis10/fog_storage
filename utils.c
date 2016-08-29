#include "utils.h"
#include <string.h>
#include <stdlib.h>

float str2float(char * str)
{
	float r, num;
	char * s = strdup(str);
	char * a =(char *) strtok(s, "."), b[3];
	num = atoi(a);
	r = num;
	a = (char *) strtok(NULL, ".");
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
	num = atoi(b);
	r += (r < 0 ? - (num / 1000) : (num / 1000));
	return r;
}

