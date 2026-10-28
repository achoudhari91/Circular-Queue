#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Insert student ID
    void insert(int id) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full!\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = id;

        cout << "Student ID " << id
             << " added to queue.\n";
    }

    // Delete student ID after issuing pass
    void issuePass() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Bus pass issued to Student ID "
             << queue[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display circular queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Students waiting: ";

        int i = front;
        while (true) {
            cout << queue[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, id;

    do {
        cout << "\n--- Bus Pass Distribution System ---\n";
        cout << "1. Insert Student ID\n";
        cout << "2. Issue Bus Pass\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                q.insert(id);
                break;

            case 2:
                q.issuePass();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
