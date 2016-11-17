
template <typename T>
class Node {
public:
	//asume that the = operator for T will create a deep copy
	T* lower;		
	T* upper;
	Node<T>* left;
	Node<T>* center;
	Node<T>* right;
};
template <typename T>
class TST {
public:
	TST();		//initialize with empty tree
	TST(T);		//initialize with root node
	~TST();		//traverse and call delete on all nodes

	bool insert(const T&);
	bool remove(const T&);
	bool find(const T&) const;
	void display() const; 
private:
	Node<T> * root;	
};

#include "TST.cpp"