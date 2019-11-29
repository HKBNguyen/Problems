int binarySearch(int Arr[], int size, int target)
{
	int start = 0, end = size-1;
	int mid = (start + end)/2;

	while(start <= end)
	{
	if (Arr[mid] == target)
		return mid;
	else if (Arr[mid] < target)
	{
		start = mid +1;
	}
	else if (Arr[mid] > target)
		end = mid - 1;
}
return -1;
}


def solution(string, charSet):
    if len(string) == 0:
        return 0
    if len(charSet) == 0:
        return 0

    left = 0;
    right = 0;
    letterMap = {}
    charactersEncountered = 0;
    bestScore = float('inf')
    while (left < len(string) and right < len(string)):
        letterMap[string[right]] =  letterMap.get(string[right], 0) + 1
        if letterMap[string[right]] == 1 and string[right] in charSet:
            charactersEncountered += 1
        right += 1
        # we've encountered every letter, let's minimize!
        if (charactersEncountered == len(charSet)):
            # make the string 'invalid' again, and update
            # bestScorebefore continuing
            while (charactersEncountered == len(charSet)):
                letterMap[string[left]] -= 1
                if letterMap[string[left]] == 0 and string[left] in charSet:
                    charactersEncountered -= 1
                left += 1
            bestScore = min(bestScore, right - left + 1)
    return bestScore




class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum =nums[0], totalSum = nums[0];

        for(int i=1; i<nums.size(); i++) {

            //Current max sum is either the current element OR current element + Previous Maximum subarray)
            currentSum = max(nums[i], currentSum+nums[i]);

            //If the current maximum array sum is greater than the global total. Update it
            totalSum = max(totalSum, currentSum);
    }
        return totalSum;
    }
};



	class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // cached results of previous minimum number of coins for each amount
        // where each index indicates how much money we have left
       vector<int> dp(amount + 1);
    for(int i = 0; i < dp.size(); i++)
        dp[i] = amount + 1;
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if (dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};



// A C++ program to find k'th smallest element using max heap
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Max Heap
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    MaxHeap(int a[], int size); // Constructor
    void maxHeapify(int i);  //To maxHeapify subtree rooted with index i
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    int extractMax();  // extracts root (maximum) element
    int getMax() { return harr[0]; } // Returns maximum

    // to replace root with new node x and heapify() new root
    void replaceMax(int x) { harr[0] = x;  maxHeapify(0); }
};

MaxHeap::MaxHeap(int a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        maxHeapify(i);
        i--;
    }
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
    if (heap_size == 0)
        return INT_MAX;

    // Store the maximum vakue.
    int root = harr[0];

    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        maxHeapify(0);
    }
    heap_size--;

    return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        maxHeapify(largest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to return k'th largest element in a given array
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of first k elements: O(k) time
    MaxHeap mh(arr, k);

    // Process remaining n-k elements.  If current element is
    // smaller than root, replace root with current element
    for (int i=k; i<n; i++)
        if (arr[i] < mh.getMax())
           mh.replaceMax(arr[i]);

    // Return root
    return mh.getMax();
}

// Driver program to test above methods
int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 4;
    cout << "K'th smallest element is " <<  kthSmallest(arr, n, k);
    return 0;
}



// A C++ program to find k'th smallest element using min heap
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor
    void MinHeapify(int i);  //To minheapify subtree rooted with index i
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    int extractMin();  // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;

    // Store the minimum vakue.
    int root = harr[0];

    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;

    return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
    // Build a heap of n elements: O(n) time
    MinHeap mh(arr, n);

    // Do extract min (k-1) times
    for (int i=0; i<k-1; i++)
        mh.extractMin();

    // Return root
    return mh.getMin();
}

// Driver program to test above methods
int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}


def solution(arr):
    total = 0

    for y in range(len(arr)):
        for x in range(len(arr[y])):
            if arr[x][y] == 1:
                total += 1
                dfs(x,y,arr)
    return total

def dfs(x, y, arr):
    if x < 0 or x >= len(arr) or y < 0 or y >= len(arr[x]):
        return
    if arr[x][y] == 0:
        return
    arr[x][y] = 0
    dfs(x+1, y, arr)
    dfs(x-1, y, arr)
    dfs(x, y-1, arr)
    dfs(x, y+1, arr)

print(solution([[1,1,1],[1,0,0],[0,1,0]])) #2


// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];