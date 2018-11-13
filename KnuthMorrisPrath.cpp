#include "KnuthMorrisPrath.h"

void KMP::CalculatePrefixArray(char * pattern, int * prefixes)
{
	int patternLength = strlen(pattern);
	prefixes[0] = 0;
	int partialMatchCount = 0;

	for (size_t i = 1; i < patternLength; i++)
	{
		while (partialMatchCount > 0 && pattern[partialMatchCount] != pattern[i])
		{
			partialMatchCount = prefixes[partialMatchCount - 1];
		}

		if (pattern[partialMatchCount] == pattern[i])
		{
			++partialMatchCount;
		}

		prefixes[i] = partialMatchCount;
	}
}

int KMP::ExecKnuthMorrisPratt(char * text, char * pattern)
{
	int textLength = strlen(text);
	int patternLength = strlen(pattern);

	int *prefixes = new int[patternLength];
	CalculatePrefixArray(pattern, prefixes);
	int partialMatchCount = 0;

	for (size_t i = 0; i < textLength; i++)
	{
		while (partialMatchCount > 0 && pattern[partialMatchCount] != text[i])
		{
			partialMatchCount = prefixes[partialMatchCount - 1];
		}

		if (pattern[partialMatchCount] == text[i])
		{
			++partialMatchCount;
		}

		if (partialMatchCount == patternLength)
		{
			return  i - partialMatchCount + 1;
		}
	}

	return -1;
}
