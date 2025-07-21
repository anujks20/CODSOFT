#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};


void showMenu() {
    cout << "\n====== TO-DO LIST MANAGER ======\n";
    cout << "1. Add a new task\n";
    cout << "2. View all tasks\n";
    cout << "3. Mark a task as completed\n";
    cout << "4. Remove a task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}


void addTask(vector<Task>& tasks) {
    string desc;
    cin.ignore();
    cout << "Enter task description: ";
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully.\n";
}


void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }

    cout << "\n---- Your Tasks ----\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << "\n";
    }
}


void markCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }

    int num;
    cout << "Enter task number to mark as completed: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}


void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int num;
    cout << "Enter task number to remove: ";
    cin >> num;

    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed successfully.\n";
    }
}

int main() {
    vector<Task> taskList;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(taskList); break;
            case 2: viewTasks(taskList); break;
            case 3: markCompleted(taskList); break;
            case 4: removeTask(taskList); break;
            case 5: cout << "Goodbye! \n"; break;
            default: cout << "Please enter a valid option (1–5).\n";
        }

    } while (choice != 5);

    return 0;
}

