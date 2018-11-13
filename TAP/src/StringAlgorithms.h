/*
 * StringAlgorithms.h
 *
 *  Created on: 19 May 2018
 *      Author: João Álvaro Ferreira
 */

#ifndef STRINGALGORITHMS_H_
#define STRINGALGORITHMS_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class StringAlgorithms{

public:
	StringAlgorithms();


	//Exact String Matching
	void ExactStringMatchingNaive(string pattern, string text);

	void ExactStringMatchingFiniteAutomaton(string pattern, string text); //não está feito porque dá mais trabalho que os outros e pode não ser util

	bool ExactStringMatchingKMP(string pattern, string text);

	void auxKMP(string pattern, int *lps);

	//Aproximate String Matching

	int divideString(string pattern, string text);
	int checkSimilarity(string string1, string string2);

	int ApproximateStringMatchingEditDistance(string string1, string string2); //usar isto para ver o quão proximo uma string é de outra e depois ordenar destinos a partir daí
	int findApproxMatchingStrings(string userInput, string sentencesVec);
};


#endif /* STRINGALGORITHMS_H_ */
