#include <iostream>

using namespace std;


class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int data) {
        QueueNode* newNode = new QueueNode(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (!isEmpty()) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        } else {
            cout << "The queue is empty. Cannot dequeue." << endl;
        }
    }


    bool isEmpty() {
        return front == nullptr;
    }


    int getFront() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "The queue is empty." << endl;
            return -1; // Sentinel value
        }
    }
};

int main() {

    Queue queue;


    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.getFront() << endl;

    return 0;
}
