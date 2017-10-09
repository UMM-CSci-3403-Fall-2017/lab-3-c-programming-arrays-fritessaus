#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mergesort.h"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int tempSize = 0;
	int count = 0;
	int finalCount = 0;
	int index = 1;
	int tempValue;

	for(int i = 0; i < num_arrays; i++){
		tempSize += sizes[i];
	}

	int *tempArray = (int*)calloc(tempSize, sizeof(int));

	for(int j = 0; j < num_arrays; j++){
		for(int k =0; k < sizes; k++){
			tempArray[count] = values[j][k];
		}
	}

	mergesort(tempSize, tempArray);
	
	tempValue = tempArray[0];
	
	if (tempSize != 0) {
		finalCount++;
	}

	for(int l = 0; l < tempSize; l++){
		if (tempArray[l] != tempValue) {
			finalCount++;
			tempValue = tempArray[l];
		} else {
			tempValue = tempArray[l];
		}
	}

	int *result = (int*)calloc(finalCount, sizeof(int));

	if (tempSize != 0) {
		result[0] = finalCount;
		result[1] = tempArray[0];
	}

	for(int h = 0; h < (tempSize - 1); h++) {
		if (tempArray[h] != tempArray[h+1];{
				}
	}




}

bool needsSorting(int rangeSize){
        return rangeSize > 1;
}

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex){
	int rangeSize, firstIndex, secondIndex, copyIndex, i;
	rangeSize = endIndex - startIndex;
	int destination[rangeSize];
	firstIndex = startIndex;
	secondIndex = midPoint;
	copyIndex = 0;
	while(firstIndex < midPoint && secondIndex < endIndex){
		if(values[firstIndex] < values[secondIndex]){
			destination[copyIndex] = values[firstIndex];
			++firstIndex;
		}
		else{
			destination[copyIndex] = values[secondIndex];
			++secondIndex;
		}
		++copyIndex;
	}

	while(firstIndex < midPoint){
		destination[copyIndex] = values[firstIndex];
		++copyIndex;
		++firstIndex;
	}

	while(secondIndex < endIndex){
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}

	for(i=0; i<rangeSize; ++i){
		values[i + startIndex] = destination[i];
	}
}

void mergesortRange(int* values, int startIndex, int endIndex){
        int rangeSize, midPoint;
        bool needSort;
        rangeSize = endIndex - startIndex;
        needSort = needsSorting(rangeSize);

        if(needSort){
                midPoint = (startIndex + endIndex)/2;
                mergesortRange(values, startIndex, midPoint);
                mergesortRange(values, midPoint, endIndex);
                mergeRanges(values, startIndex, midPoint, endIndex);
        }
}

void mergesort(int size, int* values){
        mergesortRange(values, 0, size);
}	

	

