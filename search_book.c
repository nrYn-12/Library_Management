#include "header.h"

void search_book(void) {
    int p;

    printf("\nSearching a book...\n");
    if (nbooks == 0) {
        printf("No books in library.\n");
        pause();
        return;
    }

    p = pick_book();
    if (p == -1)
        return;

    printf("\nBook found:\n");
    printf("| %-8s | %-28s | %-20s | %-6s |\n", "Books ID", "Books Title", "Author Name", "Copies");
    show_book(books[p]);
    pause();
}
