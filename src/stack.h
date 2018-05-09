/*
 * stack.h
 *
 *  Created on: Feb. 2016, 25th
 *  Author: EDI/DIS teachers
 *  Definition of a generic Stack
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
/**
* Stack class
* Generic class for storing objects.
* Dynamic implementation with pointers.
*/
template <class TYPE> class Stack {
private:
	/**
	* Node class
	* Each node is composed of an element (generic) and a pointer to the next.
	*/
	class Node {
	public:
	    TYPE  elem;
	    Node *next;

        Node (const TYPE &data) {
            this->elem = data;
            this->next = NULL;
        }
	};

	/** Pointer to the top node of the Stack */
	Node *topNode;

public:
	/*
	 * Default constructor
	 * Pre ={}
	 * Post= {new Stack}
	 * \param ""
	 * \return
	 */
	Stack ();

	/*
	 * Parametrized constructor
	 * Pre ={}
	 * Post= {new Stack, top() = element}
	 * \param element for the top of the Stack
	 * \return
	 */
	//Stack (TYPE elem);

	/*
	 * Empty Stack?
	 * Pre= {}
	 * Post = {}
	 * \param ""
 	 * \return true if empty, false if not empty
 	 * Complexity: O(1)
 	 */
	bool empty () const;

	/*
	 * Push an element in the Stack
	 * Pre = {Stack[Elem] x Elem2 => type(Elem2) = type(Elem)}
	 * Post = {Stack = Stack + Elem, top = Elem}
	 * \param Elem: element to insert.
 	 * \return
 	 * Complexity: O(1)
 	 */
	void push (const TYPE &elem);

	/*
	 * Get the top element of the Stack.
	 * Pre = {!empty(Stack)}
	 * Post = {Elem = top(Stack)}
	 * \param Elem is the top element of the Stack
 	 * \return
 	 * Complexity: O(1)
 	 */
	void top (TYPE &elem) const;

	/*
	 * Get the top element of the Stack.
	 * Pre = {!empty(Stack)}
	 * Post = {return top(Stack)}
	 * \param ""
 	 * \return return the element in the top of the Stack
 	 * Complexity: O(1)
 	 */
	TYPE top () const;


	/*
	 * Delete the top element in the Stack
	 * Pre = {!empty(Stack)}
	 * Post = {number of elements - 1}
	 * \param ""
 	 * \return
 	 * Complexity: O(1)
 	 */
	void pop();

	/**
	* Destructor for the Stack
	* Post = {empty(Stack) = true}
	* \param ""
	* \return
	* Complexity: O(1)
	*/
	~Stack ();
};

template <class TYPE> Stack<TYPE>::Stack () {
	topNode = NULL;
}

//template <class TYPE> Stack<TYPE>::Stack (TYPE data) {
//	Node *node = new Node (data);
//	node->next = topNode;
//	topNode = node;
//}

template <class TYPE> bool Stack<TYPE>::empty () const {
	return (topNode == NULL);
}

template <class TYPE> void Stack<TYPE>::push (const TYPE &data) {
	Node *node = new Node(data);
	node->next = topNode;
	topNode = node;
}

template <class TYPE> void Stack<TYPE>::top (TYPE &data) const {
	data = topNode->elem;
}

template <class TYPE> TYPE Stack<TYPE>::top () const {
	return topNode->elem;
}

template <class TYPE> void  Stack<TYPE>::pop(){
	Node *node = topNode;
	if (! empty()){
		topNode = topNode->next;
		delete node;
	}
}

template <class TYPE>  Stack<TYPE>::~Stack (){
	Node *node;
	while (! empty()){
		node = topNode;
		topNode = topNode->next;
		delete node;
	}
}
#endif /* STACK_H_ */

