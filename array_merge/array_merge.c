#include <stdlib.h>
#include <string.h>
#include "../mergesort/mergesort.c"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int tempSize = 0;
	int count = 0;
	int finalCount = 0;
	int tempValue;
	int currentIndex = 1;
	
	//Calculate the total amount of elements/pointer needed for tempArray
	for(int i = 0; i < num_arrays; i++){
		tempSize += sizes[i];
	}

	int *tempArray = (int*)calloc(tempSize, sizeof(int));

	//Moving element in values to tempArray
	for(int j = 0; j < num_arrays; j++){
		for(int k = 0; k < sizes[j]; k++){
			tempArray[count] = values[j][k];
			count++;
		}
	}
	
	//Sort the values in tempArray
	mergesort(tempSize, tempArray);

	int *holding = (int*)calloc(tempSize, sizeof(int));
	
	//Putting the first element into holding array and initialize tempValue for comparison later on
	if (tempSize != 0){
		finalCount++;
                tempValue = tempArray[0];
		holding[0] = tempArray[0];
	}
	
	//This for loop is responsible for calculating the final amount of pointers needed for the array
	//return as well as adding unique values to the holding array;
	for(int l = 0; l < tempSize; l++){
		if (tempArray[l] != tempValue) {
			holding[currentIndex] = tempArray[l];
			currentIndex++;
			finalCount++;
			tempValue = tempArray[l];
		} else {
			tempValue = tempArray[l];
		}
	}

	//freeing up tempArray as it was no longer needed
	free(tempArray);

	int *result = (int*)calloc(finalCount + 1, sizeof(int));

	//copying over elements from holding to result
	if (tempSize != 0) {
		result[0] = finalCount;
		for(int k = 1; k < (finalCount + 1); k++) {
			result[k] = holding[k-1]; 
		}
	}

	//freeing holding as it was no longer needed
	free(holding);

	//returning result
	return result;
}

