
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       SMART CAMPUS MANAGEMENT\n";
        cout << "====================================\n";

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

        switch (choice)
        {
            case 1:
                cout << "Submit New Request\n";
                break;

            case 2:
                cout << "View All Requests\n";
                break;

            case 3:
                cout << "Search Request\n";
                break;

            case 4:
                cout << "Update Request Status\n";
                break;

            case 5:
                cout << "Assign Staff\n";
                break;

            case 6:
                cout << "Close Request\n";
                break;

            case 7:
                cout << "Emergency Management\n";
                break;

            case 8:
                cout << "Generate Reports\n";
                break;

            case 9:
                cout << "Thank you for using Smart Campus Management!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
