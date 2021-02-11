#include <bits/stdc++.h>
#include "DynIntQueue.h"

using namespace std;

DynIntQueue::DynIntQueue(void) {
	front = NULL;
	rear = NULL;
	numItems = 0;
}

void DynIntQueue::enqueue(int num) {
	QueueNode *newNode;
	newNode = new QueueNode;
	newNode->value = num;
	newNode->next = NULL;
	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}

void DynIntQueue::dequeue(int &num) {
	QueueNode *temp;
	if (isEmpty()) {
		cout << "The queue is empty.\n";
	} else {
		num = front->value;
		temp = front->next;
		delete front;
		front = temp;
		numItems--;
	}
}

bool DynIntQueue::isEmpty() {
	bool status;
	if (numItems) {
		status = false;
	} else {
		status = true;
	}
	return status;
}

void DynIntQueue::clear() {
	int value;
	while(!isEmpty()) {
		dequeue(value);
	}
}

DynIntQueue::~DynIntQueue() {
	clear();
}

int main() {
	DynIntQueue iQueue;
	cout << "Enqueuing 5 items...\n";
	for (int x = 0; x < 5; x++) {
		iQueue.enqueue(x);
	}
	cout << "The values in the queue were:\n";
	while(!iQueue.isEmpty()) {
		int value;
		iQueue.dequeue(value);
		cout << value << " ";
	}
	cout << endl;
	return 0;
}
