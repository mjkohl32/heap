#include <iostream>
#include <cstdlib>
#include <chrono>
#include "heap.h"
#include <assert.h>
using namespace std;
using namespace std::chrono;

bool isHeap(int arr[], int parent, int size)
{
	if (parent >= size && size <= 2*parent + 1)
		return true;
	return arr[parent] <= arr[2 * parent] && arr[parent] <= arr[2 * parent + 1] &&
		isHeap(arr, 2 * parent, size) && isHeap(arr, 2 * parent + 1, size);
}


void heapSort(int arr[], int n)
{
	Heap send(n);
	for (int i = 0; i < n; i++)
		send.insert(arr[n]);
	for (int j = 0; j < n; j++) {
		arr[j] = send.min();
		send.remove_min();
	}
}

int main()
{
	Heap h(900);
	srand(time(0));
	int v;
	int n;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	t1 = high_resolution_clock::now();
	t2 = high_resolution_clock::now();
	double total = 0;
	duration<double> time_span = duration_cast<duration<double> >(t2-t1);
	for (int j = 0; j < 500; j++) // number of trials
	{
		n = rand() % 30000; // number of elements
	//	n = 900;
        int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			v = rand() % 1000; // number to be inserted
            arr[i] = v;
		}
		t1 = high_resolution_clock::now();
        heapSort(arr, n);
		t2 = high_resolution_clock::now();
        time_span = duration_cast<duration<double> >(t2 - t1);
        total = time_span.count();
//        cout << n << ", " << total << endl;
        delete[] arr;
		h.reset();
	}
}
