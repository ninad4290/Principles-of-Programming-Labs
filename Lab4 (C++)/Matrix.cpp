
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; j++ )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	rowsNum = row;
	colsNum = col;
	if (colsNum <=0 || rowsNum <=0){
		colsNum = 3;
		rowsNum = 3;
		}
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	for(int i =0 ; i<rowsNum;++i){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));

	for(int j=0;j<colsNum;j++){
			matrixData[i][j] = 0;
		}
	}

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/


	         

}


Matrix::Matrix(int row, int col, int** table){
	rowsNum = row;
	colsNum = col;
	matrixData = (int**)malloc(rowsNum*sizeof(int));

	for(int i =0 ; i<rowsNum;i++){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
		for(int j=0;j<colsNum;j++){
			matrixData[i][j] = table[i][j];
		}
	}






	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

}

int Matrix::getElement(int i, int j){
	if( i<0 || i >= rowsNum || j<0 || j>=colsNum){
		throw std::out_of_range("Invalid indexes.");
	}

	else{
		return matrixData[i][j];
	}

}

bool Matrix::setElement(int x, int i, int j){
	if( i<0 || i >= rowsNum || j<0 || j>=colsNum){
    return false;
	}
	else{
	matrixData[i][j] = x;
	return true;
	}
}



Matrix Matrix::copy(){

	/* fix the code and write your implementation below */
	Matrix copy= Matrix(rowsNum,colsNum,matrixData);

    return  copy;


}


void Matrix::addTo( Matrix m ){
	if(m.rowsNum != rowsNum || m.colsNum != colsNum){
		throw invalid_argument("Invalid operation");
	}
	for(int	i = 0; i<rowsNum;i++){
		for(int j = 0;j<colsNum;j++){
			matrixData[i][j]+=m.matrixData[i][j];
		}
	}
}


Matrix Matrix::subMatrix(int i, int j){
	if( i<0 || i >= rowsNum || j<0 || j>=colsNum)
		throw out_of_range("Submatrix not defined");
	Matrix subM(i+1,j+1,matrixData);

	return subM;
	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */



}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return -1;
}


int Matrix::getsizeofcols(){



	/* update below return */
    return -1;
}


bool Matrix::isUpperTr(){
	int n = min(rowsNum,colsNum);
	for(int i = 0;i<n;++i){
		for(int j = 0;j<i;j++){
			if (matrixData[i][j] != 0)
				return false;
		}
	}

	/* write your implementation here and update return accordingly */
	
	  return true;
}


string Matrix::toString(){

	string output="";
	for(int i =0;i<rowsNum;++i){
		for(int j =0;j<colsNum;j++){
			output += to_string(matrixData[i][j]);
			output += " ";
		}
		output += "\n";
	}

	//return output;
	 return output;
}
