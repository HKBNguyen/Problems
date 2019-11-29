#include <iostream>
using namespace std;


class Node
{
public:
	Node(int data): self.data(data){}
	int data;
	Node* left;
	Node* right;

}
Node * createMinimalTree(int arr, int start, int end)
	{
		if (start > end)
			return NULL;
		int mid = (start + end)/2
		root = Node(arr[mid]);
		root->left = createMinimalTree(arr, start, mid -1);
		root->right = createMinimalTree(arr, mid + 1, end);
		return root;
	}
int main()
{
	int size = 7;
	int arr[size] = {1,2,3,4,5,6,7};

}