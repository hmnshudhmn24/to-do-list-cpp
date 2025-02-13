#include "todo.h"
#include <iostream>

using namespace std;

int main() {
    TodoList todoList;
    int choice;
    string task;
    int index;

    while (true) {
        cout << "\n1. Add Task\n2. Remove Task\n3. View Tasks\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.displayTasks();
                cout << "Enter task number to remove: ";
                cin >> index;
                todoList.removeTask(index - 1);
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
