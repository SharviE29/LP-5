#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

template<typename T>
T parallelMax(const vector<T> &arr){

    T result = arr[0];
    #pragma omp parallel for reduction(max : result)
    for(int i = 0 ; i < arr.size(); i++){
        result = max(result, arr[i]);
    }
    return result;
}

template<typename T>
T parallelMin(const vector<T> &arr){

    T result = arr[0];
    #pragma omp parallel for reduction(min : result)
    for(int i = 0 ; i < arr.size(); i++){
        result = min(result, arr[i]);
    }
    return result;
}
template<typename T>
T parallelSum(const vector<T> &arr){

    T result = arr[0];
    #pragma omp parallel for reduction(+ : result)
    for(int i = 0 ; i < arr.size(); i++){
        result += arr[i];
    }
    return result;
}
template<typename T>
double parallelAvg(const vector<T> &arr){
    T result = parallelSum(arr);
    return static_cast<double> (result) / arr.size();
}

int main(){

    vector<int> arr(10);
    for(int i=0;i<arr.size();i++){
        arr[i] = rand() % 1000;
        cout<<arr[i]<<" ";
    }
     cout << endl;
    // Compute min, max, sum, and average using parallel reduction
    int minVal = parallelMin(arr);
    int maxVal = parallelMax(arr);
    int sum = parallelSum(arr);
    double average = parallelAvg(arr);

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}