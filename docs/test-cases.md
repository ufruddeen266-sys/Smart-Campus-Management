# Smart Campus Management System — Test Cases

## 1. Functional Testing

| Test ID | Test Scenario | Expected Result |
|---|---|---|
| TC-01 | Submit a valid request | Request submitted successfully |
| TC-02 | Submit request with empty fields | Error message displayed |
| TC-03 | Enter invalid priority | Invalid priority message displayed |
| TC-04 | View all requests | All saved requests displayed |
| TC-05 | Search using valid Request ID | Correct request displayed |
| TC-06 | Search using invalid Request ID | Request not found message |
| TC-07 | Update request status | Status updated successfully |
| TC-08 | Assign staff to a request | Staff assigned successfully |
| TC-09 | Close a resolved request | Request closed successfully |
| TC-10 | Close a pending request | System prevents closure |
| TC-11 | Submit an emergency | Emergency recorded with High priority |
| TC-12 | Generate reports | Request statistics displayed |

## 2. Input Validation Testing

- Enter letters instead of a menu number.
- Enter an invalid menu option.
- Enter an empty student name.
- Enter an invalid priority.
- Search for a request ID that does not exist.

## 3. File Handling Testing

- Start the system without an existing requests.txt file.
- Save a new request.
- Restart the program and check whether the request loads again.

## 4. Conclusion

These test cases are designed to verify the main functions, input validation, emergency management, and file handling of the Smart Campus Management System.
