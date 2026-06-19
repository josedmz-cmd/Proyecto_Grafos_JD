#pragma once //Solo pase una vez

template <typename E>
class Stack {
public:
	Stack() {};
	Stack(const Stack<E>& other) = delete; //se puede quitar el other
	void operator=(const Stack<E>&) = delete;
	virtual ~Stack() {} //destructor, para que todas las clases puedan sobreescrirlo
	virtual void push(E element) = 0; //No tiene implementación
	virtual E pop() = 0; //virtual: el método se puede volver a definir en una subclase
	virtual E top_value() = 0;
	virtual void clear() = 0;
	virtual bool is_empty() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};