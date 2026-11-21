
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Request {
    int id;
    string studentName;
    string department;
    string category;
    string description;
    string priority;
    string status;
};

Request requests[100];
int requestCount = 0;

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

    r.status = "Pending";

    requests[requestCount] = r;
    requestCount++;

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
            return;
        }
    }

    cout << "\nRequest ID not found!\n";
}


int main() {
    int choice;

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
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                submitRequest();
                break;

            case 2:
                viewRequests();
                break;

            case 3:
               case 3:
                  searchRequest();
                break;

            case 4:
                cout << "Update status feature will be added next.\n";
                break;

            case 5:
                cout << "Staff assignment feature will be added next.\n";
                break;

            case 6:
                cout << "Close request feature will be added next.\n";
                break;

            case 7:
                cout << "Emergency management feature will be added next.\n";
                break;

            case 8:
                cout << "Reports feature will be added next.\n";
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
