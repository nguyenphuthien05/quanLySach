#ifndef USER_H
#define USER_H

#define MAX_BORROWED 10

typedef struct {
    int id;
    char name[100];
    int borrowedBookIds[MAX_BORROWED];
    int borrowCount;
} User;

#endif

