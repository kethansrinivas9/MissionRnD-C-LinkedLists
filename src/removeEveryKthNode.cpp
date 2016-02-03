/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int count;
	struct node *current = head, *temp;
	if (head == NULL || K <= 0) {
		return NULL;
	}
	else if (K == 1) {
		while (current != NULL) {
			temp = current->next;
			current = temp;
		}
		return NULL;
	}
	else {
		while (true) {
			count = 1;
			while (count < K - 1 && current != NULL) {
				count++;
				current = current->next;
			}
			if (current == NULL) return head;
			else {
				if (current->next != NULL) {
					temp = current->next->next;
					current->next = temp;
				}
				current = current->next;
			}
		}
	}
	return head;
}