# Project Documentation

## 1. Introduction

The **Smart Campus Operations and Emergency Response Management System** is a menu-driven C++ application designed to manage campus maintenance requests, staff assignments, campus resources, and emergency situations.

The system provides an organized way to submit, track, search, update, and manage campus-related requests.

## 2. Main System Modules

The application contains the following 11 menu options:

1. Submit New Request
2. View All Requests
3. Search Request
4. Update Request Status
5. Assign Staff
6. Close Request
7. Emergency Management
8. Generate Reports
9. Campus Resource Matrix
10. View Requests by Priority
11. Exit

## 3. Request Management

Each request contains information such as:

- Request ID
- Request title and description
- Request category
- Priority level
- Request status
- Building and room location
- Assigned staff member

## 4. Request Status

The system supports four request statuses:

- Pending
- In Progress
- Resolved
- Closed

## 5. Emergency Management

The system supports different emergency categories:

- Medical
- Fire
- Electrical
- Security

Emergency requests can be managed through the Emergency Management module.

## 6. Priority Management

Requests can be filtered and displayed according to their priority levels. The system also uses recursion to count high-priority requests.

## 7. Campus Resource Management

The Campus Resource Matrix uses a two-dimensional array to represent campus resource usage.

Nested loops are used to display and process the resource matrix. The matrix data is maintained during the program session.

## 8. Data Management and File Handling

The system uses file handling to save and retrieve request records through a text file named `requests.txt`.

Existing requests are loaded when the application starts, and updated records are saved to the file.

## 9. Error Handling and Input Validation

The application includes validation and error handling for:

- Invalid menu choices
- Empty required fields
- Invalid numeric input
- Duplicate request IDs
- Invalid request IDs
- Invalid priorities
- Incorrect request data
- File loading and saving errors

## 10. C++ Programming Concepts Used

The project demonstrates the following programming concepts:

- Conditional statements (`if`, `else`, and `switch`)
- Loops (`for`, `while`, and `do-while`)
- Nested loops and nested decisions
- Modular programming using functions
- Function overloading
- Recursion
- One-dimensional arrays
- Two-dimensional arrays
- Structures and nested structures
- Pointers
- Dynamic memory allocation and deallocation
- Strings
- File handling
- Passing structures by value and reference
- Input validation

## 11. Future Improvements

Possible future improvements include:

- Database integration
- Graphical user interface
- Login and role-based access
- Real-time emergency notifications
- Advanced resource tracking
- More detailed reporting and analytics

## 12. Conclusion

The Smart Campus Operations and Emergency Response Management System demonstrates the practical use of fundamental C++ programming concepts in a campus management application. It combines request handling, emergency management, file storage, resource management, and priority-based filtering in one system.
