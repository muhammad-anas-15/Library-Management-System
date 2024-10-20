# Library Management System

## Overview

The Library Management System is a C++ application that allows users to manage a collection of books. The system provides functionalities for adding books, searching for books by genre, and displaying all available books. This project demonstrates object-oriented programming principles such as encapsulation, dynamic memory management, and user interaction.

## Features

- **Add Book:** Add a new book to the library's collection, specifying the title, author, genre, and availability status.
- **Find Book:** Search for books by genre and display available books that match the specified genre.
- **Display All Books:** View details of all books in the library.

## Requirements

To compile and run the project, you need:

- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ programming concepts

## Code Structure

The project consists of two main classes:

1. **Book Class**
   - Manages individual book properties: `title`, `author`, `genre`, and `availability_status`.
   - Implements getter and setter methods to ensure encapsulation.

2. **Library Class**
   - Manages a collection of `Book` objects using a dynamic array.
   - Contains methods to add books, display available books by genre, and display all books.

## Usage

1. Compile the code using a C++ compiler:

   ```bash
   g++ -o LibraryManagementSystem main.cpp


***Library Management System***

    Press[1]. Add Book
    
    Press[2]. Find Book
    
    Press[3]. Display All Books
    
    Press[0]. Exit
