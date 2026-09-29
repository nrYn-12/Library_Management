#include "header.h"

void save_issued(void) {
    FILE *fp = fopen("issued.txt", "w");
    int i;

    if (!fp) {
        printf("Could not save issued.txt\n");
        return;
    }

    for (i = 0; i < nissued; i++)
        fprintf(fp, "%d\t%d\t%s\t%s\t%s\n",
                issued[i].issue_id, issued[i].book_id, issued[i].title,
                issued[i].student, issued[i].date);

    fclose(fp);
}
