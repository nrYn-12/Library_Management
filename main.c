#include "header.h"

Book books[MAX];
int nbooks = 0;
Issued issued[MAX];
int nissued = 0;

void pause(void) {
    char dummy[8];
    printf("\nPress Enter to return: ");
    fgets(dummy, sizeof(dummy), stdin);
}

void get_line(char *s, int n) {
    if (fgets(s, n, stdin) == NULL) {
        s[0] = 0;
        return;
    }
    s[strcspn(s, "\r\n")] = 0;
}

int get_int(void) {
    char buf[20];
    get_line(buf, sizeof(buf));
    if (buf[0] == 0)
        return -1;   /* empty Enter is not 0 / Exit */
    return atoi(buf);
}

int find_id(int id) {
    int i;
    for (i = 0; i < nbooks; i++)
        if (books[i].id == id)
            return i;
    return -1;
}

int find_title(char *title) {
    int i;
    for (i = 0; i < nbooks; i++)
        if (strcmp(books[i].title, title) == 0)
            return i;
    return -1;
}

void show_book(Book b) {
    printf("| %-8d | %-28s | %-20s | %-6d |\n", b.id, b.title, b.author, b.copies);
}

void now_str(char *s) {
    time_t t = time(NULL);
    strftime(s, 32, "%Y-%m-%d %H:%M:%S", localtime(&t));
}

int days_held(char *issued) {
    struct tm t = {0};
    int y, m, d;
    time_t t1, t2;
    int days;

    sscanf(issued, "%d-%d-%d", &y, &m, &d);
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_hour = 12;
    t.tm_isdst = -1;
    t1 = mktime(&t);
    t2 = time(NULL);
    if (t1 == (time_t)-1)
        return 0;
    days = (int)(difftime(t2, t1) / 86400);
    return days < 0 ? 0 : days;
}

/* 0-3 free, 4-6 Rs.10, 7-10 Rs.20, 11-30 Rs.20, 31+ Rs.100 + Rs.10/day after 30 */
int calc_fine(int days) {
    if (days <= 3)
        return 0;
    if (days < 7)
        return 10;
    if (days <= 30)
        return 20;
    return 100 + (days - 30) * 10;
}

int pick_book(void) {
    int ch, i;
    char title[LEN];

    while (1) {
        search_menu();
        printf("Enter your choice: ");
        ch = get_int();

        if (ch == 0)
            return -1;
        if (ch == -1)
            continue;

        if (ch == 1) {
            printf("Enter Book ID: ");
            i = find_id(get_int());
            if (i == -1) {
                printf("Book not found.\n");
                continue;
            }
            return i;
        }

        if (ch == 2) {
            printf("Enter Book Title: ");
            get_line(title, LEN);
            i = find_title(title);
            if (i == -1) {
                printf("Book not found.\n");
                continue;
            }
            return i;
        }

        printf("Invalid choice.\n");
    }
}

int main(void) {
    int ch;

    load_books();
    load_issued();

    while (1) {
        menu();
        ch = get_int();

        if (ch == -1)
            continue;          /* Enter only: stay in menu */
        else if (ch == 1) add_book();
        else if (ch == 2) remove_book();
        else if (ch == 3) search_book();
        else if (ch == 4) list_books();
        else if (ch == 5) {
            save_books();
            printf("\nBooks saved.\n");
            pause();
        }
        else if (ch == 6) issue_book();
        else if (ch == 7) return_book();
        else if (ch == 8) list_issued();
        else if (ch == 9) {
            save_issued();
            printf("\nIssued books saved.\n");
            pause();
        }
        else if (ch == 0) {
            save_books();
            save_issued();
            printf("\nData saved. Bye!\n");
            break;             /* close terminal only here */
        }
        else {
            printf("\nInvalid choice.\n");
            pause();
        }
    }
    return 0;
}
