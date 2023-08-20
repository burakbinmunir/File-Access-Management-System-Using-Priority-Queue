# Priority Queue and File Access Management System

This C++ program demonstrates the implementation of a priority queue and a file access management system using classes. The project includes classes for users, a priority queue, files, a file list, and a hash table.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Classes](#classes)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project showcases the implementation of a max-heap priority queue that is utilized to manage user access to files in a file access management system. It allows users to be assigned priority keys and grants access to files based on these priorities.

## Usage

The project provides implementations for various classes that interact to achieve the file access management system:

1. `User` class: Represents a user with a priority key, user ID, operation type (read or write), and access status.

2. `PriorityQueue` class: Implements a max-heap priority queue. Users can be added to the queue based on their priority keys. It provides functions like `AddToQueue`, `ExtractMax`, `FindMax`, `FindMin`, `IsEmpty`, and `Size`.

3. `File` class: Represents a file with a file name, file ID, number of accessors, and a priority queue of users with access to the file.

4. `FileList` class: Manages a list of files and provides functions like `PrintFileList`, `GrantAccess`, `AddFile`, and `IsEmpty`.

5. `HashTable` class: Implements a hash table for efficient storage and retrieval of files. It offers functions like `InsertFile`, `PrintHash`, and `RequestFileAccess`.

## Classes

1. **User**
   - Represents a user with a priority key, user ID, operation type, and access status.
   - Provides constructors, an overloaded `<<` operator for printing, and a `PrintUser` function.

2. **PriorityQueue**
   - Implements a max-heap priority queue for users.
   - Provides functions to add users, extract the maximum user, find the maximum and minimum users, check if the queue is empty, and get the size.

3. **File**
   - Represents a file with a file name, file ID, accessors queue, and number of accessors.
   - Provides constructors and an overloaded `<<` operator for printing.

4. **FileList**
   - Manages a list of files and provides functions for printing the file list, granting access to files, adding files, and checking if the list is empty.

5. **HashTable**
   - Implements a hash table for file storage and retrieval.
   - Provides functions for inserting files, printing the hash table, and requesting file access.

## Getting Started

### Prerequisites

Ensure you have a C++ compiler installed on your system, such as GCC or Visual C++.

### Installation

1. Clone or download the repository.

2. Open a terminal or command prompt and navigate to the project directory.

3. Compile the code using the appropriate compiler command. For example, using g++:

   ```bash
   g++ main.cpp -o file_access_management
