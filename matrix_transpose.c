/*
 * File: matrix_transpose.c
 * Desc: this program receives a matrix inputted by the user and displays the matrix’s transpose
 * Author: Rishap kumar and Thanapol Makjumroen
 */
#include <stdio.h>
  
  int main()
  {
  	int size;
  	scanf("%d", &size);
  	int matrix[size][size];
  	int transposed_matrix[size][size];

  	for(int i =0; i< size; i++){
  		for(int j=0; j<size; j++) {
  			scanf("%d", &matrix[i][j]);
  		}
  	}
  	printf("Matrix is:\n");
  	for(int i=0; i<size; i++){
  		for(int j=0; j<size; j++){
  			printf("\t%d", matrix[i][j]);
  		}
  		printf("\n");
  	}
  	
  	for(int i=0; i<size; i++){
  	    for(int j=0; j<size; j++){
  	        transposed_matrix[i][j] = matrix[j][i];
  	    }
  	}

  	printf("After transpose, matrix is:\n");
    	for(int i=0; i<size; i++){
    		for(int j=0; j<size; j++){
    			printf("\t%d", transposed_matrix[i][j]);
    		}
    		printf("\n");
    	}
  	
  
  }
