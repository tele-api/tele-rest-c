#ifndef menu_button_commands_TEST
#define menu_button_commands_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define menu_button_commands_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/menu_button_commands.h"
menu_button_commands_t* instantiate_menu_button_commands(int include_optional);



menu_button_commands_t* instantiate_menu_button_commands(int include_optional) {
  menu_button_commands_t* menu_button_commands = NULL;
  if (include_optional) {
    menu_button_commands = menu_button_commands_create(
      "commands"
    );
  } else {
    menu_button_commands = menu_button_commands_create(
      "commands"
    );
  }

  return menu_button_commands;
}


#ifdef menu_button_commands_MAIN

void test_menu_button_commands(int include_optional) {
    menu_button_commands_t* menu_button_commands_1 = instantiate_menu_button_commands(include_optional);

	cJSON* jsonmenu_button_commands_1 = menu_button_commands_convertToJSON(menu_button_commands_1);
	printf("menu_button_commands :\n%s\n", cJSON_Print(jsonmenu_button_commands_1));
	menu_button_commands_t* menu_button_commands_2 = menu_button_commands_parseFromJSON(jsonmenu_button_commands_1);
	cJSON* jsonmenu_button_commands_2 = menu_button_commands_convertToJSON(menu_button_commands_2);
	printf("repeating menu_button_commands:\n%s\n", cJSON_Print(jsonmenu_button_commands_2));
}

int main() {
  test_menu_button_commands(1);
  test_menu_button_commands(0);

  printf("Hello world \n");
  return 0;
}

#endif // menu_button_commands_MAIN
#endif // menu_button_commands_TEST
