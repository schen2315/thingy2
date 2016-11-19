#include "TST.h"
#define nodes 10
#define maxInt 100
using namespace std;

int main() {
	srand(time(NULL));
	Node<int> node1(3);
	Node<string> node2("string"); 
	TST<int> tree;
	tree.insert(1);
	int arr[nodes];
	for(int i=0; i < nodes; i++) {
		int val = rand()% maxInt;
		arr[i] = val;
		tree.insert(val);
	}
	return 0;
}
