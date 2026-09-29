#include "header.h"

void issue_book(void) {
    Issued rec;
    int i, p, max_id = 0;

    printf("\nIssuing a book...\n");
    if (nbooks == 0) {
        printf("No books in library.\n");
        pause();
        return;
    }

    p = pick_book();
    if (p == -1)
        return;

    if (books[p].copies <= 0) {
        printf("No copies left.\n");
        pause();
        return;
    }

    printf("Enter Student Name: ");
    get_line(rec.student, LEN);

    for (i = 0; i < nissued; i++)
        if (issued[i].issue_id > max_id)
            max_id = issued[i].issue_id;

    rec.issue_id = max_id + 1;
    rec.book_id = books[p].id;
    strcpy(rec.title, books[p].title);
    now_str(rec.date);   /* system clock */

    issued[nissued++] = rec;
    books[p].copies--;
    save_books();
    save_issued();

    printf("\nIssued to %s. Issue ID: %d\n", rec.student, rec.issue_id);
    printf("Issue date (auto): %s\n", rec.date);
    printf("Return within 3 days to avoid fine.\n");
    pause();
}
