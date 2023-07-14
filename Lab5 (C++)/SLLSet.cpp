/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>
#include <string>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize){
	size = arrSize;
	head = NULL;
	for (int i = size - 1; i >= 0; i--) { //moving left in the linked list
		SLLNode *currentnode = new SLLNode(); //creating a node that has value 0 and next is null
		currentnode->value = sortedArray[i]; //value is each item in the sorted array
		currentnode->next = head; //the next value is the head
		head = currentnode; //setting left most node as the head value
		}

	}

int SLLSet::getSize()
{
	
	//fixME
	return size;
}
SLLSet SLLSet::copy(){
	SLLNode *copyNode = new SLLNode(head->value, NULL); //setting variable copyNode to a new linked list
	SLLSet *copy = new SLLSet(); //creates a new set called copy
	SLLNode *current = head; //sets variable current as the node head

	current = current->next; //the node head leads to the next node
	copy->size = size; //copies the size to be the same as current set
	copy->head = copyNode; //copies the head to be the same as the current head

	while (current != NULL) { //while the node head is not equal to NULL, which is after the node tail
		copyNode->next = new SLLNode(current->value, NULL); //the next value will be the next value from temp
		current = current->next;
		copyNode = copyNode->next;
	}
	
	return *copy;
}
bool SLLSet::isIn(int v){
	SLLNode *current = head; //sets variable current as the node head
	while (current != NULL) { //while the node head is not NULL
		if (current->value == v) { //if the head value is the same as v return true
			return true;
		}
		current = current->next; //continue through the next node head after the if statement
	}

	return false; //if head value does not exist then return false
}
void SLLSet::add(int v){
	SLLNode *current = head; //sets variable current as the node head

	if (isIn(v) == false) { //if the head value in the previous function does not exist

		if (head == NULL) { //if the head value is NULL, meaning it is after the tail
				head = new SLLNode(v, NULL); //replace the NULL value with variable v input
		}
		else if (head->value > v) { //otherwise, if the head value is bigger than the v input value

				head = new SLLNode(v, head); //replace the head value with the variable v input

		}
		else { //in the middle

			while (current->next != NULL) { //if the next value of the head is not NULL
				if (current->next->value > v && current->value < v) { //if next value is not greater than the v input value AND it is not less
					current->next = new SLLNode(v, current->next);
				}
				current = current->next; //replace current with the next value each time it loops
			}

				//insert at the ending
			if (v > current->value) {
				current->next = new SLLNode(v, NULL);
			}
		}
		size++; //increase the size by 1
	}

}
void SLLSet::remove(int v){
	SLLNode *currentnode = head; //let variable node equal the node head

	if (isIn(v) == true) { //if the v input variable exists

		while (currentnode && currentnode->next) { //while the node head and the next value
			if (currentnode->next->value == v) { //if the next nodes value is equal to the variable v input value
				currentnode->next = currentnode->next->next; //the next nodes value will be the next next node
			}
			else {
				currentnode = currentnode->next; //else the node value is the next node value
				}
			}
		if (head->value == v) //if the head value is equal to v
			head = head->next; //the head value will be the next head

		size--; //decrease the size of the set by  1
	}

}
SLLSet SLLSet::setUnion(SLLSet s){
	SLLSet *unionLL = new SLLSet(); //create a new set with variable name unionLL

	if (s.head == NULL) {// if the input set head is equal to NULL
		*unionLL = copy(); //copy the set and return it
		return (*unionLL);
	}

	if (head == NULL) { //if the head is equal to NULL
		*unionLL = s.copy(); //copy the input set and return it
		return (*unionLL);
	}

	*unionLL = copy();

	while (s.head != NULL) { //iterate through the input set linked list
		(*unionLL).add(s.head->value); //add input set values to uniionLL
		size++; //increase the size by 1
		s.head = s.head->next; //the input set head will be the next head
	}

	return (*unionLL); //return the new linked list set
}
SLLSet SLLSet::intersection(SLLSet s){
	if (s.head == NULL || head == NULL) { //if the input set or the head are equal to NULL
			SLLSet *intersecting = new SLLSet(); //create a new set with variable name intersecting and return it
			return *intersecting;
		}

		SLLSet *intersecting = new SLLSet();
		int counter = 0;

		while (s.head != NULL) { //while the input set head does not equal NULL

			if (isIn(s.head->value) == true) { //if the input s head value existence equals true

				(*intersecting).add(s.head->value); //add the input s head value into the intersecting set
				counter++; //increment by 1
			}

			s.head = s.head->next; //iterate
		}

		(*intersecting).size = counter; //if the size of the set equals the increment then return the set

		return *intersecting;

}
SLLSet SLLSet::difference(SLLSet s){
	if (head == NULL) { //if the head equals NULL
			SLLSet different= SLLSet(); //create a new set with variable different and return it
			return different;
		}

		if (s.head == NULL) { //if the input set head equals NULL
			SLLSet different= copy(); //create a copy and return it
			return different;
		}

		SLLSet *different= new SLLSet();
		int counter = 0;

		SLLNode *current = head; //let variable current be the node head

		while (current != NULL) { //while the node head does not equal NULL

			if (s.isIn(current->value) == false) { //if the input set value existence is false
				(*different).add(current->value); //add the current node values to the different set
				counter++; //increment
			}

			current = current->next; //the current node will be the next one each time
		}

		(*different).size = counter;

		return *different;
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size){

	SLLSet *unionSet = new SLLSet();

	for (int i = 0; i < size; i++) {
		*unionSet = (*unionSet).setUnion(sArray[i]);
	}
	return *(unionSet);

}
string SLLSet::toString(){
	string output;
	while (head != NULL) {
		output += to_string(head->value) + ", ";
		head = head->next;

		}

		if (!output.empty()) {
			output.resize(output.size() - 2);
		}

		return output;
	}







