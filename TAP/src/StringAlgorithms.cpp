/*
 * StringAlgorithms.cpp
 *
 *  Created on: 19 May 2018
 *      Author: João Álvaro Ferreira
 */

#include "StringAlgorithms.h"

StringAlgorithms::StringAlgorithms(){};

void  StringAlgorithms::ExactStringMatchingNaive(string pattern, string text){
	unsigned int j;
	int l = pattern.length() - text.length();

	for (int i = 0; i <= l; i++)
	{
	        for (j = 0; j < pattern.length(); j++){
	            if (text[i + j] != pattern[j])
	                break;

	        if (j == pattern.length())
	            cout << "Padrao encontrado em" << i << ".";
	    }
	}

}

void StringAlgorithms::ExactStringMatchingFiniteAutomaton(string pattern, string text){

	//TO DO se acharem necessário
}

void StringAlgorithms::auxKMP(string pattern,  int *afixo_mais_longo)
{
	        int len = 0;
	        unsigned int i = 1;
	        afixo_mais_longo[0] = 0;

	        while (i < pattern.length())
	        {
	            if (pattern.at(i) == pattern.at(len))
	            {
	                len++;
	                afixo_mais_longo[i] = len;
	                i++;
	            }
	            else{
	                if (len != 0)
	                  len = afixo_mais_longo[len-1];

	                else
	                {
	                    afixo_mais_longo[i] = len;
	                    i++;
	                }
	            }
	        }
}

bool StringAlgorithms::ExactStringMatchingKMP(string pattern, string text){

			bool found = false;
	        int afixo_mais_longo[pattern.length()];
	        auxKMP(pattern,afixo_mais_longo);

	        unsigned int i = 0;
	        unsigned int j = 0;

	        while (i < text.length())
	        {
	            if (pattern.at(j) == text.at(i))
	            {
	                j++;
	                i++;
	            }
	            if (j == pattern.length())
	            {
	                j = afixo_mais_longo[j-1];
	                found = true;
	            }


	            else if (i < text.length() && pattern.at(j) != text.at(i))
	            {
	                if (j != 0)
	                    j = afixo_mais_longo[j-1];
	                else
	                    i = i+1;
	            }
	        }

	        return found;
}

int  StringAlgorithms::ApproximateStringMatchingEditDistance(string pattern, string text){


	int n = text.length();
	vector<int> d(n+1);

	int velho, novo;

	for(int j = 0; j < n; j++)
		d[j] = j;

	int m = pattern.length();

	for(int i = 1; i <= m; i++)
	{
		velho = d[0];
		d[0] = i;

		for(int j = 1; j <= n; j++)
		{
			if(pattern[i -1] == text[j-1])
				novo = velho;
			else{
				novo = min(velho, d[j]);
				novo = min(novo, d[j-1]);
				novo = novo + 1;
			}


			velho = d[j];
			d[j] = novo;
		}
	}

	return d[n];
}

int StringAlgorithms::findApproxMatchingStrings(string userInput, string sentencesVec){

	int counter = 0;
	int n = 0;

	float carChange = 99999, compare;

		counter = ApproximateStringMatchingEditDistance(sentencesVec, userInput);
		n++;
		carChange = (float) counter/n;
		compare = 0.8*sentencesVec.size();

		if(carChange < compare){
			return carChange;
		}

		else
	   return carChange;
}
