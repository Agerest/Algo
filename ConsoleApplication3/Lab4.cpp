#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <stdlib.h>

using namespace std;

struct SimpleQueue {
	char *array = new char[5];
	int length = 5;
	int size = 0;
};

void increaseQueueArray(SimpleQueue *q) {
	char *temp = new char[q->length * 2];
	for (int i = 0; i < q->length; i++) {
		temp[i] = q->array[i];
	}
	q->length *= 2;
	q->array = temp;
}

void push(SimpleQueue *q, char data) {
	if (q->size == q->length) {
		increaseQueueArray(q);
	}
	q->array[q->size++] = data;
}

char pop(SimpleQueue *q) {
	if (q->size == 0) {
		cout << "ќчередь пуста" << endl;
		return '\0';
	}
	char result = q->array[0];
	for (int i = 0; i < q->size - 1; i++) {
		q->array[i] = q->array[i + 1];
	}
	q->size--;
	return result;
}

struct LoopQueue {
	char *array = new char[5];
	int length = 5;
	int size = 0;
	int head = 0;
	int tail = 0;
};

void push(LoopQueue *q, char data) {
	if (q->size == q->length) {
		cout << "ќчередь заполнена" << endl;
		return;
	}
	q->array[q->tail] = data;
	q->size++;
	if (q->tail == q->length - 1) {
		q->tail = 0;
	}
	else {
		q->tail++;
	}
}

char pop(LoopQueue *q) {
	if (q->size == 0) {
		cout << "ќчередь пуста" << endl;
		return '\0';
	}
	char result = q->array[q->head];
	q->size--;
	if (q->head == q->length - 1) {
		q->head = 0;
	}
	else {
		q->head++;
	}
	return result;
}

struct ArrayStack {
	char *array = new char[5];
	int length = 5;
	int size = 0;
};

void increaseStackArray(ArrayStack *s) {
	char *temp = new char[s->length * 2];
	for (int i = 0; i < s->length; i++) {
		temp[i] = s->array[i];
	}
	s->length *= 2;
	s->array = temp;
}

void push(ArrayStack *s, char data) {
	if (s->size == s->length) {
		increaseStackArray(s);
	}
	s->array[s->size++] = data;
}

char pop(ArrayStack *s) {
	if (s->size == 0) {
		cout << "ќчередь пуста" << endl;
		return '\0';
	}
	char result = s->array[s->size - 1];
	s->array[s->size-- - 1] = '\0';
	return result;
}

struct Stack {
	char data;
	Stack *next;
};

void push(Stack *s, char data)
{
	Stack *temp = new Stack;
	temp->data = data;
	temp->next = s;
	s = temp;
}

char pop(Stack *s) {
	char result = s->data;
	Stack head = *s;
	s = s->next;
	delete &head;
	return result;
}


int main()
{
	setlocale(LC_ALL, "rus");

	SimpleQueue simpleQueue;
	LoopQueue loopQueue;
	ArrayStack arrayStack;
	Stack stack;

	char data;

	int i = 0;
	do {
		cout << "1 - push in simple queue" << endl;
		cout << "2 - pop in simple queue" << endl;
		cout << "3 - push in loop queue" << endl;
		cout << "4 - pop in loop queue" << endl;
		cout << "5 - push in array stack" << endl;
		cout << "6 - pop in array stack" << endl;
		cout << "7 - push in stack" << endl;
		cout << "8 - pop in stack" << endl;
		cout << "0 - exit" << endl;
		cin >> i;
		switch (i)
		{
		case 1: {
			cout << "¬ведите элемент: " << endl;
			cin >> data;
			push(&simpleQueue, data);
			break;
		}
		case 3: {
			cout << "¬ведите элемент: " << endl;
			cin >> data;
			push(&loopQueue, data);
			break;
		}
		case 5: {
			cout << "¬ведите элемент: " << endl;
			cin >> data;
			push(&arrayStack, data);
			break;
		}
		case 7: {
			cout << "¬ведите элемент: " << endl;
			cin >> data;
			push(&stack, data);
			break;
		}
		case 2: {
			data = pop(&simpleQueue);
			cout << "Ёлемент: " << data << endl;
			break;
		}
		case 4: {
			data = pop(&loopQueue);
			cout << "Ёлемент: " << data << endl;
			break;
		}
		case 6: {
			data = pop(&arrayStack);
			cout << "Ёлемент: " << data << endl;
			break;
		}
		case 8: {
			data = pop(&stack);
			cout << "Ёлемент: " << data << endl;
			break;
		}
		default:
			break;
		}
	} while (i != 0);


	return 0;
}