using namespace std;	
template <typename T>
Node<T>::Node() {
	//all pointers point to null
	left = NULL;
	center = NULL;
	right = NULL;
	parent = NULL;
}
template <typename T>
Node<T>::~Node() {
	if(left != NULL) delete left;
	if(center != NULL) delete center;
	if(right != NULL) delete right;
}
template <typename T>
Node<T>::Node(const T &val) {
	lower = val;			//assume create a deep copy	
	hasLower = true;
	left = NULL;
	center = NULL;
	right = NULL;
	parent = NULL;
}
template <typename T>
Node<T>::Node(const T &val, Node<T>* par) {
	lower = val;			//assume create a deep copy	
	hasLower = true;
	left = NULL;
	center = NULL;
	right = NULL;
	parent = par;
}
template <typename T>
TST<T>::TST() {
	root = NULL;
}
template <typename T>
TST<T>::TST(const T& val) {
	root = new Node<T>(val);
}
template <typename T>
TST<T>::~TST() {
	if(root != NULL)
	delete root;	//should traverse and delete every node so nothing else to do
}
template <typename T>
bool TST<T>::insert(const T& val) {
	if(root != NULL) {
		return insertHelper(*root, val);
	} else {
		root = new Node<T>(val);
		return true;
	}
}
template <typename T>
bool TST<T>::insertHelper(Node<T>& node, const T& val) {
	if(node.hasLower && node.hasUpper) {
		if(val < node.lower){
			if(node.left != NULL) {
				return insertHelper(*(node.left), val);
			} else {
				node.left = new Node<T>(val, &node);
				return true;
			}
		} else if(val > node.lower && val < node.upper) {
			if(node.center != NULL) {
				return insertHelper(*(node.center), val);
			} else {
				node.center = new Node<T>(val, &node);
				return true;
			}
		} else if(val > node.upper) {
			if(node.right != NULL) {
				return insertHelper(*(node.right), val);
			} else {
				node.right = new Node<T>(val, &node);
				return true;
			}
		} else {	//val is equal to either upper or lower
			return false;
		}
	} else if(node.hasLower) {
		if(val < node.lower) {
			if(node.left != NULL) {
				return insertHelper(*(node.left), val);
			} else {
				node.left = new Node<T>(val, &node);
				return true;
			}
		} else if(val > node.lower) {
			node.upper = val;
			node.hasUpper = true;
			return true;
		} else {	//val is equal to lower
			return false;
		}
	} else {
		//both lower & upper are NULL
		//which means there is a problem
		throw std::exception();
	}
}
template <typename T>
void TST<T>::display() const {
	if(root != NULL) {
		displayHelper(*root);
	} else {
		cout << "Tree is empty" << endl;
	}
}
template <typename T>
void TST<T>::displayHelper(const Node<T>& node) const {
	if(node.hasLower && node.hasUpper) {
		if(node.lower > node.upper) throw std::exception();
		if(node.left != NULL) displayHelper(*(node.left));
		cout << node.lower << " ";
		if(node.center != NULL) displayHelper(*(node.center));
		cout << node.upper << " ";
		if(node.right != NULL) displayHelper(*(node.right));
	} else if(node.hasLower) {
		//there should be no center or right trees
		if(node.center != NULL || node.right != NULL) throw std::exception();
		if(node.left != NULL) displayHelper(*(node.left));
		cout << node.lower << " ";
	} else {
		throw std::exception();
	}
};
template <typename T>
bool TST<T>::find(const T& val) const {
	if(root != NULL) {
		Node<T>* node = findHelper(*root, val);	
		if(node != NULL) return true;
		else return false;
	}
	else return false;
}
template <typename T>
Node<T>* TST<T>::findHelper(Node<T>& node, const T& val) const {
	if(node.hasLower && node.hasUpper) {
		if(node.lower > node.upper) throw std::exception();
		if(val < node.lower) {
			if(node.left != NULL) return findHelper(*(node.left), val);
			else return NULL;
		} else if(val > node.lower && val < node.upper) {
			if(node.center != NULL) return findHelper(*(node.center), val);
			else return NULL;
		} else if(val > node.upper) {
			if(node.right != NULL) return findHelper(*(node.right), val);
			else return NULL;
		} else {	//val is equal to either lower or upper
			return &node;
		}
	} else if(node.hasLower) {
		if(val < node.lower) {
			if(node.left != NULL) return findHelper(*(node.left), val);
			else return NULL;
		} else if(val > node.lower) {
			return NULL;
		} else {	//val is equal to lower
			return &node;
		}
	} else {
		throw std::exception();
	}
}
//remove function
//some helper functions:
	//removeHelper(Node<T>& node)
		//
	//findMin
	//findMax
//find the element
	//if in a node with 2 elements:
		//if it is the lower:
			//findMax of the left or 
			//finMin of the center tree or findMin of the right tree
				//copy the element over and call removeHelper on that tree
			//or replace with the upper
			//return tree
		//if it is the upper:
			//findMax of center or findMin of right 
				//copy the element over and call removeHelper on that tree
			//delete and return true
	//if in a node with one element:
		//findMax of left and replace
		//or just delete the node
//else return false 
template <typename T>
bool TST<T>::remove(const T& val) {
	if(root != NULL) {
		//find the element
		Node<T>* node = findHelper(*root, val);
		if(node == NULL) return false;
		else {
			removeHelper(*node, val);
			return true;
		}
	} else return false;
}

template <typename T>
void TST<T>::removeHelper(Node<T>& node, const T& val) {
	if(node.hasLower && node.hasUpper) {
		if(val == node.lower) {
			if(node.left != NULL) {
				Node<T>* max = findMax(*(node.left));
				T temp;
				if(max->hasUpper) {
					node.lower = max->upper;
					temp = max->upper;
				} else {
					node.lower = max->lower;
					temp = max->lower;
				}
				removeHelper(*max, temp);
			} else if(node.center != NULL) {
				Node<T>* min = findMin(*(node.center));
				node.lower = min->lower;
				removeHelper(*min, min->lower);
			} else if(node.right != NULL) {
				node.lower = node.upper;
				Node<T>* min = findMin(*(node.right));
				node.upper = min->lower;
				removeHelper(*min, min->lower);
			} else {
				node.lower = node.upper;
				node.hasUpper = false;
			}
		} else if(val == node.upper) {
			if(node.right != NULL) {
				Node<T>* min = findMin(*(node.right));
				node.upper = min->lower;
				removeHelper(*min, min->lower);
			} else if(node.center != NULL) {
				Node<T>* max = findMax(*(node.center));
				T temp;
				if(max->hasUpper) {
					node.upper = max->upper;
					temp = max->upper;
				} else {
					node.upper = max->lower;
					temp = max->lower;
				}
				removeHelper(*max, temp);
			} else {	
				node.hasUpper = false;
			}
		} else {
			throw std::exception();
		}
	} else if(node.hasLower) {
		if(node.center != NULL || node.right != NULL) throw std::exception();
		//search for max of left sub tree
		if(node.left != NULL) {
			Node<T>* max = findMax(*(node.left));
			T temp;
			if(max->hasUpper) {
				node.lower = max->upper;
				temp = max->upper;
			} else {
				node.lower = max->lower;
				temp = max->lower;
			}
			removeHelper(*max, temp);
		} else {
			if(node.parent->left == &node) {
				node.parent->left = NULL;
				delete &node;
			} else if(node.parent->center == &node) {
				node.parent->center = NULL;
				delete &node;
			} else if(node.parent->right == &node) {
				node.parent->right = NULL;
				delete &node;
			} else throw std::exception();
		}
	} else {
		throw std::exception();
	}
}
template <typename T>
Node<T>* TST<T>::findMax(Node<T>& node) {
	if(node.hasLower && node.hasUpper) {
		if(node.right != NULL) return findMax(*(node.right));
		else return &node;
	} else if(node.hasLower) {
		if(node.center != NULL || node.right != NULL) throw std::exception();
		return &node;
	} else {
		throw std::exception();
	}
}
template <typename T>
Node<T>* TST<T>::findMin(Node<T>& node) {
	if(node.hasLower && node.hasUpper) {
		if(node.left != NULL) return findMin(*(node.left));
		else return &node;
	} else if(node.hasLower) {
		if(node.center != NULL || node.right != NULL) throw std::exception();
		if(node.left != NULL) return findMin(*(node.left));
		else return &node;
	} else {
		throw std::exception();
	}
}














