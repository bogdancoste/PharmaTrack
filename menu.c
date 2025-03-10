#include "menu.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

typedef enum {
	/* Base colors */
	base03_color,
	base02_color,
	base01_color,
	base00_color,
	base0_color,
	base1_color,
	base2_color,

	/* Accent colors */
	yellow_color,
	orange_color,
	red_color,
	magenta_color,
	violet_color,
	blue_color,
	cyan_color,
	green_color,

	/* Custom highlights */
	highlight_bg_color,
	frame_color_code,

	/* Additional formatting */
	bold_color,
	// You can add more, for example: underline_color, etc.

	num_color_codes
} color_code;

const char* color_codes[num_color_codes] = {
	/* Base colors */
	"\033[48;2;0;43;54m",   // base03_color
	"\033[48;2;7;54;66m",   // base02_color
	"\033[38;2;88;110;117m",// base01_color
	"\033[38;2;101;123;131m",// base00_color
	"\033[38;2;131;148;150m",// base0_color
	"\033[38;2;147;161;161m",// base1_color
	"\033[38;2;238;232;213m",// base2_color

	/* Accent colors */
	"\033[38;2;181;137;0m",  // yellow_color
	"\033[38;2;203;75;22m",  // orange_color
	"\033[38;2;220;50;47m",  // red_color
	"\033[38;2;211;54;130m", // magenta_color
	"\033[38;2;108;113;196m",// violet_color
	"\033[38;2;38;139;210m", // blue_color
	"\033[38;2;42;161;152m", // cyan_color
	"\033[38;2;133;153;0m",  // green_color

	/* Custom highlights */
	"\033[48;2;7;54;66m",    // highlight_bg_color
	"\033[38;2;88;110;117m", // frame_color_code

	/* Additional formatting */
	"\033[1m"               // bold_color
};

#define NUM_OPTIONS 7

void buffer_flush(void)
{
	if (fflush(stdout) != 0) {
		perror("Flush failed.");
		_exit(0);
	}
}

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
	buffer_flush();

	printf("1. Quantity.\n");
	buffer_flush();

	printf("2. Name.\n");
	buffer_flush();

	printf("3. Exit submenu.\n");
	buffer_flush();

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
	buffer_flush();

	if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 1 && (cmd[0] == '1' || cmd[0] == '2' || cmd[0] == '3')) {
			return cmd[0];
		}
		else {
			printf("Invalid command.\n");
			buffer_flush();
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
	buffer_flush();

	printf("1. Less than a given value.\n");
	buffer_flush();

	printf("2. Medicines that begin with a given letter.\n");
	buffer_flush();

	printf("3. Exit submenu.\n");
	buffer_flush();
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
	buffer_flush();

	if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 1 && (cmd[0] == '1' || cmd[0] == '2' || cmd[0] == '3')) {
			return cmd[0];
		}
		else {
			printf("Invalid command.\n");
			buffer_flush();

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

void display_medicines_ui(const struct medicine_list* list)
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
		buffer_flush();

		printf("Medicine Name: %s\n", list->array[i].name);
		buffer_flush();

		printf("Medicine Concentration: %.2f\n", list->array[i].concentration);
		buffer_flush();

		printf("Medicine Available Quantity: %d\n", list->array[i].available_quantity);
		buffer_flush();
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
	buffer_flush();

	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		buffer_flush();

		clear_input_buffer();
	}

	printf("Insert the medicine name: ");
	buffer_flush();

	while (scanf_s("%s", name, 256) != 1) {
		printf("Invalid input. Please enter a valid string value for the medicine name: ");
		buffer_flush();

		clear_input_buffer();
	}

	printf("Insert the concentration: ");
	buffer_flush();

	while (scanf_s("%f", &concentration) != 1) {
		printf("Invalid input. Please enter a valid float value for the concentration: ");
		buffer_flush();

		clear_input_buffer();
	}

	printf("Insert the available quantity: ");
	buffer_flush();

	while (scanf_s("%d", &available_quantity) != 1) {
		printf("Invalid input. Please enter a valid integer value for the available quantity: ");
		buffer_flush();

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
	buffer_flush();
}

void update_medicine_ui(struct medicine_list* list)
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
	buffer_flush();

	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		buffer_flush();

		clear_input_buffer();
	}

	printf("Insert the medicine name: ");
	buffer_flush();

	while (scanf_s("%s", name, 256) != 1) {
		printf("Invalid input. Please enter a valid string value for the medicine name: ");
		buffer_flush();

		clear_input_buffer();
	}

	printf("Insert the concentration: ");
	buffer_flush();

	while (scanf_s("%f", &concentration) != 1) {
		printf("Invalid input. Please enter a valid float value for the concentration: ");
		buffer_flush();

		clear_input_buffer();
	}
	update_medicine(list, id, name, concentration);
	printf("Medicine updated successfully.\n");
	buffer_flush();
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
	buffer_flush();

	while (scanf_s("%d", &id) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine ID: ");
		buffer_flush();

		clear_input_buffer();
	}

	delete_medicine_stock(list, id);
	printf("Medicine stock deleted successfully.\n");
	buffer_flush();
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

	const medicine_list filtered_list = sort_medicines_quantity(list);
	display_medicines_ui(&filtered_list);
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

	const medicine_list filtered_list = sort_medicines_name(&filtered_list);
	display_medicines_ui(&filtered_list);
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
	buffer_flush();

	while (scanf_s("%d", &quantity) != 1) {
		printf("Invalid input. Please enter a valid integer value for the medicine quantity: ");
		buffer_flush();

		clear_input_buffer();
	}

	const medicine_list filtered_list = filter_medicines_by_stock(list, quantity);
	display_medicines_ui(&filtered_list);
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
	buffer_flush();

	while (scanf_s("%c", &letter) != 1) {
		printf("Invalid input. Please enter a valid character value for the medicine letter: ");
		buffer_flush();

		clear_input_buffer();
	}

	const medicine_list filtered_list = filter_medicines_by_name(list, letter);
	display_medicines_ui(&filtered_list);
}

const char* menu_options[NUM_OPTIONS] = {
	" Add New Medicine",
	" Update Existing Stock",
	" Delete Medicine Stock",
	" Display Sorted Inventory",
	" Filter Medicines",
	" List All Medicines",
	" Exit Application"
};

void clear_screen(void) {
	const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (h_console == INVALID_HANDLE_VALUE)
		return;

	CONSOLE_SCREEN_BUFFER_INFO cons_scr_buff_info;
	if (!GetConsoleScreenBufferInfo(h_console, &cons_scr_buff_info))
		return;

	DWORD consoleSize = cons_scr_buff_info.dwSize.X * cons_scr_buff_info.dwSize.Y;
	DWORD charsWritten;
	COORD homeCoords = { 0, 0 };

	FillConsoleOutputCharacter(h_console, ' ', consoleSize, homeCoords, &charsWritten);

	FillConsoleOutputAttribute(h_console, cons_scr_buff_info.wAttributes, consoleSize, homeCoords, &charsWritten);

	SetConsoleCursorPosition(h_console, homeCoords);
}

// ---------- BASIC CONSOLE SETUP ----------
void enable_ansi(void) {
	const HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dw_mode = 0;
	GetConsoleMode(h_out, &dw_mode);
	dw_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(h_out, dw_mode);
	SetConsoleOutputCP(65001);
}

static void set_full_screen(void) {
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_OVERLAPPEDWINDOW;
	style |= WS_POPUP;
	SetWindowLong(hwnd, GWL_STYLE, (LONG)(style));
	ShowWindow(hwnd, SW_MAXIMIZE);

	RECT rect;
	GetWindowRect(hwnd, &rect);
	MoveWindow(hwnd, rect.left, rect.top,
		rect.right - rect.left + 1,
		rect.bottom - rect.top + 1, TRUE);

	// Resize the screen buffer to match window size
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cons_scr_buff_info;
	GetConsoleScreenBufferInfo(h_console, &cons_scr_buff_info);
	COORD new_size;

	new_size.X = (int)(cons_scr_buff_info.srWindow.Right - cons_scr_buff_info.srWindow.Left + 1);
	new_size.Y = (int)(cons_scr_buff_info.srWindow.Bottom - cons_scr_buff_info.srWindow.Top + 1);
	SetConsoleScreenBufferSize(h_console, new_size);
}

int get_screen_width(void) {
	CONSOLE_SCREEN_BUFFER_INFO cons_scr_buff_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cons_scr_buff_info);
	return cons_scr_buff_info.srWindow.Right - cons_scr_buff_info.srWindow.Left + 1;
}

int get_screen_height(void) {
	CONSOLE_SCREEN_BUFFER_INFO cons_scr_buff_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cons_scr_buff_info);
	return cons_scr_buff_info.srWindow.Bottom - cons_scr_buff_info.srWindow.Top + 1;
}

void decorative_frame(void) {
	const int screen_w = get_screen_width();
	const int screen_h = get_screen_height();
	const int frame_width = (int)(screen_w * 0.50);
	const int frame_height = NUM_OPTIONS * 2 + 2;
	const int start_x = 3;
	const int start_y = 3;

	printf("\033[%d;%dH%s╔", start_y, start_x, color_codes[frame_color_code]);
	for (int i = 0; i < frame_width - 2; i++)
		printf("═");

	for (int y = start_y + 1; y < start_y + frame_height; y++) {
		printf("\033[%d;%dH%s║", y, start_x, color_codes[frame_color_code]);
	}

	const int br_start_x = screen_w - frame_width;
	const int br_start_y = screen_h - frame_height;
	for (int y = br_start_y; y < screen_h; y++) {
		printf("\033[%d;%dH%s║", y, screen_w - 1, color_codes[frame_color_code]);
	}

	printf("\033[%d;%dH%s═", screen_h - 1, br_start_x, color_codes[frame_color_code]);
	for (int i = 0; i < frame_width - 2; i++)
		printf("═");
	printf("╝");

	printf("\033[%d;%dH", start_y + 1, start_x + 2);
}

void print_menu(const int highlight) {
	// Use base03_color from the array
	printf("%s", color_codes[base03_color]);
	decorative_frame();

	const int screen_w = get_screen_width();
	const int frame_width = (int)(screen_w * 0.50);
	const int start_x = 3;
	const int start_y = 3;
	const int text_padding = 2;
	const int content_width = frame_width - 2;

	printf("\033[%d;%dH", start_y + 1, start_x + text_padding + 1);
	for (int i = 0; i < NUM_OPTIONS; i++) {
		if (highlight == i + 1) {
			// Replace macros with corresponding array entries:
			// Instead of: color_codes[highlight_bg_color], color_codes[bold], YELLOW, BASE2
			// Use: color_codes[highlight_bg_color], color_codes[bold_color], color_codes[yellow_color], color_codes[base2_color]
			printf("%s%s%s> %s%s",
				color_codes[highlight_bg_color],
				color_codes[bold_color],
				color_codes[yellow_color],
				color_codes[base2_color],
				menu_options[i]);
		}
		else {
			// Similarly, replace BASE03, BASE0, and BASE1 with array entries
			printf("%s%s  %s%s",
				color_codes[base03_color],
				color_codes[base0_color],
				color_codes[base1_color],
				menu_options[i]);
		}
		printf("\033[1B\033[%d;%dH%s",
			start_y + 1 + (i * 2) + 1,
			start_x + 1,
			color_codes[base01_color]);
		for (int j = 0; j < content_width; j++) {
			printf("─");
		}
		if (i < NUM_OPTIONS - 1) {
			printf("\033[%d;%dH", start_y + 1 + (i + 1) * 2, start_x + text_padding + 1);
		}
	}
	printf("\033[%d;%dH%s%s[CONTROLS] ↑/↓: Navigate | Enter: Select",
		start_y + (NUM_OPTIONS * 2) + 1,
		start_x + text_padding,
		color_codes[base0_color],
		color_codes[bold_color]);
	buffer_flush();
}

// ---------- CURSOR / INPUT HELPERS ----------
#define HIDE_CURSOR "\033[?25l"

void enable_raw_console_mode(void) {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hInput, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hInput, mode);
}

void hide_mouse_cursor(void) {
	printf("%s", HIDE_CURSOR);
	buffer_flush();
}

void update_menu(int old_highlight, const int new_highlight) {
	const int start_y = 3 + 1;
	const int line_spacing = 2;
	const int option_col = 3 + 2 + 1;

	const int screen_w = get_screen_width();
	const int frame_width = (int)(screen_w * 0.50);
	const int content_width = frame_width - 2;

	const int old_row = start_y + (old_highlight - 1) * line_spacing;
	printf("\033[%d;%dH", old_row, option_col);
	printf("%s%s  %s%-*s%s",
		color_codes[base03_color],
		color_codes[base0_color],
		color_codes[base1_color],
		content_width - 2,
		menu_options[old_highlight - 1],
		color_codes[base03_color]);

	const int new_row = start_y + (new_highlight - 1) * line_spacing;
	printf("\033[%d;%dH", new_row, option_col);
	printf("%s%s%s> %-*s%s",
		color_codes[highlight_bg_color],
		color_codes[bold_color],
		color_codes[yellow_color],
		content_width - 2,
		menu_options[new_highlight - 1],
		color_codes[base03_color]);

	const int sep_old_row = old_row + 1;
	printf("\033[%d;%dH%s", sep_old_row, option_col, color_codes[base01_color]);
	for (int j = 0; j < content_width; j++) {
		printf("─");
	}
	printf("%s", color_codes[base03_color]);

	const int sep_new_row = new_row + 1;
	printf("\033[%d;%dH%s", sep_new_row, option_col, color_codes[base01_color]);
	for (int j = 0; j < content_width; j++) {
		printf("─");
	}
	printf("%s", color_codes[base03_color]);

	buffer_flush();
}


// ---------- INPUT HANDLING ----------
bool key_pressed(const int virtKey) {
	return GetAsyncKeyState(virtKey) & 0x8000;
}

// ---------- SPLASH SCREEN ----------
void display_splash_screen(void) {
	printf("%s\033[2J\033[H", color_codes[base03_color]);
	buffer_flush();

	const int width = get_screen_width();
	const int height = get_screen_height();

	const char* ascii_art[] = {
		"______  _                                   _____ ______   ___   _____  _   __",
		"| ___ \\| |                                 |_   _|| ___ \\ / _ \\ /  __ \\| | / /",
		"| |_/ /| |__    __ _  _ __  _ __ ___    __ _ | |  | |_/ // /_\\ \\| /  \\/| |/ / ",
		"|  __/ | '_ \\  / _` || '__|| '_ ` _ \\  / _` || |  |    / |  _  || |    |    \\",
		"| |    | | | || (_| || |   | | | | | || (_| || |  | |\\ \\ | | | || \\__/\\| |\\  \\",
		"\\_|    |_| |_| \\__,_||_|   |_| |_| |_| \\__,_|\\_/  \\_| \\_|\\_| |_/ \\____/\\_| \\_/"
	};

	int total_art_height = 6 + 2;
	int start_y = (height - total_art_height) / 2;

	for (int i = 0; i < 6; i++) {
		int padding = (width - (int)strlen(ascii_art[i])) / 2;
		printf("\033[%d;%dH%s%s%s",
			start_y + i, padding,
			color_codes[cyan_color], ascii_art[i], color_codes[base03_color]);
	}

	const char* subtitle = "Pharmaceutical Management System";
	int subtitle_padding = (width - (int)strlen(subtitle)) / 2;
	printf("\033[%d;%dH%s%s%s",
		start_y + 7, subtitle_padding,
		color_codes[base1_color], subtitle, color_codes[base03_color]);

	for (int y = start_y + 8; y < height; y++) {
		printf("\033[%d;0H%s%*s", y, color_codes[base03_color], width, " ");
	}

	buffer_flush();
	Sleep(3000);

	clear_screen();
}

void menu_implemented(struct medicine_list* list)
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

	enable_ansi();
	set_full_screen();
	enable_raw_console_mode();
	hide_mouse_cursor();

	printf("%s", color_codes[base03_color]);
	display_splash_screen();

	decorative_frame();
	print_menu(1);

	int current_option = 1;
	int prev_option = 1;

	while (true) {
		if (key_pressed(VK_UP)) {
			current_option--;
			if (current_option < 1)
				current_option = NUM_OPTIONS;
			update_menu(prev_option, current_option);
			prev_option = current_option;
			Sleep(100);
		}
		else if (key_pressed(VK_DOWN)) {
			current_option++;
			if (current_option > NUM_OPTIONS)
				current_option = 1;
			update_menu(prev_option, current_option);
			prev_option = current_option;
			Sleep(100);
		}

		if (key_pressed(VK_RETURN)) {
			while (_kbhit()) { _getch(); }
			clear_screen();

			switch (current_option) {
				case 1:
					add_medicine_ui(list);
					break;
				case 2:
					update_medicine_ui(list);
					break;
				case 3:
					delete_medicine_stock_ui(list);
					break;
				case 4:
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
				case 5:
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
				case 6:
					display_medicines_ui(list);
					break;
				case 7:
					printf("Exiting the program...\n");
					return;
				default:
					printf("Invalid command.\n");
					break;
			}
			buffer_flush();

			_getch();

			while (_kbhit()) { _getch(); }

			if (current_option == 7)
				_exit(0);

			clear_screen();
			printf("%s", color_codes[base03_color]);
			decorative_frame();
			print_menu(current_option);

			Sleep(100);
		}

		Sleep(10);
	}

}