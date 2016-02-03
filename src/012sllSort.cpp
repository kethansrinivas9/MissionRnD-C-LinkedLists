/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node *current = head;
	int arr[3] = { 0 }, i = 0;
	if (head == NULL) {
		return;
	}
	while (current != NULL) {
		arr[current->data]++;
		current = current->next;
	}
	current = head;
	while (current != NULL) {
		if (arr[i] != 0) {
			current->data = i;
			arr[i]--;
			current = current->next;
		}
		else i++;
	}
	return;
}