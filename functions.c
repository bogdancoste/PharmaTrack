#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Basic logic functions.
 */

medicine_list list_init(void)
{
	/**
	 * @brief Initializes a medicine list.
	 *
	 * This function initializes a medicine list by setting its index to 0.
	 *
	 * @return A medicine_list structure with the index set to 0.
	 */

	struct medicine_list list;
	list.index = 0;
	return list;
}

medicine create_medicine(const int id, const char name[256], const float concentration, const int available_quantity)
{
	/**
	 * @brief Creates a new medicine.
	 *
	 * This function creates a new medicine with the given parameters.
	 *
	 * @param id The ID of the medicine.
	 * @param name The name of the medicine.
	 * @param concentration The concentration of the medicine.
	 * @param available_quantity The available quantity of the medicine.
	 * @return A medicine structure initialized with the given parameters.
	 */

	struct medicine med_unit;
	med_unit.id = id;
	strcpy_s(med_unit.name, sizeof(med_unit.name), name);
	med_unit.concentration = concentration;
	med_unit.available_quantity = available_quantity;
	return med_unit;
}

int add(struct medicine_list *list, const struct medicine med_unit) {
	/**
	 * @brief Adds a medicine to the list.
	 *
	 * This function adds a medicine to the list. If the medicine already exists in the list,
	 * it updates the available quantity. If the list is full, it returns an error.
	 *
	 * @param list A pointer to the medicine list.
	 * @param med_unit The medicine to be added.
	 * @return An integer indicating the result of the operation:
	 *         - already_exists: if the medicine already exists in the list.
	 *         - error_list_full: if the list is full.
	 *         - success: if the medicine was successfully added.
	 */

   if (check_if_existing(list, med_unit))  
   {
		list -> array[list -> index] . available_quantity += med_unit.available_quantity;
   		return already_exists;  
   }
	if (list->index < max_size) {  
		list->array[list->index] = med_unit;  
		list->index++;  
	}  
	else {  
		return error_list_full;  
	}

	return success;  
}

bool check_if_existing(const struct medicine_list *list, const struct medicine med_unit)  
{
	/**
	 * @brief Checks if a medicine exists in the list.
	 *
	 * This function checks if a medicine with the same ID as the given medicine exists in the list.
	 *
	 * @param list A pointer to the medicine list.
	 * @param med_unit The medicine to be checked.
	 * @return A boolean value indicating whether the medicine exists in the list:
	 *         - true: if the medicine exists in the list.
	 *         - false: if the medicine does not exist in the list.
	 */

   for (int i = 0; i < list->index; i++)  
   {  
       if (list->array[i].id == med_unit.id)  
       {  
           return true;  
       }  
   }  

   return false;  
}

void update_medicine(struct medicine_list* list, const int id, const char name[256], const float concentration)
{
	/**
	 * @brief Updates a medicine in the list.
	 *
	 * This function updates the name and concentration of a medicine with the given ID in the list.
	 * If the medicine with the given ID is found, its name and concentration are updated.
	 *
	 * @param list A pointer to the medicine list.
	 * @param id The ID of the medicine to be updated.
	 * @param name The new name of the medicine.
	 * @param concentration The new concentration of the medicine.
	 */

	for (int i = 0; i < list -> index; i++)
	{
		if (list -> array[i].id == id)
		{
			strcpy_s(list->array[i].name, sizeof(list -> array[i].name), name);
			list->array[i].concentration = concentration;
		}
	}
}

void delete_medicine_stock(struct medicine_list* list, const int id)
{
	/**
	  * @brief Deletes the stock of a medicine.
	  *
	  * This function sets the available quantity of a medicine with the given ID to 0.
	  * If the medicine with the given ID is found, its available quantity is set to 0.
	  *
	  * @param list A pointer to the medicine list.
	  * @param id The ID of the medicine whose stock is to be deleted.
	  */

	for (int i = 0; i < list -> index; i++)
	{
		if (list -> array[i].id == id)
		{
			list -> array[i].available_quantity = 0;
		}
	}
}

void display_medicines(const struct medicine_list* list)  
{  
	/**  
	 * @brief Displays all medicines in the list.  
	 *  
	 * This function iterates through the medicine list and prints the details of each medicine,  
	 * including its ID, name, concentration, and available quantity.  
	 *  
	 * @param list A pointer to the medicine list.  
	 */

	for (int i = 0; i < list->index; i++)
	{
		printf("Medicine ID: %d\n", list->array[i].id);
		printf("Medicine Name: %s\n", list->array[i].name);
		printf("Medicine Concentration: %.2f\n", list->array[i].concentration);
		printf("Medicine Available Quantity: %d\n", list->array[i].available_quantity);
	}
}

/*
 * Business logic functions.
 */

int compare_quantity(const void* a, const void* b)
{
	/**
	* @brief Compares the available quantity of two medicines.
	*
	* This function compares the available quantity of two medicines.
	* It is used as a comparison function for sorting medicines by their available quantity.
	*
	* @param a A pointer to the first medicine.
	* @param b A pointer to the second medicine.
	* @return An integer less than, equal to, or greater than zero if the available quantity of the first medicine
	*         is found, respectively, to be less than, to match, or be greater than the second.
	*/

   const struct medicine* med_a = (const struct medicine*)a;
   const struct medicine* med_b = (const struct medicine*)b;
   return (med_a->available_quantity - med_b->available_quantity);
}

medicine_list sort_medicines_quantity(const struct medicine_list* list)
{
	/**
	 * @brief Sorts medicines by available quantity.
	 *
	 * This function sorts the medicines in the given list by their available quantity in ascending order.
	 *
	 * @param list A pointer to the medicine list to be sorted.
	 * @return A new medicine_list structure containing the sorted medicines.
	 */

    struct medicine_list filtered_list = *list;
    
    qsort(filtered_list.array, filtered_list.index, sizeof(struct medicine), compare_quantity);
    
    return filtered_list;
}

int compare_name(const void* a, const void* b)
{
	/**
  * @brief Compares the names of two medicines.
  *
  * This function compares the names of two medicines.
  * It is used as a comparison function for sorting medicines by their names.
  *
  * @param a A pointer to the first medicine.
  * @param b A pointer to the second medicine.
  * @return An integer less than, equal to, or greater than zero if the name of the first medicine
  *         is found, respectively, to be less than, to match, or be greater than the second.
  */

	const struct medicine* med_a = (const struct medicine*)a;
	const struct medicine* med_b = (const struct medicine*)b;
	return strcmp(med_a->name, med_b->name);
}

medicine_list sort_medicines_name(const struct medicine_list* list)
{
	/**
  * @brief Sorts medicines by name.
  *
  * This function sorts the medicines in the given list by their names in ascending order.
  *
  * @param list A pointer to the medicine list to be sorted.
  * @return A new medicine_list structure containing the sorted medicines.
  */

	struct medicine_list filtered_list = *list;
	qsort(filtered_list.array, filtered_list.index, sizeof(struct medicine), compare_name);
	return filtered_list;
}

medicine_list filter_medicines_by_stock(const struct medicine_list* list, const int given_quantity)
{
	/**
	 * @brief Filters medicines by stock quantity.
	 *
	 * This function filters the medicines in the given list by their available quantity.
	 * It returns a new list containing only the medicines with an available quantity less than the given quantity.
	 *
	 * @param list A pointer to the medicine list to be filtered.
	 * @param given_quantity The quantity threshold for filtering medicines.
	 * @return A new medicine_list structure containing the filtered medicines.
	 */

	struct medicine_list filtered_list = list_init();

	for (int i = 0; i < list -> index; i++)
	{
		if (list -> array[i].available_quantity < given_quantity)
		{
			add(&filtered_list, list->array[i]);
		}
	}

	return filtered_list;
}

medicine_list filter_medicines_by_name(const struct medicine_list* list, const char first_char)
{
	/**
	  * @brief Filters medicines by the first character of their name.
	  *
	  * This function filters the medicines in the given list by the first character of their name.
	  * It returns a new list containing only the medicines whose names start with the given character.
	  *
	  * @param list A pointer to the medicine list to be filtered.
	  * @param first_char The first character of the medicine names to filter by.
	  * @return A new medicine_list structure containing the filtered medicines.
	  */

	struct medicine_list filtered_list = list_init();

	for (int i = 0; i < list->index; i++)
	{
		if (list->array[i].name[0] == first_char)
		{
			add(&filtered_list, list->array[i]);
		}
	}

	return filtered_list;
}