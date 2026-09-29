#include "header.h"

void load_books(void) {
    FILE *fp = fopen("books.txt", "r");

    nbooks = 0;
    if (!fp)
        return;

    while (nbooks < MAX &&
           fscanf(fp, "%d\t%79[^\t]\t%79[^\t]\t%d\n",
                  &books[nbooks].id,
                  books[nbooks].title,
                  books[nbooks].author,
                  &books[nbooks].copies) == 4)
        nbooks++;

    fclose(fp);
}
