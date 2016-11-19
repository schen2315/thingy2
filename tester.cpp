#include "TST.h"
#define nodes 100
#define maxInt 100
using namespace std;

int main() {
	srand(time(NULL));
	Node<int> node1(3);
	Node<string> node2("string"); 
	TST<int> tree;
	int arr[nodes];
	for(int i=0; i < nodes; i++) {
		int val = rand()% maxInt;
		arr[i] = val;
		tree.insert(val);
		// tree.insert(i);
	}
	// for(int i=0; i < nodes; i++) {
	// 	tree.insert(i);
	// }
	sort(arr, arr+nodes);
	for(int i=0; i < nodes; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	tree.display();
	//i may try to implement a LL class that holds stuff on the heap
	//to test if this class works on deep copies
	return 0;
}
