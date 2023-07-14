#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int n,i;
	char ch;
	n = strlen(word);

	for(i=0;i<n;i++){
		ch = word[i];
		if(ch >= 97 && ch<=122){
			freq[ch-'a']+=1;
		}
		else if (ch >=65&& ch<=90){
			freq[ch-'A']+=1;
		}
	}


	

   
}
