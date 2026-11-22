
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
| TC-13 | Record campus resource usage | Resource usage recorded |
| TC-14 | Display resource matrix | Two-dimensional matrix displayed |
| TC-15 | Filter requests by High priority | Only High priority requests displayed |
| TC-16 | Filter requests with no matching priority | No matching requests message displayed |
| TC-17 | Enter invalid building number | Error message displayed |
| TC-18 | Enter invalid time slot | Error message displayed |

## 2. Input Validation Testing

- Enter letters instead of a menu number.
- Enter an invalid menu option.
- Enter an empty student name.
- Enter an invalid priority.
- Search for a request ID that does not exist.
- Enter an invalid building number.
- Enter an invalid resource time slot.
- Enter an empty staff name.
- Enter a description containing the restricted file delimiter.

## 3. File Handling Testing

- Start the system without an existing requests.txt file.
- Save a new request.
- Restart the program and check whether the request loads again.
- Load records containing invalid data.
- Check that duplicate request IDs are skipped.

## 4. Programming Concepts Testing

- Test all four function categories.
- Test recursive high-priority request counting.
- Test function overloading.
- Test one-dimensional request storage.
- Test two-dimensional campus resource matrix.
- Test nested structures for building and room information.
- Test pointer-based dynamic memory allocation.
- Verify dynamic memory is released using delete[].
- Test structure passing by value and reference.
- Test nested loops in the resource matrix.

## 5. Conclusion

These test cases verify the functional features, input validation, file handling, emergency management, campus resource matrix, and C++ programming concepts implemented in the Smart Campus Management System.
