
template <typename T>
class Node {
public:
	T data;
	Node<T>* left;
	Node<T>* middle;
	Node<T>* right;
};
template <typename T>
class TST {
public:
	TST();
	TST(T);
	~TST();
	bool insert(const T&);
	bool remove(const T&);
	bool find(const T&) const;
	void display() const; 
private:
	Node<T> * root;	
};

#include "TST.cpp"