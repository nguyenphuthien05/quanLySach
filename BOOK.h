#ifndef BOOK_H
#define BOOK_H

typedef struct {
    int id;
    char title[100];
    char author[100];
    int isBorrowed;
} Book;

#endif

