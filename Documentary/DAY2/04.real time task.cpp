#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Task structure
struct Task {
    int id, priority, execTime, interval;
    Task* next;
    Task(int i, int p, int e, int inter = 0) : id(i), priority(p), execTime(e), interval(inter), next(nullptr) {}
};

// Task Scheduler
class TaskScheduler {
private:
    Task* head = nullptr;

    // Helper to print tasks
    void printTasks() {
        if (!head) { 
            cout << "No tasks in the queue.\n"; 
            return; 
        }
        Task* temp = head;
        cout << "Current Task Queue:\n";
        do {
            cout << "Task " << temp->id << ": Priority " << temp->priority
                 << ", Time " << temp->execTime << "ms";
            if (temp->interval > 0) cout << ", Periodic\n";
            else cout << "\n";
            temp = temp->next;
        } while (temp != head);
    }

public:
    // Add a task to the scheduler
    void addTask(int id, int priority, int execTime, int interval = 0) {
        Task* newTask = new Task(id, priority, execTime, interval);
        if (!head) {
            head = newTask;
            head->next = head; // Circular linked list
        } else {
            Task* prev = nullptr;
            Task* curr = head;

            // Find correct position by priority
            do {
                if (curr->priority < priority) break;
                prev = curr;
                curr = curr->next;
            } while (curr != head);

            // Insert task
            newTask->next = curr;
            if (!prev || curr == head) { // Insert at head
                Task* tail = head;
                while (tail->next != head) tail = tail->next;
                tail->next = newTask;
                if (curr == head) head = newTask;
            } else { // Insert elsewhere
                prev->next = newTask;
            }
        }
        printTasks();
    }

    // Complete the current task
    void completeTask() {
        if (!head) {
            cout << "No tasks to complete.\n";
            return;
        }
        Task* toDelete = head;

        // Handle periodic tasks
        if (head->interval > 0) {
            addTask(head->id, head->priority, head->execTime, head->interval);
        }

        // Remove current task
        if (head->next == head) { // Only one task
            head = nullptr;
        } else {
            Task* tail = head;
            while (tail->next != head) tail = tail->next;
            head = head->next;
            tail->next = head;
        }
        delete toDelete;

        printTasks();
    }

    // Execute tasks in priority order
    void executeTasks() {
        while (head) {
            cout << "Executing Task " << head->id << "...\n";
            this_thread::sleep_for(chrono::milliseconds(head->execTime));
            completeTask();
        }
        cout << "All tasks completed.\n";
    }
};

int main() {
    TaskScheduler scheduler;

    // Add tasks
    scheduler.addTask(1, 3, 1000); // ID, Priority, Execution Time
    scheduler.addTask(2, 1, 2000);
    scheduler.addTask(3, 2, 1500, 3000); // Periodic task

    // Execute tasks
    scheduler.executeTasks();

    return 0;
}
