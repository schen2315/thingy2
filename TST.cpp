template <typename T>
Node<T>::Node() {
	//all pointers point to null
	lower = NULL;
	upper = NULL;
	left = NULL;
	center = NULL;
	right = NULL;
}
template <typename T>
Node<T>::~Node() {
	if(lower != NULL) delete lower;
	if(upper != NULL) delete upper;
	if(left != NULL) delete upper;
	if(center != NULL) delete center;
	if(right != NULL) delete right;
}
template <typename T>
Node<T>::Node(const T &val) {
	T* temp = new T();
	*temp = val;			//create a deep copy	
	lower = temp;
	upper = NULL;
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
	delete root;
}





