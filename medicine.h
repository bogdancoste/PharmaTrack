#ifndef MEDICINE_H
#define MEDICINE_H

enum { max_size = 200 };
enum { success  = 0, error_list_full = 1, already_exists = 2};

typedef struct medicine
{
    int id;
	char name[256];
    float concentration;
    int available_quantity;

} medicine;

typedef struct medicine_list
{
    medicine array[max_size];
    int index;

} medicine_list;

#endif 