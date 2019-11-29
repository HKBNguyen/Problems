#include <climits>
using namespace std;

// rough implementation of binary min heaps
// uses an array structure to hold values


class MinHeap
{
public:
	MinHeap(int capacity);
	void MinHeapify (int i );
	int parent(int i) {return (i-1)/2;}
	int left (int i) {return (2*i + 1);}
	int right (int i) {return (2*i + 2);}
	int extractMin();
	int getMin();
private:
	int *arr;
	int capacity;
	int size;
}