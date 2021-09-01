
#ifndef ARRAYFUNCTIONS_H_
#define ARRAYFUNCTIONS_H_

#endif /* arrayFunctions_H_ */

int minNumbArrayInt(int array[], int maxIndex);
int maxNumbArrayInt(int array[], int maxIndex);
int iniArrayInt(int array[], int maxIndex, int criterio);
int iniMatrixInt(int **array, int maxFiles, int maxColumns, int criterio);
int getMinorNumFromArray(int array[], int maxIndex);
int getMaxNumFromArray(int array[], int maxIndex);
float promNumbArrayInt(int array[], int maxIndex);
int findInArrayInt(int array[], int maxIndex, int criterio);
int printArrayInt(int *array[], int maxIndex);
int printArrayIntUntil(int array[], int maxIndex, int criterio);
void ordenarArrayInt(int array[], int low, int maxIndex, int criterio);
int partition(int array[], int low, int maxIndex, int criterio);
void swap(int *menor, int *mayor);
void swapTwoValues(int array[], int array2[],int i);
int ordenarDosArray(int array[], int array2[], int maxIndex, int criterio);
int getLastWordOfString(char *str, char *outputStr);
