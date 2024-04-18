#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string priority;
    Task* prev;
    Task* next;
};

class PriorityQueue {
private:
    Task* head;
    Task* tail;

public:
    PriorityQueue() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int id, string priority) {
        Task* newTask = new Task;
        newTask->id = id;
        newTask->priority = priority;
        newTask->prev = nullptr;
        newTask->next = nullptr;

        if (head == nullptr) {
            head = newTask;
            tail = newTask;
        } else if (priority == "HIGH") {
            newTask->next = head;
            head->prev = newTask;
            head = newTask;
        } else {
            Task* curr = head;
            while (curr->next != nullptr && curr->next->id < id) {
                curr = curr->next;
            }
            if (curr == tail) {
                tail->next = newTask;
                newTask->prev = tail;
                tail = newTask;
            } else {
                newTask->next = curr->next;
                newTask->prev = curr;
                curr->next->prev = newTask;
                curr->next = newTask;
            }
        }
    }

    void view() {
        Task* curr = head;
        int count = 1;
        while (curr != nullptr) {
            cout << count << "    " << curr->id << "      " << curr->priority << endl;
            curr = curr->next;
            count++;
        }
    }

    void doOne() {
        if (head == nullptr) {
            cout << "No tasks remaining." << endl;
            return;
        }
        Task* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        cout << "[" << temp->id << "] is DONE. " << (head == nullptr ? "0" : to_string(countTasks())) << " items remaining..." << endl;
        delete temp;
    }

    void doAll() {
        while (head != nullptr) {
            Task* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            cout << "[" << temp->id << "] is DONE." << endl;
            delete temp;
        }
        cout << "0 tasks remaining" << endl;
    }

private:
    int countTasks() {
        Task* curr = head;
        int count = 0;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    PriorityQueue pq;
    string command, id, priority;
    int idNum;

    while (true) {
        cin >> command;
        if (command == "INSERT") {
            cin >> id >> priority;
            idNum = stoi(id);
            pq.insert(idNum, priority);
        } else if (command == "VIEW") {
            pq.view();
        } else if (command == "DO") {
            pq.doOne();
        } else if (command == "DOALL") {
            pq.doAll();
        } else {
            break;
        }
    }

    return 0;
}