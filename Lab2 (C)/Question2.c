#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag = 0;
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	for(int row = 0;row<N2;row++){
		int rowsum = 0;
		int diagVal = mat[row][row];

		for(int col = 0;col<N2;col++){
			mat[row][row] = 0;
			rowsum += fabs(mat[row][col]);
		}

		if (fabs(diagVal)>rowsum){
			isDiag = 1;
		}
		else{
			isDiag = 0;
		break;
		}
	}
		return isDiag;
}



