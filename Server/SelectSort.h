#ifndef SELECTSORT_H_
#define SELECTSORT_H_

#include <cmath>
#include <vector>
#include "Database.h"

/**
 * The class is responsible for applying the Select algorithm which outputs the K closest numbers based on distances
*/
class SelectSort {
private:

    /**
    * Unifies the vector between its two parts in order of distance
    * @param arr1 the Database vector
    * @param start the start of the first part
    * @param middle the start of the second part
    * @param end the end of the second part
    */
    static void merge(vector<Database>& arr1, int start, int middle, int end);

    /**
    * Divides the vector to half recursively and merge (sort arr)
    * @param arr1 the Database vector
    * @param start the start of the first part
    * @param end end of the second part
    */
    static void mergeSort(vector<Database>& arr, int start, int end);

    /**
    * Finds the location in which is distance value is the pivot
    * @param arr the Database vector
    * @param valuePivot the start of the first part
    * @return the place of the pivot in the arr 
    */
    static int findPivotPlace(vector<Database>& arr, double valuePivot);

    /**
    * Partitions the vector according to the pivot gotten by the select function, in which
    * the smaller values are on the left of the pivot and the larger values are on the right
    * @param arr the Database vector
    * @param k the start of the first part
    * @return the place of the pivot in the vector 
    */
    static int partition(vector<Database>& arr, int k);

    /**
    * Copies the range [from, until] from original vector to the subOriginal vector
    * @param original the vector being copied from
    * @param subOriginal the vector to be applied to
    * @param from the copy starting point
    * @param until the copy ending point
    */
    static void getRangeVector(vector<Database>& original, vector<Database>& subOriginal, int from, int until);

    /**
    * Finds the median of medians recursively
    * @param arr the vector sorted
    * @param k the number of neighbors needed
    * @return the median of medians being returned
    */
    static double select(vector<Database>& arr, int k);
    
public:

    /**
    * Finds the k term in size according to the distance
    * @param arr the vector type Database
    * @param k the k term in size
    * @return the distance
    */
    static double getK(vector<Database>& arr, int k);

    /**
    * Partitions the vector according to the pivot gotten by the select function, in which
    * the smaller values are on the left of the pivot and the larger values are on the right
    * @param arr the Database vector
    * @param k the start of the first part
    * @return the place of the pivot in the vector 
    */
    static int partitionFinal(vector<Database>& arr, double valuePivot);

};

#endif
