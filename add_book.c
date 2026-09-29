#include "header.h"

void add_book(void) {
    Book b;
    int i, max_id = 0;

    printf("\nAdding a book...\n");
    printf("Enter the Book details:\n");

    printf("Enter the Title: ");
    get_line(b.title, LEN);
    printf("Enter the Author Name: ");
    get_line(b.author, LEN);
    printf("Enter the Number of Copies: ");
    b.copies = get_int();

    if (b.title[0] == 0 || b.copies <= 0) {
        printf("Invalid details.\n");
        pause();
        return;
    }

    for (i = 0; i < nbooks; i++)
        if (books[i].id > max_id)
            max_id = books[i].id;

    b.id = max_id + 1;
    books[nbooks++] = b;
    save_books();   /* keep file updated even if window is closed */

    printf("\nBook added with ID %d.\n", b.id);
    pause();
}
