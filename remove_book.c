#include "header.h"

void remove_book(void) {
    int i, p;

    printf("\nRemoving a book...\n");
    if (nbooks == 0) {
        printf("No books in library.\n");
        pause();
        return;
    }

    p = pick_book();
    if (p == -1)
        return;

    for (i = 0; i < nissued; i++) {
        if (issued[i].book_id == books[p].id) {
            printf("This book is issued. Return it first.\n");
            pause();
            return;
        }
    }

    printf("Removed: %s\n", books[p].title);
    for (i = p; i < nbooks - 1; i++)
        books[i] = books[i + 1];
    nbooks--;
    save_books();
    pause();
}
