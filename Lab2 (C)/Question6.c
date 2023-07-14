#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	for(int i = 0,k=0;i<size;i++){
		if(source[i] != 0){
			val[k] = source[i];
			pos[k] = i;
			k++;
		}
	}


}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	for(int i = 0;i<m;i++){
		for(int k = 0;k<n;k++){
			if (pos[k] == i){
				source[i] = val[k];
			}
		}
	}
    
	

}
