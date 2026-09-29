#include "header.h"

void list_books(void) {
    int i;

    printf("\nListing all books...\n\nBooks List:\n\n");
    if (nbooks == 0) {
        printf("No books available.\n");
        pause();
        return;
    }

    printf("| %-8s | %-28s | %-20s | %-6s |\n", "Books ID", "Books Title", "Author Name", "Copies");
    printf("+----------+------------------------------+----------------------+--------+\n");
    for (i = 0; i < nbooks; i++)
        show_book(books[i]);
    pause();
}
