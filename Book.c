#include <stdio.h>
#include "library.h"
void printMenu() {
    printf("\n===== LIBRARY MENU =====\n");
    printf("1. Them sach\n");
    printf("2. Them nguoi dung\n");
    printf("3. Muon sach\n");
    printf("4. Tra sach\n");
    printf("0. Thoat\n");
    printf("Chon: ");
}
int main() {
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addUser();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}

