#ifndef TODO_H
#define TODO_H

#include <vector>
#include <string>

class TodoList {
private:
    std::vector<std::string> tasks;
    void loadTasks();
    void saveTasks();

public:
    TodoList();
    void addTask(const std::string& task);
    void removeTask(int index);
    void displayTasks() const;
};

#endif // TODO_H
