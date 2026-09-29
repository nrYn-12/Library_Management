#include "header.h"

void save_books(void) {
    FILE *fp = fopen("books.txt", "w");
    int i;

    if (!fp) {
        printf("Could not save books.txt\n");
        return;
    }

    for (i = 0; i < nbooks; i++)
        fprintf(fp, "%d\t%s\t%s\t%d\n", books[i].id, books[i].title, books[i].author, books[i].copies);

    fclose(fp);
}
