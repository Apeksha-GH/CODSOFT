#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for a Task with description and status
struct Task {
    string description;
    bool completed;

    // Constructor to create a new task
    Task(string desc) : description(desc), completed(false) {}
};

// Function declarations
void addTask(vector<Task>& tasks);
void showTasks(const vector<Task>& tasks);
void completeTask(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> toDoList;  // List of tasks
    char option = '0';

    cout << "Hello! Welcome to your To-Do List!\n";

    // Keep the program running until the user chooses to exit
    while (option != '5') {
        // Show available options to the user
        cout << "\nWhat would you like to do?\n";
        cout << "1. Add a Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Mark a Task as Done\n";
        cout << "4. Remove a Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> option;

        // Handle user input based on their choice
        if (option == '1') {
            addTask(toDoList);
        } else if (option == '2') {
            showTasks(toDoList);
        } else if (option == '3') {
            completeTask(toDoList);
        } else if (option == '4') {
            removeTask(toDoList);
        } else if (option == '5') {
            cout << "Goodbye! Have a productive day!\n";
        } else {
            cout << "Oops! Please choose a valid option (1-5).\n";
        }
    }

    return 0;
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    string taskDesc;
    cin.ignore();  // Clear the input buffer before taking user input
    cout << "Enter the task description: ";
    getline(cin, taskDesc);
    tasks.push_back(Task(taskDesc));  // Add the new task to the list
    cout << "Task added successfully!\n";
}

// Function to show all tasks
void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n";
    } else {
        cout << "\nHere are your tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description << " ["
                 << (tasks[i].completed ? "Done" : "Pending") << "]\n";
        }
    }
}

// Function to mark a task as completed
void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n";
        return;
    }

    int taskNumber;
    showTasks(tasks);  // Display the tasks so the user can pick one
    cout << "Enter the number of the task you want to mark as done: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as done!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n";
        return;
    }

    int taskNumber;
    showTasks(tasks);  // Display the tasks so the user can pick one
    cout << "Enter the number of the task you want to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNumber - 1));  // Remove the task
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}
