#include "menu.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>

void options(void)
{
    /*
    * Function Name: options
    *
    * Description:
    * The options function displays a menu of options to the user. This menu is intended to guide the user through various actions they can perform within the program.
    * The application allows a pharmacy administrator to manage the pharmacy's stock. Each medicine in stock has a unique code, name, concentration, and available quantity.
    *
    * Parameters:
    * - None
    *
    * Return Value:
    * - None
    *
    * Example Usage:
    * options();
    *
    * Notes:
    * - This function is static, meaning it is only accessible within the file it is defined in.
    * - The function does not take any input parameters and does not return any values.
    * - The function is used to inform the user of the available actions they can take within the program.
    */

    printf("----------Menu----------\n");
    printf("1. Add medicines.\n");
    printf("2. Update existing medicine.\n");
    printf("3. Delete entire stock of a given medicine.\n");
    printf("4. Display the medicines available sorted by a given criterion.\n");
    printf("5. Filter the medicines by a given criterion.\n");
    printf("6. Display all the medicines.\n");
    printf("7. Exit.\n");
}

void option_4_submenu(void)
{
	/*
	* Function Name: option_4_submenu
	*
	* Description:
	* The option_4_submenu function displays a submenu of sorting options to the user.
	* This submenu allows the user to choose how they want to sort the list of medicines.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* option_4_submenu();
	*
	* Notes:
	* - This function does not take any input parameters and does not return any values.
	* - The function is used to inform the user of the available sorting options they can choose from.
	*/

	printf("----------Sort by----------\n");
	printf("1. Quantity.\n");
	printf("2. Name.\n");
	printf("3. Exit submenu.\n");
}

char select_option_4(void)
{
	/*
	* Function Name: select_option_4
	*
	* Description:
	* The select_option_4 function prompts the user to input a command and reads the input from the standard input.
	* It validates the input to ensure it is a single character representing a valid submenu option for sorting medicines.
	* If the input is valid, it returns the character corresponding to the selected option.
	* If the input is invalid, it prints an error message and returns '\0'.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - char: The character representing the selected submenu option, or '\0' if the input is invalid.
	*
	* Example Usage:
	* char option = select_option_4();
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - The valid submenu options are '1', '2', and '3'.
	* - The function trims the newline character from the input string.
	*/

	char cmd[256] = "";

	printf("Insert option: >>> ");

	if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 1 && (cmd[0] == '1' || cmd[0] == '2' || cmd[0] == '3')) {
			return cmd[0];
		}
		else {
			printf("Invalid command.\n");
		}
	}

	return '\0';
}

void option_5_submenu(void)
{
	/*
	* Function Name: option_5_submenu
	*
	* Description:
	* The option_5_submenu function displays a submenu of filtering options to the user.
	* This submenu allows the user to choose how they want to filter the list of medicines.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* option_5_submenu();
	*
	* Notes:
	* - This function does not take any input parameters and does not return any values.
	* - The function is used to inform the user of the available filtering options they can choose from.
	*/

	printf("----------Filter by----------\n");
	printf("1. Less than a given value.\n");
	printf("2. Medicines that begin with a given letter.\n");
	printf("3. Exit submenu.\n");
}

char select_option_5(void)
{
	/*
	* Function Name: select_option_5
	*
	* Description:
	* The select_option_5 function prompts the user to input a command and reads the input from the standard input.
	* It validates the input to ensure it is a single character representing a valid submenu option for filtering medicines.
	* If the input is valid, it returns the character corresponding to the selected option.
	* If the input is invalid, it prints an error message and returns '\0'.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - char: The character representing the selected submenu option, or '\0' if the input is invalid.
	*
	* Example Usage:
	* char option = select_option_5();
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - The valid submenu options are '1', '2', and '3'.
	* - The function trims the newline character from the input string.
	*/

	char cmd[256] = "";

	printf("Insert option: >>> ");

	if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 1 && (cmd[0] == '1' || cmd[0] == '2' || cmd[0] == '3')) {
			return cmd[0];
		}
		else {
			printf("Invalid command.\n");
		}
	}

	return '\0';
}

char select_option(void)
{
	/*
	* Function Name: select_option
	*
	* Description:
	* The select_option function prompts the user to input a command and reads the input from the standard input.
	* It validates the input to ensure it is a single character representing a valid menu option.
	* If the input is valid, it returns the character corresponding to the selected option.
	* If the input is invalid, it prints an error message and returns '\0'.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - char: The character representing the selected menu option, or '\0' if the input is invalid.
	*
	* Example Usage:
	* char option = select_option();
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - The valid menu options are '1', '2', '3', '4', '5', and '6'.
	* - The function trims the newline character from the input string.
	*/

	char cmd[256] = "";

	printf("Insert option: >>> ");

	if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 1 && (cmd[0] == '1' || cmd[0] == '2' || cmd[0] == '3' || cmd[0] == '4' || cmd[0] == '5' || cmd[0] == '6' || cmd[0] == '7')) {
			return cmd[0];
		}
		else {
			printf("Invalid command.\n");
		}
	}

	return '\0';
}

void clear_input_buffer(void)
{
	/*
	* Function Name: clear_input_buffer
	*
	* Description:
	* The clear_input_buffer function clears the input buffer by reading and discarding characters until a newline character or end-of-file (EOF) is encountered.
	* This is useful to remove any extraneous input that may interfere with subsequent input operations.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* clear_input_buffer();
	*
	* Notes:
	* - This function is typically used after reading input to ensure the input buffer is empty.
	* - It reads characters from the standard input (stdin) until a newline character or EOF is found.
	*/

	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

medicine read_params_create_ui(void)
{
	/*
	* Function Name: read_params_create
	*
	* Description:
	* The read_params_create function prompts the user to input the parameters required to create a new medicine entry.
	* It reads the medicine ID, name, concentration, and available quantity from the standard input.
	* The function validates the input to ensure it is of the correct type and format.
	*
	* Parameters:
	* - int *id: Pointer to an integer where the medicine ID will be stored.
	* - char *name: Pointer to a character array where the medicine name will be stored.
	* - float *concentration: Pointer to a float where the medicine concentration will be stored.
	* - int *available_quantity: Pointer to an integer where the available quantity will be stored.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* int id;
	* char name[256];
	* float concentration;
	* int available_quantity;
	* read_params_create(&id, name, &concentration, &available_quantity);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the scanf_s function to read and validate the input.
	* - The function calls clear_input_buffer to clear the input buffer in case of invalid input.
	*/

	int id;
	char name[256];
	float concentration;
	int available_quantity;

	printf("Insert the medicine ID: ");
	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		clear_input_buffer();
	}

	printf("Insert the medicine name: ");
	while (scanf_s("%s", name, 256) != 1) {
		printf("Invalid input. Please enter a valid string value for the medicine name: ");
		clear_input_buffer();
	}

	printf("Insert the concentration: ");
	while (scanf_s("%f", &concentration) != 1) {
		printf("Invalid input. Please enter a valid float value for the concentration: ");
		clear_input_buffer();
	}

	printf("Insert the available quantity: ");
	while (scanf_s("%d", &available_quantity) != 1) {
		printf("Invalid input. Please enter a valid integer value for the available quantity: ");
		clear_input_buffer();
	}

	const medicine med_unit = create_medicine(id, name, concentration, available_quantity);
	return med_unit;
}

void add_medicine_ui(struct medicine_list* list)
{
	/*
	* Function Name: add_medicine_ui
	*
	* Description:
	* The add_medicine_ui function prompts the user to input the parameters required to add a new medicine to the stock.
	* It reads the medicine ID, name, concentration, and available quantity from the standard input.
	* The function validates the input to ensure it is of the correct type and format.
	* If the medicine already exists in the stock, the available quantity is updated.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list where the new medicine will be added.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* add_medicine_ui(&list);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the add function to add the new medicine to the stock.
	* - If the medicine already exists in the stock, the available quantity is updated.
	*/

	add(list, read_params_create_ui());
	printf("Medicine added successfully.\n");
}

void update_medicine_ui(struct medicine_list *list)
{
	/*
	* Function Name: update_medicine_ui
	*
	* Description:
	* The update_medicine_ui function prompts the user to input the parameters required to update an existing medicine in the stock.
	* It reads the medicine ID, name, and concentration from the standard input.
	* The function validates the input to ensure it is of the correct type and format.
	* If the medicine ID is found in the stock, the name and concentration are updated.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list where the medicine will be updated.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* update_medicine_ui(&list);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the update_medicine function to update the existing medicine in the stock.
	*/

	int id;
	char name[256];
	float concentration;
	printf("Insert the medicine ID: ");
	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		clear_input_buffer();
	}

	printf("Insert the medicine name: ");
	while (scanf_s("%s", name, 256) != 1) {
		printf("Invalid input. Please enter a valid string value for the medicine name: ");
		clear_input_buffer();
	}
	printf("Insert the concentration: ");
	while (scanf_s("%f", &concentration) != 1) {
		printf("Invalid input. Please enter a valid float value for the concentration: ");
		clear_input_buffer();
	}
	update_medicine(list, id, name, concentration);
	printf("Medicine updated successfully.\n");
}

void delete_medicine_stock_ui(struct medicine_list* list)
{
	/*
	* Function Name: delete_medicine_stock_ui
	*
	* Description:
	* The delete_medicine_stock_ui function prompts the user to input the ID of the medicine whose entire stock is to be deleted.
	* It reads the medicine ID from the standard input and validates the input to ensure it is a valid integer.
	* If the input is valid, it calls the delete_medicine_stock function to remove the medicine from the stock.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list from which the medicine stock will be deleted.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* delete_medicine_stock_ui(&list);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the delete_medicine_stock function to remove the medicine from the stock.
	*/

	int id;
	printf("Insert the deletion medicine ID: ");
	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		clear_input_buffer();
	}
	delete_medicine_stock(list, id);
	printf("Medicine stock deleted successfully.\n");
}

void display_all_ui(const struct medicine_list* list)
{
	/*
	* Function Name: display_all_ui
	*
	* Description:
	* The display_all_ui function displays all the medicines available in the stock.
	* It calls the display_medicines function to print the details of each medicine in the stock.
	*
	* Parameters:
	* - None
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* display_all_ui();
	*
	* Notes:
	* - This function does not take any input parameters.
	* - It uses the display_medicines function to print the details of each medicine in the stock.
	*/

	display_medicines(list);
}

void sort_medicines_quantity_ui(const struct medicine_list* list)
{
	/*
	* Function Name: filter_medicines_quantity_ui
	*
	* Description:
	* The filter_medicines_quantity_ui function prompts the user to input a quantity threshold for filtering the medicines.
	* It reads the quantity threshold from the standard input and validates the input to ensure it is a valid integer.
	* If the input is valid, it calls the filter_medicines_quantity function to filter the medicines based on the quantity threshold.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list to be filtered.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* filter_medicines_quantity_ui(&list);
	*
	* Notes:
	* - It uses the filter_medicines_quantity function to filter the medicines based on the quantity threshold.
	*/

	medicine_list filtered_list = sort_medicines_quantity(list);
	display_medicines(&filtered_list);
}

void sort_medicines_name_ui(const struct medicine_list* list)
{
	/*
	* Function Name: filter_medicines_name_ui
	*
	* Description:
	* The filter_medicines_name_ui function prompts the user to input a name criterion for filtering the medicines.
	* It reads the name criterion from the standard input and validates the input to ensure it is a valid string.
	* If the input is valid, it calls the filter_medicines_name function to filter the medicines based on the name criterion.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list to be filtered.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* filter_medicines_name_ui(&list);
	*
	* Notes:
	* - It uses the filter_medicines_name function to filter the medicines based on the name criterion.
	*/

	medicine_list filtered_list = sort_medicines_name(&filtered_list);
	display_medicines(&filtered_list);
}

void filter_medicines_stock_ui(const struct medicine_list* list)
{
	/*
	* Function Name: filter_medicines_stock_ui
	*
	* Description:
	* The filter_medicines_stock_ui function prompts the user to input a quantity threshold for filtering the medicines.
	* It reads the quantity threshold from the standard input and validates the input to ensure it is a valid integer.
	* If the input is valid, it calls the filter_medicines_by_stock function to filter the medicines based on the quantity threshold.
	* The filtered list of medicines is then displayed to the user.
	*
	* Parameters:
	* - const struct medicine_list *list: Pointer to the medicine list to be filtered.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* filter_medicines_stock_ui(&list);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the filter_medicines_by_stock function to filter the medicines based on the quantity threshold.
	* - The function calls clear_input_buffer to clear the input buffer in case of invalid input.
	*/

	int quantity;
	printf("Insert the medicine quantity: ");
	while (scanf_s("%d", &quantity) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine quantity: ");
		clear_input_buffer();
	}

	medicine_list filtered_list = filter_medicines_by_stock(list, quantity);
	display_medicines(&filtered_list);
}

void filter_medicines_first_letter_ui(const struct medicine_list* list)
{
	/*
	* Function Name: filter_medicines_first_letter_ui
	*
	* Description:
	* The filter_medicines_first_letter_ui function prompts the user to input a letter to filter the medicines by their name.
	* It reads the letter from the standard input and validates the input to ensure it is a valid character.
	* If the input is valid, it calls the filter_medicines_by_name function to filter the medicines based on the given letter.
	*
	* Parameters:
	* - const struct medicine_list *list: Pointer to the medicine list to be filtered.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* filter_medicines_first_letter_ui(&list);
	*
	* Notes:
	* - This function reads input from the standard input (stdin).
	* - It uses the filter_medicines_by_name function to filter the medicines based on the given letter.
	* - The function calls clear_input_buffer to clear the input buffer in case of invalid input.
	*/

	char letter;
	printf("Insert the medicine letter: ");
	while (scanf_s("%c", &letter) != 1) {
		printf("Invalid input. Please enter a valid character value for the medicine letter: ");
		clear_input_buffer();
	}

	medicine_list filtered_list = filter_medicines_by_name(list, letter);
	display_medicines(&filtered_list);
}

void menu_implemented(struct medicine_list *list)
{
	/*
	* Function Name: menu_implemented
	*
	* Description:
	* The menu_implemented function displays the main menu and handles user input to perform various actions related to managing the pharmacy's stock.
	* It allows the user to add, update, delete, sort, filter, and display medicines in the stock.
	*
	* Parameters:
	* - struct medicine_list *list: Pointer to the medicine list that contains the stock of medicines.
	*
	* Return Value:
	* - None
	*
	* Example Usage:
	* menu_implemented(&list);
	*
	* Notes:
	* - This function runs in an infinite loop until the user selects the option to exit the program.
	* - It uses various helper functions to perform specific actions based on the user's input.
	* - The function validates user input and provides appropriate feedback for invalid commands.
	*/

	while (true)
	{
		options();
		const char option = select_option();

		switch (option) {
		case '1':
			add_medicine_ui(list);
			clear_input_buffer();
			break;

		case '2':
			update_medicine_ui(list);
			clear_input_buffer();
			break;

		case '3':
			delete_medicine_stock_ui(list);
			clear_input_buffer();
			break;

		case '4':
			while (true) {

				option_4_submenu();
				const char sub_option = select_option_4();

				if (sub_option == '3') {
					printf("Exiting the submenu...\n");
					break;
				}

				switch (sub_option)
				{
				case '1':
					sort_medicines_quantity_ui(list);
					break;

				case '2':
					sort_medicines_name_ui(list);
					break;

				default:
					break;
				}
			}
			break;

		case '5':
			while (true) {

				option_5_submenu();
				const char sub_option = select_option_5();

				if (sub_option == '3') {
					printf("Exiting the submenu...\n");
					break;
				}

				switch (sub_option)
				{
				case '1':
					filter_medicines_stock_ui(list);
					break;

				case '2':
					filter_medicines_first_letter_ui(list);
					break;

				default:
					break;
				}
			}
			break;

		case '6':
			display_all_ui(list);
			break;

		case '7':
			printf("Exiting the program...\n");
			return;

		default:
			printf("Invalid command.\n");
			break;
		}
	}
}
