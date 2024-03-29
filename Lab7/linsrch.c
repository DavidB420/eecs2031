/* Linear search function files. */
/* We define the two functions for linear search */
/* David Badiei, Mar. 2024 */

#define _CRT_SECURE_NO_WARNINGS //remove if not using msvc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linsrch.h"

int lininsert(linptr lin, char *s, double v) 
{
	if (strlen(s) > MAXCHARS)
		return -1;

	if (lin->elmn > MAXELMS)
		return -1;

	strncpy(lin->data[lin->elmn].name, s, MAXCHARS);
	lin->data[lin->elmn].val = v;
	lin->elmn++;
	return 0;
}

int linsrch(linptr lin, char *s, double *vp) 
{
	for (int i = 0; i < lin->elmn; i++)
	{
		if (strcmp(s, lin->data[i].name) == 0)
		{
				*vp = lin->data[i].val;
				return i;
		}
	}
	return -1;
}
