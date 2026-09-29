#include "header.h"

void return_book(void) {
    int i, id, p = -1, b, days, fine;
    char ret[32];

    printf("\nReturning a book...\n");
    if (nissued == 0) {
        printf("No issued books.\n");
        pause();
        return;
    }

    printf("\n| %-8s | %-8s | %-24s | %-16s | %-19s |\n",
           "Issue ID", "Book ID", "Books Title", "Student Name", "Issue Date");
    for (i = 0; i < nissued; i++)
        printf("| %-8d | %-8d | %-24s | %-16s | %-19s |\n",
               issued[i].issue_id, issued[i].book_id, issued[i].title,
               issued[i].student, issued[i].date);

    printf("\nEnter Issue ID to return: ");
    id = get_int();

    for (i = 0; i < nissued; i++)
        if (issued[i].issue_id == id)
            p = i;

    if (p == -1) {
        printf("Issue ID not found.\n");
        pause();
        return;
    }

    now_str(ret);
    days = days_held(issued[p].date);
    fine = calc_fine(days);

    b = find_id(issued[p].book_id);
    if (b != -1)
        books[b].copies++;

    printf("\n---------- RETURN BILL ----------\n");
    printf("Book         : %s\n", issued[p].title);
    printf("Student      : %s\n", issued[p].student);
    printf("Issue date   : %s  (system clock)\n", issued[p].date);
    printf("Return date  : %s  (system clock)\n", ret);
    printf("Days kept    : %d\n", days);
    printf("Fine         : Rs. %d\n", fine);
    if (fine == 0)
        printf("Returned on time. No fine.\n");
    else if (days > 30)
        printf("Late > 30 days: Rs.100 + Rs.10 x %d extra day(s).\n", days - 30);
    else if (days >= 7)
        printf("Late 7-30 days: Rs.20\n");
    else
        printf("Late more than 3 days: Rs.10\n");
    printf("---------------------------------\n");

    for (i = p; i < nissued - 1; i++)
        issued[i] = issued[i + 1];
    nissued--;
    save_books();
    save_issued();
    pause();
}
