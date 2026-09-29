#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define LEN 80

typedef struct {
    int id;
    char title[LEN];
    char author[LEN];
    int copies;
} Book;

typedef struct {
    int issue_id;
    int book_id;
    char title[LEN];
    char student[LEN];
    char date[32];
} Issued;

extern Book books[MAX];
extern int nbooks;
extern Issued issued[MAX];
extern int nissued;

void menu(void);
void search_menu(void);
void add_book(void);
void remove_book(void);
void search_book(void);
void list_books(void);
void save_books(void);
void issue_book(void);
void return_book(void);
void list_issued(void);
void save_issued(void);
void load_books(void);
void load_issued(void);

void pause(void);
void get_line(char *s, int n);
int get_int(void);
int find_id(int id);
int find_title(char *title);
int pick_book(void);
void show_book(Book b);
void now_str(char *s);
int days_held(char *issued);
int calc_fine(int days);

#endif
