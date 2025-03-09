#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "medicine.h"
#include "stdbool.h"

/*
 * Basic logic functions.
 */

medicine_list list_init(void);
medicine create_medicine(const int id, const char name[256], const float concentration, const int available_quantity);
int add(struct medicine_list* list, struct medicine med_unit);
void update_medicine(struct medicine_list* list, const int id, const char name[256], const float concentration);
void delete_medicine_stock(struct medicine_list* list, const int id);
bool check_if_existing(const struct medicine_list* list, const struct medicine med_unit);
void display_medicines(const struct medicine_list* list);

/*
 * Business logic functions.
 */

int compare_quantity(const void* a, const void* b);
medicine_list sort_medicines_quantity(const struct medicine_list* list);

int compare_name(const void* a, const void* b);
medicine_list sort_medicines_name(const struct medicine_list* list);

medicine_list filter_medicines_by_stock(const struct medicine_list* list, const int given_quantity);
medicine_list filter_medicines_by_name(const struct medicine_list* list, const char first_char);

#endif 