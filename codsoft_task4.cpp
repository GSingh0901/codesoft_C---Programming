#include <iostream>
#include <vector>
using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;
};

// Function to display the menu
void displayMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks; // Vector to store tasks
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    Task newTask;
                    cout << "Enter task description: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, newTask.description);
                    newTask.completed = false;
                    tasks.push_back(newTask);
                    cout << "Task added!" << endl;
                    break;
                }
            case 2:
                cout << "Tasks:" << endl;
                for (size_t i = 0; i < tasks.size(); i++) {
                    cout << (i + 1) << ". ";
                    if (tasks[i].completed) {
                        cout << "[X] ";
                    } else {
                        cout << "[ ] ";
                    }
                    cout << tasks[i].description << endl;
                }
                break;
            case 3:
                if (tasks.empty()) {
                    cout << "No tasks to mark as completed." << endl;
                } else {
                    int taskIndex;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskIndex;
                    markTaskCompleted(tasks, taskIndex);
                }
                break;
            case 4:
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                } else {
                    int taskIndex;
                    cout << "Enter the task number to delete: ";
                    cin >> taskIndex;
                    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                        tasks.erase(tasks.begin() + (taskIndex - 1));
                        cout << "Task deleted!" << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
