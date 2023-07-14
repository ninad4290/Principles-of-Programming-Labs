#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

int strlen1(const char c[]){
	int len = 0;
	while(c[len]!=0)
		len++;
	return len;
}




char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
		char *z = NULL;
	/*write your implementation here*/
		z=(char*)malloc((strlen1(str1)+strlen1(str2)+1)*sizeof(char));
		int i,j = 0;
		for(i=0;i<strlen1(str1);j++,i++){
		z[j]=str1[i];
		}
		for(i=0;i<strlen1(str2);j++,i++){
		z[j]=str2[i];
		}
	/* finally, return the string*/
		return z;
}
