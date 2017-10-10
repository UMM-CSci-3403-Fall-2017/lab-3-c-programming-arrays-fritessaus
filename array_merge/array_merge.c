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

	for(int i = 0; i < num_arrays; i++){
		tempSize += sizes[i];
	}

	int *tempArray = (int*)calloc(tempSize, sizeof(int));

	for(int j = 0; j < num_arrays; j++){
		for(int k = 0; k < sizes[j]; k++){
			tempArray[count] = values[j][k];
		}
	}

	mergesort(tempSize, tempArray);
	
	if (tempSize != 0) {
		finalCount++;
		tempValue = tempArray[0];
	}

	int *holding = (int*)calloc(tempSize, sizeof(int));

	holding[0] = tempArray[0];

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

	int *result = (int*)calloc(finalCount + 1, sizeof(int));

	if (tempSize != 0) {
		result[0] = finalCount;
		for(int k = 1; k < (finalCount + 1); k++) {
			result[k] = holding[k-1]; 
		}
	}

	free(holding);
	free(tempArray);

	return result;
}

