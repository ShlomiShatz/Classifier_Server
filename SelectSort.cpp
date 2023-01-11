#include <iostream>
#include <cmath>
#include <vector>
#include "SelectSort.h"
#include "Database.h"

#define DIVARR 5

using namespace std;


/**
* Unifies the vector between its two parts in order of distance
* @param arr1 the Database vector
* @param start the start of the first part
* @param middle the start of the second part
* @param end the end of the second part
*/
void SelectSort::merge(vector<Database>& arr1, int start, int middle, int end) {
    vector<Database> listNum;
    int endFirstArr = middle;
    int sizeMerge = end - start;
    int saveStart = start;
    if (start == end) {
        return;
    }
    for (int i = saveStart; i <= end; i++)
    {
        if (endFirstArr == start) {
            listNum.push_back(arr1[middle]);
            middle = middle + 1;
        }
        else if (middle == end + 1) {
            listNum.push_back(arr1[start]);
            start = start + 1;
        }
        else if (arr1[start].getDist() > arr1[middle].getDist()) {
            listNum.push_back(arr1[middle]);
            middle = middle + 1;
        }
        else {
            listNum.push_back(arr1[start]);
            start = start + 1;
        }
    }
    for (int i = 0; i <= sizeMerge; i++)
    {
        arr1.at(saveStart + i) = listNum[i];
    }
}

/**
* Divides the vector to half recursively and merge (sort arr)
* @param arr1 the Database vector
* @param start the start of the first part
* @param end end of the second part
*/
void SelectSort::mergeSort(vector<Database>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    SelectSort::mergeSort(arr, start, (start + end) / 2);
    SelectSort::mergeSort(arr, (start + end) / 2 + 1, end);
    SelectSort::merge(arr, start, (start + end) / 2 + 1, end);
}

/**
* Finds the location in which is distance value is the pivot
* @param arr the Database vector
* @param valuePivot the start of the first part
* @return the place of the pivot in the arr 
*/
int SelectSort::findPivotPlace(vector<Database>& arr, double valuePivot) {
    for (int i = 0; i < arr.size(); i++) {
        if (valuePivot == arr[i].getDist()) {
            return i;
        }
    }
    return arr.size();
}

/**
* Partitions the vector according to the pivot gotten by the select function, in which
* the smaller values are on the left of the pivot and the larger values are on the right
* @param arr the Database vector
* @param k the start of the first part

* @return the place of the pivot in the vector 
*/
int SelectSort::partition(vector<Database>& arr, int k) {
    double valuePivot = select(arr, k);
    return SelectSort::partitionFinal(arr,valuePivot);
}

/**
* Partitions the vector according to the pivot gotten by the select function, in which
* the smaller values are on the left of the pivot and the larger values are on the right
* @param arr the Database vector
* @param k the start of the first part
* @return the place of the pivot in the vector 
*/
int SelectSort::partitionFinal(vector<Database>& arr, double valuePivot) {
    int place = SelectSort::findPivotPlace(arr, valuePivot);
    Database temp = arr[place];
    arr[place] = arr[0];
    arr[0] = temp;
    int biggerThenPivot = 1;
    int smallerThenPivot = 0;
    while (biggerThenPivot < arr.size()) {
        if (valuePivot < arr[biggerThenPivot].getDist()) {
            biggerThenPivot++;
        }
        else if (valuePivot >= arr[biggerThenPivot].getDist()) {
            smallerThenPivot++;
            temp = arr[smallerThenPivot];
            arr[smallerThenPivot] = arr[biggerThenPivot];
            arr[biggerThenPivot] = temp;
            biggerThenPivot++;
        }
    }
    temp = arr[0];
    arr[0]= arr[smallerThenPivot];
    arr[smallerThenPivot] = temp;
    return smallerThenPivot;
}

/**
* Copies the range [from, until] from original vector to the subOriginal vector
* @param original the vector being copied from
* @param subOriginal the vector to be applied to
* @param from the copy starting point
* @param until the copy ending point
*/
void SelectSort::getRangeVector(vector<Database>& original, vector<Database>& subOriginal, int from, int until) {
    for (int i = from; i < until; i++) {
        subOriginal.push_back(original[i]);
    }
}

/**
* Finds the median of medians recursively
* @param arr the vector sorted
* @param k the number of neighbors needed
* @return the median of medians being returned
*/
double SelectSort::select(vector<Database>& arr, int k) {
    double size = arr.size();
    vector<Database> arrMedian;
    if (size < DIVARR) {
        SelectSort::mergeSort(arr, 0, size - 1);
        return arr[k-1].getDist();
    }
    for (int i = 0; i < size; i = i + DIVARR) {
        if (i + DIVARR > size) {
            SelectSort::mergeSort(arr, i, size - 1);
            arrMedian.push_back(arr[i + ((size - 1 - i) / 2)]);
        }
        else {
            SelectSort::mergeSort(arr, i, i - 1 + DIVARR);
            arrMedian.push_back(arr[i + (DIVARR / 2)]);
        }
    }
    return SelectSort::select(arrMedian, ceil((size / (DIVARR * 2))));  
}

/**
* Finds the k term in size according to the distance
* @param arr the vector type Database
* @param k the k term in size
* @return the distance
*/
double SelectSort::getK(vector<Database>& arr, int k) {
    int placePivot = SelectSort::partition(arr, k);
    if (placePivot + 1 == k) {
        return arr[k - 1].getDist();
    }
    vector<Database> subOriginal;
    if (placePivot + 1 < k) {
        SelectSort::getRangeVector(arr, subOriginal, placePivot + 1, arr.size());
        return getK(subOriginal, k - placePivot - 1);
    }
    else {
        SelectSort::getRangeVector(arr, subOriginal, 0, placePivot);
        return getK(subOriginal, k);
    }
}

