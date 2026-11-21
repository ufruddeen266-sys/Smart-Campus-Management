
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;

struct Request {
    int id;
    string studentName;
    string department;
    string category;
    string description;
    string priority;
    string status;
    string assignedStaff;
    string location;
};

Request requests[100];
int requestCount = 0;

void saveRequests() {
    ofstream file("requests.txt");

    if (!file) {
        cout << "Error saving requests!\n";
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
             << requests[i].location << "\n";
    }

    file.close();
}

void loadRequests() {
    ifstream file("requests.txt");

    if (!file) {
        cout << "No previous records found. Starting new system.\n";
        return;
    }

    string line;

    while (getline(file, line) && requestCount < 100) {
        stringstream ss(line);
        string idText;
        Request r;

        getline(ss, idText, '|');

        if (idText.empty()) {
            continue;
        }

        r.id = stoi(idText);

        getline(ss, r.studentName, '|');
        getline(ss, r.department, '|');
        getline(ss, r.category, '|');
        getline(ss, r.description, '|');
        getline(ss, r.priority, '|');
        getline(ss, r.status, '|');
        getline(ss, r.assignedStaff, '|');
        getline(ss, r.location);

        requests[requestCount] = r;
        requestCount++;
    }

    file.close();
}


void submitRequest() {
    if (requestCount >= 100) {
        cout << "Request storage is full!\n";
        return;
    }

    Request r;

    r.id = requestCount + 1;

    cout << "\nEnter Student Name: ";
    getline(cin, r.studentName);

    cout << "Enter Department: ";
    getline(cin, r.department);

    cout << "Enter Category (Maintenance/Technical/Medical/Other): ";
    getline(cin, r.category);

    cout << "Enter Description: ";
    getline(cin, r.description);

  
cout << "Enter Priority (Low/Medium/High): ";
getline(cin, r.priority);

if (r.studentName.empty() || r.department.empty() ||
    r.category.empty() || r.description.empty()) {
    cout << "\nError: All fields are required!\n";
    return;
}

if (r.priority != "Low" &&
    r.priority != "Medium" &&
    r.priority != "High") {
    cout << "\nInvalid priority! Enter Low, Medium, or High.\n";
    return;
}

r.status = "Pending";
r.assignedStaff = "Not Assigned";
r.location = "";


    requests[requestCount] = r;
    requestCount++;
    saveRequests();

    cout << "\nRequest submitted successfully!\n";
    cout << "Your Request ID is: " << r.id << endl;
}

void viewRequests() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    for (int i = 0; i < requestCount; i++) {
        cout << "\n-------------------------\n";
        cout << "Request ID: " << requests[i].id << endl;
        cout << "Student Name: " << requests[i].studentName << endl;
        cout << "Department: " << requests[i].department << endl;
        cout << "Category: " << requests[i].category << endl;
        cout << "Description: " << requests[i].description << endl;
        cout << "Priority: " << requests[i].priority << endl;
        cout << "Status: " << requests[i].status << endl;
        cout << "Assigned Staff: " << requests[i].assignedStaff << endl;
        cout << "Location: " << requests[i].location << endl;
    }
   
}

void searchRequest() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    int searchID;

    cout << "\nEnter Request ID to search: ";
    cin >> searchID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].id == searchID) {
            cout << "\nRequest Found!\n";
            cout << "Request ID: " << requests[i].id << endl;
            cout << "Student Name: " << requests[i].studentName << endl;
            cout << "Department: " << requests[i].department << endl;
            cout << "Category: " << requests[i].category << endl;
            cout << "Description: " << requests[i].description << endl;
            cout << "Priority: " << requests[i].priority << endl;
            cout << "Status: " << requests[i].status << endl;
            cout << "Assigned Staff: " << requests[i].assignedStaff << endl;
            cout << "Location: " << requests[i].location << endl;
            return;
        }
    }

    cout << "\nRequest ID not found!\n";
}

void updateRequestStatus() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    int updateID;

    cout << "\nEnter Request ID: ";
    cin >> updateID;

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].id == updateID) {

            cout << "\nCurrent Status: " << requests[i].status << endl;

            cout << "\nSelect New Status:\n";
            cout << "1. Pending\n";
            cout << "2. In Progress\n";
            cout << "3. Resolved\n";

            int statusChoice;
            cout << "Enter choice: ";
            cin >> statusChoice;

            switch (statusChoice) {
                case 1:
                    requests[i].status = "Pending";
                    break;

                case 2:
                    requests[i].status = "In Progress";
                    break;

                case 3:
                    requests[i].status = "Resolved";
                    break;

                default:
                    cout << "\nInvalid status choice!\n";
                    return;
            }
            saveRequests();
            cout << "\nRequest status updated successfully!\n";
            return;
        }
    }

    cout << "\nRequest ID not found!\n";
}

void assignStaff() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    int searchID;

    cout << "\nEnter Request ID: ";
    cin >> searchID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].id == searchID) {

            string staffName;

            cout << "Enter Staff Member Name: ";
            getline(cin, staffName);

            if (staffName.empty()) {
                cout << "\nStaff name cannot be empty!\n";
                return;
            }

            requests[i].assignedStaff = staffName;
            saveRequests();
            cout << "\nStaff assigned successfully!\n";
            cout << "Assigned Staff: " << requests[i].assignedStaff << endl;

            return;
        }
    }

    cout << "\nRequest ID not found!\n";
}

void closeRequest() {
    if (requestCount == 0) {
        cout << "\nNo requests available.\n";
        return;
    }

    int closeID;

    cout << "\nEnter Request ID to close: ";
    cin >> closeID;

    for (int i = 0; i < requestCount; i++) {
        if (requests[i].id == closeID) {

            if (requests[i].status == "Closed") {
                cout << "\nThis request is already closed!\n";
                return;
            }

            if (requests[i].status != "Resolved") {
                cout << "\nOnly resolved requests can be closed.\n";
                return;
            }

            requests[i].status = "Closed";
            saveRequests();
            cout << "\nRequest closed successfully!\n";
            return;
        }
    }

    cout << "\nRequest ID not found!\n";
}

void emergencyManagement() {
    if (requestCount >= 100) {
        cout << "\nRequest storage is full!\n";
        return;
    }

    Request r;

    r.id = requestCount + 1;
    r.category = "Emergency";
    r.priority = "High";
    r.status = "Pending";
    r.assignedStaff = "Not Assigned";

    cout << "\n===== EMERGENCY MANAGEMENT =====\n";

    cout << "Enter Your Name: ";
    getline(cin, r.studentName);

    cout << "Enter Department: ";
    getline(cin, r.department);

    cout << "Emergency Type (Medical/Fire/Electrical/Security): ";
    getline(cin, r.description);

    cout << "Enter Emergency Location: ";
    getline(cin, r.location);

    if (r.studentName.empty() || r.location.empty() ||
        r.description.empty()) {
        cout << "\nRequired information cannot be empty!\n";
        return;
    }

    requests[requestCount] = r;
requestCount++;

saveRequests();

cout << "\nEMERGENCY REPORTED SUCCESSFULLY!\n";
    cout << "Emergency ID: " << r.id << endl;
    cout << "Priority: High\n";
    cout << "Status: Pending\n";
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

    cout << "====================================\n";
}


int main() {
    int choice;

    loadRequests();
    do {
        cout << "\n===== SMART CAMPUS MANAGEMENT SYSTEM =====\n";
        cout << "1. Submit New Request\n";
        cout << "2. View All Requests\n";
        cout << "3. Search Request\n";
        cout << "4. Update Request Status\n";
        cout << "5. Assign Staff\n";
        cout << "6. Close Request\n";
        cout << "7. Emergency Management\n";
        cout << "8. Generate Reports\n";
        cout << "9. Exit\n";

        
cout << "\nEnter your choice: ";

if (!(cin >> choice)) {
    cout << "\nInvalid input! Please enter a number.\n";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    choice = 0;
}
else {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


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
                cout << "Thank you for using Smart Campus System!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
