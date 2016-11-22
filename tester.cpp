#include <vector>
#include <algorithm>
#include "TST.h"

#define nodes 10
using namespace std;
int main() {
	srand(time(NULL));
	//test insert
		
	int arr[nodes];
	int maxVal = 100;
	//primitive type
	TST<int> tree1;
	for(int i=0; i < nodes; i++) {
		int val = rand() % maxVal;
		tree1.insert(val);
		arr[i] = val;
	}
	sort(arr, arr + nodes);

	//check that arr and tree1.display() match 
	//inorder traversal of tree1 is same as sorted array
	//test insert & display
	cout << "insert & display test" << endl;
	{
		for(int i=0; i < nodes; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		tree1.display();
		cout << endl;
		//type containing pointers
		//TST<vector<int>> tree2;
		//passing a reference to an object on the heap

	}
	cout << endl << endl;
	cout << "find test" << endl;
	//test find 
	{
		//find random #s
		for(int i=0; i < nodes; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		for(int i=0; i < 5; i++) {
			int val = rand() % maxVal;
			bool binSearchResults = binary_search(arr, arr + nodes, val);
			if(binSearchResults) cout << val << ": binary_search -> true ";
			else cout << val << ": binary_search -> false ";	

			if(tree1.find(val)) cout << "TST find -> true" << endl;
			else  cout << "TST find -> false" << endl;
		}
		cout << endl;
		
		for(int i=0; i < 3; i++) {
			int val = rand() % nodes;
			bool binSearchResults = binary_search(arr, arr + nodes, arr[val]);
			if(binSearchResults) cout << arr[val] << ": binary_search -> true ";
			else cout << arr[val] << ": binary_search -> false ";	

			if(tree1.find(arr[val])) cout << "TST find -> true" << endl;
			else  cout << "TST find -> false" << endl;
		}
	}
	cout << endl << endl;
	//test remove
	
	cout << "remove test" << endl;
	{
		cout << "we should not be able to find any nodes that have been removed" << endl;
		for(int i=0; i < 3; i++) {
		int val = rand() % nodes;
		if(tree1.find(arr[val])) cout << arr[val] << ": TST find -> true" << endl;
		else cout << arr[val] << ": TST find -> false" << endl;
		cout << "After removing " << arr[val] << ":" << endl;
		tree1.remove(arr[val]);
		if(tree1.find(arr[val])) cout << arr[val] << ": TST find -> true" << endl;
		else cout << arr[val] << ": TST find -> false" << endl;
		}	
		tree1.remove(arr[0]);
	}

	return 0;
}
