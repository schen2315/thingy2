using namespace std;	
template <typename T>
Node<T>::Node() {
	//all pointers point to null
	left = NULL;
	center = NULL;
	right = NULL;
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
				node.left = new Node<T>(val);
				return true;
			}
		} else if(val > node.lower && val < node.upper) {
			if(node.center != NULL) {
				return insertHelper(*(node.center), val);
			} else {
				node.center = new Node<T>(val);
				return true;
			}
		} else if(val > node.upper) {
			if(node.right != NULL) {
				return insertHelper(*(node.right), val);
			} else {
				node.right = new Node<T>(val);
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
				node.left = new Node<T>(val);
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
void TST<T>::displayHelper(Node<T>& node) const {
	if(node.hasLower && node.hasUpper) {
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


