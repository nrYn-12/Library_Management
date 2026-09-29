#include "header.h"

void load_issued(void) {
    FILE *fp = fopen("issued.txt", "r");

    nissued = 0;
    if (!fp)
        return;

    while (nissued < MAX &&
           fscanf(fp, "%d\t%d\t%79[^\t]\t%79[^\t]\t%31[^\t]\n",
                  &issued[nissued].issue_id,
                  &issued[nissued].book_id,
                  issued[nissued].title,
                  issued[nissued].student,
                  issued[nissued].date) == 5)
        nissued++;

    fclose(fp);
}
