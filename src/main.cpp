
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <new>
using namespace std;

struct Location {
    string building;
    string room;
};

struct Request {
    int id;
    string studentName;
    string department;
    string category;
    string description;
    string priority;
    string status;
    string assignedStaff;
    Location location;
};

Request requests[100];
int requestCount = 0;
int nextRequestId = 1;

// Function Category 1: No parameters, no return value
void showWelcome() {
    cout << "\n========================================\n";
    cout << "     SMART CAMPUS MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
}

// Function Category 2: Parameters, no return value
void printSeparator(string symbol, int count) {
    for (int i = 0; i < count; i++) {
        cout << symbol;
    }
    cout << endl;
}

// Function Category 3: No parameters, returns a value
int getMenuChoice() {
    int choice;

    cout << "\n1. Submit New Request\n";
    cout << "2. View All Requests\n";
    cout << "3. Search Request\n";
    cout << "4. Update Request Status\n";
    cout << "5. Assign Staff\n";
    cout << "6. Close Request\n";
    cout << "7. Emergency Management\n";
    cout << "8. Generate Reports\n";
    cout << "9. Campus Resource Matrix\n";
    cout << "10. View Requests by Priority\n";
    cout << "11. Exit\n";

    cout << "\nEnter your choice: ";

    while (!(cin >> choice)) {
        cout << "Invalid input! Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

// Function Category 4: Parameters, returns a value
int findRequestIndex(int id) {
    for (int i = 0; i < requestCount; i++) {
        if (requests[i].id == id) {
            return i;
        }
    }

    return -1;
}

string readText(string prompt) {
    string value;

    while (true) {
        cout << prompt;
        getline(cin, value);

        if (value.empty()) {
            cout << "This field cannot be empty!\n";
        }
        else if (value.find('|') != string::npos) {
            cout << "The | character is not allowed!\n";
        }
        else {
            return value;
        }
    }
}

int readNumber(string prompt) {
    int number;

    cout << prompt;

    while (!(cin >> number)) {
        cout << "Invalid input! Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

// Structure passed by value
void printRequestSummary(Request r) {
    cout << "\nRequest ID: " << r.id;
    cout << "\nStudent: " << r.studentName;
    cout << "\nCategory: " << r.category;
    cout << "\nPriority: " << r.priority;
    cout << "\nStatus: " << r.status << endl;
}

// Structure passed by reference
void updateLocation(Request &r) {
    r.location.building = readText("Enter Building: ");
    r.location.room = readText("Enter Room Number: ");
}

// Function Overloading: Version 1
void displayRequest(const Request &r) {
    printSeparator("-", 35);

    cout << "Request ID: " << r.id << endl;
    cout << "Student Name: " << r.studentName << endl;
    cout << "Department: " << r.department << endl;
    cout << "Category: " << r.category << endl;
    cout << "Description: " << r.description << endl;
    cout << "Priority: " << r.priority << endl;
    cout << "Status: " << r.status << endl;
    cout << "Assigned Staff: " << r.assignedStaff << endl;
    cout << "Building: " << r.location.building << endl;
    cout << "Room: " << r.location.room << endl;

    printSeparator("-", 35);
}

// Function Overloading: Version 2
void displayRequest(int id) {
    int index = findRequestIndex(id);

    if (index != -1) {
        displayRequest(requests[index]);
    }
    else {
        cout << "\nRequest ID not found!\n";
    }
}

void saveRequests() {
    ofstream file("requests.txt");

    if (!file) {
        cout << "\nError saving requests! Check file access.\n";
        return;
    }

    for (int i = 0; i < requestCount; i++) {
        file << requests[i].id << "|"
             << requests[i].studentName << "|"
             << requests[i].department << "|"
             << requests[i].category << "|"
             << requests[i].description << "|"
             << requests[i].priority << "|"
             << requests[i].status << "|"
             << requests[i].assignedStaff << "|"
             << requests[i].location.building << "|"
             << requests[i].location.room << "\n";
    }

    file.close();
}

void loadRequests() {
    ifstream file("requests.txt");

    if (!file) {
        cout << "\nNo previous records found. Starting new system.\n";
        return;
    }

    string line;
    int maximumID = 0;

    while (getline(file, line) && requestCount < 100) {
        stringstream ss(line);
        Request r;
        string idText;

        if (!getline(ss, idText, '|')) {
            continue;
        }

        try {
            size_t position;
            r.id = stoi(idText, &position);

            if (position != idText.length() || r.id <= 0) {
                continue;
            }
        }
        catch (...) {
            continue;
        }

        if (!getline(ss, r.studentName, '|') ||
            !getline(ss, r.department, '|') ||
            !getline(ss, r.category, '|') ||
            !getline(ss, r.description, '|') ||
            !getline(ss, r.priority, '|') ||
            !getline(ss, r.status, '|') ||
            !getline(ss, r.assignedStaff, '|') ||
            !getline(ss, r.location.building, '|') ||
            !getline(ss, r.location.room)) {
            continue;
        }

        if (findRequestIndex(r.id) != -1) {
            continue;
        }

        requests[requestCount] = r;
        requestCount++;

        if (r.id > maximumID) {
            maximumID = r.id;
        }
    }

    nextRequestId = maximumID + 1;

    file.close();

    cout << "\nPrevious records loaded successfully.\n";
}

// Recursive function
int countHighPriorityRequests(int index) {
    if (index >= requestCount) {
        return 0;
    }

    if (requests[index].priority == "High") {
        return 1 + countHighPriorityRequests(index + 1);
    }

    return countHighPriorityRequests(index + 1);
}

void submitRequest() {
    if (requestCount >= 100) {
        cout << "\nRequest storage is full!\n";
        return;
    }

    Request r;

    r.id = nextRequestId++;

    cout << "\n===== SUBMIT NEW REQUEST =====\n";

    r.studentName = readText("Enter Student Name: ");
    r.department = readText("Enter Department: ");
    r.category = readText("Enter Category: ");
    r.description = readText("Enter Description: ");

    while (true) {
        r.priority = readText("Enter Priority (Low/Medium/High): ");

        if (r.priority == "Low" ||
            r.priority == "Medium" ||
            r.priority == "High") {
            break;
        }

        cout << "Invalid priority! Try again.\n";
    }

    updateLocation(r);

    r.status = "Pending";
    r.assignedStaff = "Not Assigned";

    requests[requestCount] = r;
    requestCount++;

    saveRequests();

    cout << "\nRequest submitted successfully!\n";
    cout << "Your Request ID: " << r.id << endl;
}

void viewRequests() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    for (int i = 0; i < requestCount; i++) {
        displayRequest(requests[i]);
    }
}

void searchRequest() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    int id = readNumber("\nEnter Request ID: ");
    displayRequest(id);
}

void updateRequestStatus() {
    int id = readNumber("\nEnter Request ID: ");
    int index = findRequestIndex(id);

    if (index == -1) {
        cout << "\nRequest ID not found!\n";
        return;
    }

    cout << "\n1. Pending\n";
    cout << "2. In Progress\n";
    cout << "3. Resolved\n";

    int choice = readNumber("Select New Status: ");

    switch (choice) {
        case 1:
            requests[index].status = "Pending";
            break;

        case 2:
            requests[index].status = "In Progress";
            break;

        case 3:
            requests[index].status = "Resolved";
            break;

        default:
            cout << "\nInvalid status choice!\n";
            return;
    }

    saveRequests();
    cout << "\nStatus updated successfully!\n";
}

void assignStaff() {
    int id = readNumber("\nEnter Request ID: ");
    int index = findRequestIndex(id);

    if (index == -1) {
        cout << "\nRequest ID not found!\n";
        return;
    }

    requests[index].assignedStaff =
        readText("Enter Staff Member Name: ");

    saveRequests();

    cout << "\nStaff assigned successfully!\n";
}

void closeRequest() {
    int id = readNumber("\nEnter Request ID: ");
    int index = findRequestIndex(id);

    if (index == -1) {
        cout << "\nRequest ID not found!\n";
        return;
    }

    if (requests[index].status == "Closed") {
        cout << "\nThis request is already closed!\n";
        return;
    }

    if (requests[index].status != "Resolved") {
        cout << "\nOnly resolved requests can be closed.\n";
        return;
    }

    requests[index].status = "Closed";

    saveRequests();

    cout << "\nRequest closed successfully!\n";
}

void emergencyManagement() {
    if (requestCount >= 100) {
        cout << "\nRequest storage is full!\n";
        return;
    }

    Request r;

    r.id = nextRequestId++;
    r.category = "Emergency";
    r.priority = "High";
    r.status = "Pending";
    r.assignedStaff = "Not Assigned";

    cout << "\n===== EMERGENCY MANAGEMENT =====\n";

    r.studentName = readText("Enter Your Name: ");
    r.department = readText("Enter Department: ");
    r.description = readText("Enter Emergency Type: ");

    updateLocation(r);

    requests[requestCount] = r;
    requestCount++;

    saveRequests();

    cout << "\nEMERGENCY REPORTED SUCCESSFULLY!\n";
    cout << "Emergency ID: " << r.id << endl;
}

void generateReports() {
    int pending = 0;
    int inProgress = 0;
    int resolved = 0;
    int closed = 0;
    int emergencies = 0;

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].status == "Pending") {
            pending++;
        }
        else if (requests[i].status == "In Progress") {
            inProgress++;
        }
        else if (requests[i].status == "Resolved") {
            resolved++;
        }
        else if (requests[i].status == "Closed") {
            closed++;
        }

        if (requests[i].category == "Emergency") {
            emergencies++;
        }
    }

    cout << "\n===== CAMPUS OPERATIONS REPORT =====\n";

    cout << "Total Requests: " << requestCount << endl;
    cout << "Pending Requests: " << pending << endl;
    cout << "In Progress Requests: " << inProgress << endl;
    cout << "Resolved Requests: " << resolved << endl;
    cout << "Closed Requests: " << closed << endl;
    cout << "Total Emergencies: " << emergencies << endl;

    cout << "High Priority Requests: "
         << countHighPriorityRequests(0) << endl;

    printSeparator("=", 38);
}

// 2D array and nested loops
void campusResourceMatrix() {
    static int resourceUsage[3][4] = {};

    cout << "\n===== CAMPUS RESOURCE USAGE MATRIX =====\n";
    cout << "Buildings: 1, 2, 3\n";
    cout << "Time Slots: 1, 2, 3, 4\n";

    cout << "\n1. Record Resource Usage\n";
    cout << "2. Display Resource Matrix\n";

    int choice = readNumber("Enter choice: ");

    if (choice == 1) {
        int building = readNumber("Enter Building Number (1-3): ");
        int slot = readNumber("Enter Time Slot (1-4): ");

        if (building < 1 || building > 3 ||
            slot < 1 || slot > 4) {
            cout << "\nInvalid building or time slot!\n";
            return;
        }

        resourceUsage[building - 1][slot - 1]++;

        cout << "\nResource usage recorded successfully!\n";
    }
    else if (choice == 2) {
        cout << "\nBuilding\t";

        for (int j = 0; j < 4; j++) {
            cout << "Slot " << j + 1 << "\t";
        }

        cout << endl;

        // Nested loops
        for (int i = 0; i < 3; i++) {
            cout << "Building " << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << resourceUsage[i][j] << "\t";
            }

            cout << endl;
        }
    }
    else {
        cout << "\nInvalid choice!\n";
    }
}

// Pointers and dynamic memory allocation
void viewRequestsByPriority() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    string priority = readText(
        "\nEnter Priority to filter (Low/Medium/High): "
    );

    if (priority != "Low" &&
        priority != "Medium" &&
        priority != "High") {
        cout << "\nInvalid priority!\n";
        return;
    }

    // Dynamically allocate memory using a pointer
    Request* filteredRequests = new Request[requestCount];

    int filteredCount = 0;

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].priority == priority) {
            filteredRequests[filteredCount] = requests[i];
            filteredCount++;
        }
    }

    cout << "\n===== FILTERED REQUESTS =====\n";

    if (filteredCount == 0) {
        cout << "No requests found for this priority.\n";
    }
    else {
        for (int i = 0; i < filteredCount; i++) {
            displayRequest(filteredRequests[i]);
        }
    }

    // Safely release dynamically allocated memory
    delete[] filteredRequests;
    filteredRequests = nullptr;
}

int main() {
    showWelcome();

    loadRequests();

    int choice;

    do {
        showWelcome();

        choice = getMenuChoice();

        switch (choice) {
            case 1:
                submitRequest();
                break;

            case 2:
                viewRequests();
                break;

            case 3:
                searchRequest();
                break;

            case 4:
                updateRequestStatus();
                break;

            case 5:
                assignStaff();
                break;

            case 6:
                closeRequest();
                break;

            case 7:
                emergencyManagement();
                break;

            case 8:
                generateReports();
                break;

            case 9:
                campusResourceMatrix();
                break;

            case 10:
                viewRequestsByPriority();
                break;

            case 11:
                cout << "\nThank you for using Smart Campus System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
