#include "header.h"

void list_issued(void) {
    int i, days;

    printf("\nListing issued books...\n\nIssued Books List:\n\n");
    if (nissued == 0) {
        printf("No books are issued.\n");
        pause();
        return;
    }

    printf("| %-8s | %-24s | %-16s | %-19s | %-5s | %-8s |\n",
           "Issue ID", "Books Title", "Student", "Issue Date", "Days", "Fine");
    for (i = 0; i < nissued; i++) {
        days = days_held(issued[i].date);
        printf("| %-8d | %-24s | %-16s | %-19s | %-5d | Rs.%-5d |\n",
               issued[i].issue_id, issued[i].title, issued[i].student,
               issued[i].date, days, calc_fine(days));
    }
    printf("\nFine: 0-3 days free | 4-6 Rs.10 | 7-30 Rs.20 | 31+ Rs.100 + Rs.10/day\n");
    pause();
}
