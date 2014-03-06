/**
 * Default Constructor
 */
template <class T> DLL<T>::DLL() {
	head = NULL;
	tail = NULL;
	length = 0;
}

/**
 * Determines if the number of elements in the data structure is empty or not.
 */
template <class T> int DLL<T>::IsEmpty() const {
	if (length == 0)
		return 1;
	
	return 0;
}

/**
 * Returns the number of elements in the data structure.
 */
template <class T> int DLL<T>::Length() const {
	return length;
}

/**
 * Adds an element to the front of the data structure.
 */
template <class T> void DLL<T>::Push_front(const T &element) {
	Node <T> *node = new Node <T> (element);
	
	if (head == NULL) { //for data structure with no elements
		head = node; //single element head and tail are both the inserting node
		tail = node;
		head->next = NULL; //single element with no links
		head->prev = NULL;
	} else {
		node->next = head; //inserting node next is now the former first element
		head->prev = node; //former first element prev is new node
		head = node; //former first element is now node
	}
	
	//increment length
	length++;
}

/**
 * Adds an element to the back of the data structure.
 */
template <class T> void DLL<T>::Push_back(const T &element) {
	Node <T> *node = new Node <T> (element);
	
	if (tail == NULL) {
		head = node; //single element head and tail are both the inserting node
		tail = node;
		tail->next = NULL; //single element with no links
		tail->prev = NULL;
	} else {
		tail->next = node; //former last element next is now node
		node->prev = tail; //node previous is former last element
		tail = node; //node is now last element
	}
	
	//increment length
	length++;
}

/**
 * Removes an element from the front of the data structure.
 */
template <class T> void DLL<T>::Pop_front() {
	//Check for empty
	if (length == 0)
		return;
	
	if (length == 1) {
		head = NULL; //remove the only element
	} else {
		head = head->next; //sets the head to the next element
		head->prev = NULL; //sets the former second element prev to null
	}
	
	//decrement length
	length--;
}

/**
 * Removes an element from the back of the data structure.
 */
template <class T> void DLL<T>::Pop_back() {
	//Check for empty
	if (length == 0)
		return;
	
	if (length == 1) {
		tail = NULL; //remove the only element
	} else {
		tail = tail->prev; //sets the tail to the second element from the tail
		tail->next = NULL; //sets the tail next to null
	}
	
	//decrement length
	length--;
}

/**
 * Returns the first element's value.
 */
template <class T> const T DLL<T>::Front() const {
	//Check for empty
	if (length > 0)
		return head->value;
	
	return NULL;
}

/**
 * Returns the last element's value.
 */
template <class T> const T DLL<T>::Back() const {
	//Check for empty
	if (length > 0)
		return tail->value;
	
	return NULL;
}

/**
 * Writes the elements of the list from front to back.
 */
template <class T> void DLL<T>::Print() const {
	//Check for empty
	if (length == 0)
		return;
	
	Node <T> *node = head;
	
	while (node != NULL) {
		cout << node->value; //print out node value
		node = node->next; //next node
		
		//prevents "," to print out behind last element
		if (node != NULL)
			cout << ", ";
	}
	
	cout << endl;
}

/**
 * Writes the elements of the list from back to front.
 */
template <class T> void DLL<T>::PrintBack() const {
	//Check for empty
	if (length == 0)
		return;
	
	Node <T> *node = tail;
	
	while (node != NULL) {
		cout << node->value; //print out node value
		node = node->prev; //previous node from current

		//prevents "," to print out behind last element
		if (node != NULL)
			cout << ", ";
	}
	
	cout << endl;
}

/**
 * Function visits each node's value for modification.
 */
template <class T> void DLL<T>::Iterate(void (*func)(T&)) {
	//Check for empty
	if (length == 0)
		return;
	
	Node <T> *node = head;
	
	while (node != NULL) {
		func(node->value); //give the node's value to function
		node = node->next; //next nodeS
	}
}

/**
 * Reverses the entire list without copying any data; uses "link inversion"
 */
template <class T> void DLL<T>::Reverse() {
	//Empty and data structure of 1 elements
	if (length < 2)
		return;
	
	Node <T> *node = head;
	Node <T> *temp = NULL; //temp node
	
	while (node != NULL) {
		temp = node->prev; //set the next node to the temp
		node->prev = node->next; //set the node prev to the next node
		node->next = temp; //set the node next to temp which is the previous node
		node = node->prev; //set the node the previous node
	}
	
	tail = head; //set the tail to be the head
	head = temp->prev; //set the head to the temp prev
}

/**
 * Default Destructor
 */
template <class T> DLL <T>::~DLL() {
	if (length == 0)
		return;
	
	Node <T> *node = head;
	
	while (node != NULL) {
		node = node->next; //next node
		delete head; //delete head
		head = node; //node becomes former head becomes
		
		//decrement length
		length--;
	}
}
