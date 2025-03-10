#ifndef MENU_H
#define MENU_H

#include "medicine.h"
#include <stdbool.h>

void options(void);
char select_option(void);
void clear_input_buffer(void);
void menu_implemented(struct medicine_list* list);
void display_all_ui(const struct medicine_list* list);
void add_medicine_ui(struct medicine_list* list);
void update_medicine_ui(struct medicine_list* list);
void delete_medicine_stock_ui(struct medicine_list* list);
void option_4_submenu(void);
char select_option_4(void);
void sort_medicines_quantity_ui(const struct medicine_list* list);
void sort_medicines_name_ui(const struct medicine_list* list);
void option_5_submenu(void);
char select_option_5(void);
void filter_medicines_stock_ui(const struct medicine_list* list);
void filter_medicines_first_letter_ui(const struct medicine_list* list);
void buffer_flush(void);
void display_medicines_ui(const struct medicine_list* list);
medicine read_params_create_ui(void);
void clear_screen(void);
void enable_ansi(void);
static void set_full_screen(void);
int get_screen_width(void);
int get_screen_height(void);
void decorative_frame(void);
void print_menu(const int highlight);
void enable_raw_console_mode(void);
void hide_mouse_cursor(void);
void update_menu(int old_highlight, const int new_highlight);
bool key_pressed(const int virtKey);
void display_splash_screen(void);

#endif