#include "TST.h"
#define nodes 10
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
	// for(int i=0; i < nodes; i++) {
	// 	cout << arr[i] << " ";
	// }
	cout << endl;
	tree.display();
	cout << endl;
	// for(int i=0; i < 10; i++) {
	// 	int val = rand() % maxInt;
	// 	cout << val << ": " << tree.find(val) << endl;
	// }
	//for(int i=0; i < nodes; i++) {
		int val = rand() % nodes;
		tree.remove(arr[val]);
		cout << arr[val] << ": " << tree.find(arr[val]) << endl;
	//}
	tree.display();
	cout << endl;
	// Node<int>* min = tree.findMin(*(tree.root));
	// cout << endl;
	// if(min->hasLower) cout << min->lower << endl;
	// else cout << "something is wrong ..." << endl;
	//i may try to implement a LL class that holds stuff on the heap
	//to test if this class works on deep copies
	return 0;
}
