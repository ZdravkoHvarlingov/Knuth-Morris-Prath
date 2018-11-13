#pragma once

#include "KnuthMorrisPrath.h"
#include <assert.h>

namespace KMPTests
{
	void TestMatchAtTheEndOfTheText()
	{
		char *text = "Here is some text we are going to test. The text is pretty random and it is going to be used in all the tests.\n Enjoy it!";
		char *pattern = "Enjoy it!";
			
		assert(KMP::ExecKnuthMorrisPratt(text, pattern) == 112);
	}

	void TestMatchAtTheBeginningOfTheText()
	{
		char *text = "Here is some text we are going to test. The text is pretty random and it is going to be used in all the tests.\n Enjoy it!";
		char *pattern = "Here is ";

		assert(KMP::ExecKnuthMorrisPratt(text, pattern) == 0);
	}

	void TestMatchAtTheMiddleOfTheText()
	{
		char *text = "Here is some text we are going to test. The text is pretty random and it is going to be used in all the tests.\n Enjoy it!";
		char *firstPattern = "text";
		char *secondPattern = "test";
		
		assert(KMP::ExecKnuthMorrisPratt(text, firstPattern) == 13);
		assert(KMP::ExecKnuthMorrisPratt(text, secondPattern) == 34);
	}

	void TestPatternWithLettersNotContainedInTheText()
	{
		char *text = "Here is some text we are going to test. The text is pretty random and it is going to be used in all the tests.\n Enjoy it!";
		char *pattern = "?ZzZzZ?";

		assert(KMP::ExecKnuthMorrisPratt(text, pattern) == -1);
	}

	void TestPatternWhichHasOnlyPartialMatch()
	{
		char *text = "Here is some text we are going to test. The text is pretty random and it is going to be used in all the tests.\n Enjoy it!";
		char *pattern = "randomness";

		assert(KMP::ExecKnuthMorrisPratt(text, pattern) == -1);
	}

	void ExecuteAll()
	{
		TestMatchAtTheBeginningOfTheText();
		TestMatchAtTheEndOfTheText();
		TestMatchAtTheMiddleOfTheText();
		TestPatternWhichHasOnlyPartialMatch();
		TestPatternWithLettersNotContainedInTheText();
	}
}