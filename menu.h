#ifndef MENU_H
#define MENU_H

#include "medicine.h"

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

#endif