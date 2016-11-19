#include <iostream>
template <typename T>
class Node {
public:
	//assume that the = operator for T will create a deep copy
	//T should have a default constructor
	T lower;		
	T upper;
	bool hasLower = false;
	bool hasUpper = false;
	Node<T>* left;
	Node<T>* center;
	Node<T>* right;
	Node();	//empty node
	Node(const T &val);
	~Node();
};
template <typename T>
class TST {
public:
	TST();		//initialize with empty tree
	TST(const T&);		//initialize with root node
	~TST();		//traverse and call delete on all nodes

	bool insert(const T&);
	bool remove(const T&);
	bool find(const T&) const;
	void display() const; 
private:
	Node<T> * root;	
	bool insertHelper(Node<T>& node, const T&);
	void displayHelper(Node<T>& node) const;
};

#include "TST.cpp"