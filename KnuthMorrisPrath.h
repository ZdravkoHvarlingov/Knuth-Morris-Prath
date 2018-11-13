#pragma once

#include <cstring>

namespace KMP
{
	void CalculatePrefixArray(char *, int *);

	int ExecKnuthMorrisPratt(char *, char *);
}