/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *current, *iter, *min;
	int temp;
	if (head == NULL) {
		return NULL;
	}
	current = head;
	while (current != NULL) {
		iter = current->next;
		min = current;
		while (iter != NULL) {
			if (iter->num < min->num) {
				min = iter;
			}
			iter = iter->next;
		}
		if (min == current) {
			current = current->next;
			continue;
		}
		temp = current->num;
		current->num = min->num;
		min->num = temp;
		current = current->next;
	}
	return head;
}