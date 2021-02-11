#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H

class DynIntQueue {
	private:
		struct QueueNode {
			int value;
			QueueNode *next;
		};
		QueueNode *front;
		QueueNode *rear;
		int numItems;
	public:
		DynIntQueue();
		~DynIntQueue();
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty();
		void clear();
};

#endif
