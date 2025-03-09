#include "menu.h"
#include "functions.h"

int main(void) {

	medicine_list list = list_init();

	menu_implemented(&list);

	return 0;
}