#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
#include "user.h"
#define MAX_BOOKS 100
#define MAX_USERS 50
extern Book library[MAX_BOOKS];
extern User users[MAX_USERS];

extern int bookCount;
extern int userCount;
void addBook();
void addUser();
int findBookIndex(int bookId);
int findUserIndex(int userId);
void borrowBook();
void returnBook();
#endif

