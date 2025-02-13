#include "todo.h"
#include <iostream>
#include <fstream>

using namespace std;

TodoList::TodoList() {
    loadTasks();
}

void TodoList::loadTasks() {
    ifstream file("tasks.txt");
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();
}

void TodoList::saveTasks() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task << endl;
    }
    file.close();
}

void TodoList::addTask(const string& task) {
    tasks.push_back(task);
    saveTasks();
    cout << "Task added!\n";
}

void TodoList::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        saveTasks();
        cout << "Task removed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void TodoList::displayTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}
