#include "library.h"
#include<stdio.h>
Book library[MAX_BOOKS];
User users[MAX_USERS];

int bookCount = 0;
int userCount = 0;
int findBookIndex(int bookId) {
	int i;
    for ( i = 0; i < bookCount; i++) {
        if (library[i].id == bookId) {
            return i;
        }
    }
    return -1;
}

int findUserIndex(int userId) {
	int i;
    for (i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            return i;
        }
    }
    return -1;
}
void addBook() {
    int id;
    printf("Nhap ID sach: "	);
    scanf("%d", &id);
    if (findBookIndex(id) != -1) {
        printf("ID sach da ton tai\n");
        return;
    }
    library[bookCount].id = id;
    printf("Nhap ten sach: ");
    scanf(" %[^\n]", library[bookCount].title);
    printf("Nhap tac gia: ");
    scanf(" %[^\n]", library[bookCount].author);
    library[bookCount].isBorrowed = 0;
	bookCount++;
    printf("Them sach thanh cong\n");
}
void borrowBook() {
	int bookId, userId;
	printf("Nhap ID sach: ");
	scanf("%d", &bookId);
	int bookIndex = findBookIndex(bookId);
	if (bookIndex == -1) {
    	printf("Khong tim thay sach!\n");
    	return;
}
	if (library[bookIndex].isBorrowed == 1) {
    	printf("Sach da duoc muon!\n");
    	return;
}
	printf("Nhap ID nguoi muon: ");
	scanf("%d", &userId);
	int userIndex = findUserIndex(userId);
	if (userIndex == -1) {
    	printf("Khong tim thay nguoi dung!\n");
    	return;
}
	library[bookIndex].isBorrowed = 1;
	users[userIndex].borrowedBookIds[users[userIndex].borrowCount] = bookId;
	users[userIndex].borrowCount++;
	printf("Muon sach thanh cong!\n");
}
void returnBook() {
	int bookId;
	printf("Nhap ID sach can tra: ");
	scanf("%d", &bookId);
	int bookIndex = findBookIndex(bookId);
	if (bookIndex == -1) {
    	printf("Khong tim thay sach!\n");
    	return;
	}
	if (library[bookIndex].isBorrowed == 0) {
    	printf("Sach chua duoc muon!\n");
    	return;
	}
	int userId;
	printf("Nhap ID nguoi tra: ");
	scanf("%d", &userId);
	int userIndex = findUserIndex(userId);
	if (userIndex == -1) {
    	printf("Khong tim thay nguoi dung!\n");
    	return;
}
	int found = -1;
	int i;
	for ( i = 0; i < users[userIndex].borrowCount; i++) {
    if (users[userIndex].borrowedBookIds[i] == bookId) {
        found = i;
        break;
    }
}
	if (found == -1) {
    	printf("Nguoi dung khong muon sach nay!\n");
    	return;
}
	library[bookIndex].isBorrowed = 0;
	for (i = found; i < users[userIndex].borrowCount - 1; i++) {
    	users[userIndex].borrowedBookIds[i] =
        users[userIndex].borrowedBookIds[i + 1];
}
	users[userIndex].borrowCount--;
	printf("Tra sach thanh cong!\n");
}
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Danh sach nguoi dung da day!\n");
        return;
    }

    int id;
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &id);

    if (findUserIndex(id) != -1) {
        printf("ID nguoi dung da ton tai!\n");
        return;
    }

    users[userCount].id = id;

    printf("Nhap ten nguoi dung: ");
    scanf(" %[^\n]", users[userCount].name);

    users[userCount].borrowCount = 0;
    userCount++;

    printf("Them nguoi dung thanh cong!\n");
}
