
#include <iostream>
#include<fstream>
#include<chrono>
#include<cstdlib>


    void selectionsort(int arr[], int size) {
        int i, j, min, minindex;
        for (int i = 0; i < size - 1; i++) {
            min = arr[i];
            minindex = i;
            for (int j = i + 1; j < size; j++) {
                if (min > arr[j]) {
                    min = arr[j];
                    minindex = j;
                }
            }
            arr[minindex] = arr[i];
            arr[i] = min;
        }
    }


   
    void bubblesort(int arr[], int size) {
        int j = 0;
        int sort = 0;
        bool swaped = true;
        while (swaped) {

            for (int i = size-1; i > j; i--) {
                swaped = false;
                if (arr[i] < arr[i - 1]) {
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    swaped = true;
                    sort++;
                }
            }
            if (sort == 0) {
                break;
            }

            j++;
        }
    }

  
    void  insertionsort(int arr[], int size) {
        int key;
        for (int i = 1; i < size; i++) {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
  
    void sortedarrayAscending(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }

    }

    void sortedarrayDescending(int arr[], int size) {
        for (int i = size-1; i >=0; i--) {
            arr[i] = i;
        }

    }
    
    void randomarray(int arr[], int size) {
        //srand(time(0));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 10000;
        }
    }


int main() {

    const int size = 1000;
    const int numRuns = 10;
    int a[size];

    std::ofstream file;
    file.open("Data.csv");
    file << "Algorithm,Array Size,Array Type,Average Time Taken\n";

    double bubbleRandomTime = 0, bubbleAscendingTime = 0, bubbleDescendingTime = 0;

    for (int i = 0; i < numRuns; ++i) {

        randomarray(a, size);
        auto start = std::chrono::high_resolution_clock::now();
        bubblesort(a, size);
        auto end = std::chrono::high_resolution_clock::now();
        bubbleRandomTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayAscending(a, size);
        start = std::chrono::high_resolution_clock::now();
        bubblesort(a, size);
        end = std::chrono::high_resolution_clock::now();
        bubbleAscendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayDescending(a, size);
        start = std::chrono::high_resolution_clock::now();
        bubblesort(a, size);
        end = std::chrono::high_resolution_clock::now();
        bubbleDescendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    }

    bubbleRandomTime /= numRuns;
    bubbleAscendingTime /= numRuns;
    bubbleDescendingTime /= numRuns;

    file << "Bubble Sort," << size << ",Random," << bubbleRandomTime << "\n";
    file << "Bubble Sort," << size << ",Sorted Ascending," << bubbleAscendingTime << "\n";
    file << "Bubble Sort," << size << ",Sorted Descending," << bubbleDescendingTime << "\n";



    double selectionRandomTime = 0, selectionAscendingTime = 0, selectionDescendingTime = 0;
    for (int i = 0; i < numRuns; ++i) {

        randomarray(a, size);
        auto start = std::chrono::high_resolution_clock::now();
        selectionsort(a, size);
        auto end = std::chrono::high_resolution_clock::now();
        selectionRandomTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayAscending(a, size);
        start = std::chrono::high_resolution_clock::now();
        selectionsort(a, size);
        end = std::chrono::high_resolution_clock::now();
        selectionAscendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayDescending(a, size);
        start = std::chrono::high_resolution_clock::now();
        selectionsort(a, size);
        end = std::chrono::high_resolution_clock::now();
        selectionDescendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    }

    selectionRandomTime /= numRuns;
    selectionAscendingTime /= numRuns;
    selectionDescendingTime /= numRuns;

    file << "Selection Sort," << size << ",Random," << selectionRandomTime << "\n";
    file << "Selection Sort," << size << ",Sorted Ascending," << selectionAscendingTime << "\n";
    file << "Selection Sort," << size << ",Sorted Descending," << selectionDescendingTime << "\n";



    double insertionRandomTime = 0, insertionAscendingTime = 0, insertionDescendingTime = 0;
    for (int i = 0; i < numRuns; ++i) {

        randomarray(a, size);
        auto start = std::chrono::high_resolution_clock::now();
        insertionsort(a, size);
        auto end = std::chrono::high_resolution_clock::now();
        insertionRandomTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayAscending(a, size);
        start = std::chrono::high_resolution_clock::now();
        insertionsort(a, size);
        end = std::chrono::high_resolution_clock::now();
        insertionAscendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

        sortedarrayDescending(a, size);
        start = std::chrono::high_resolution_clock::now();
        insertionsort(a, size);
        end = std::chrono::high_resolution_clock::now();
        insertionDescendingTime += std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    }

        insertionRandomTime /= numRuns;
        insertionAscendingTime /= numRuns;
        insertionDescendingTime /= numRuns;


        file << "Insertion Sort," << size << ",Random," << insertionRandomTime << "\n";
        file << "Insertion Sort," << size << ",Sorted Ascending," << insertionAscendingTime << "\n";
        file << "Insertion Sort," << size << ",Sorted Descending," << insertionDescendingTime << "\n";

    }



