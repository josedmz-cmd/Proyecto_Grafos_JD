#pragma once

template <typename E>
class Queue {
public:
	Queue() {}
	Queue(const Queue<E>&) = delete;
	void operator=(const Queue<E>&) = delete;
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E front_value() = 0;
	virtual void clear() = 0;
	virtual bool is_empty() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};

