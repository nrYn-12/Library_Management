#include "header.h"

void menu(void) {
    printf("\n--------------------------------------------\n");
    printf("          LIBRARY MANAGEMENT SYSTEM\n");
    printf("--------------------------------------------\n");
    printf("  1. Add Book\n");
    printf("  2. Remove Book\n");
    printf("  3. Search Book\n");
    printf("  4. List Books\n");
    printf("  5. Save Books\n");
    printf("  6. Issue Book\n");
    printf("  7. Return Book\n");
    printf("  8. List Issued Books\n");
    printf("  9. Save Issued Books Details\n");
    printf("  0. Exit\n");
    printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void search_menu(void) {
    printf("\n        BOOK SEARCH MENU\n");
    printf("+-------------------------------------+\n");
    printf("|  1. Search by Book ID               |\n");
    printf("|  2. Search by Book Title            |\n");
    printf("|  0. Return to Main Menu             |\n");
    printf("+-------------------------------------+\n");
}
