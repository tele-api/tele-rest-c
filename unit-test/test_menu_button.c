#ifndef menu_button_TEST
#define menu_button_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define menu_button_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/menu_button.h"
menu_button_t* instantiate_menu_button(int include_optional);

#include "test_web_app_info.c"


menu_button_t* instantiate_menu_button(int include_optional) {
  menu_button_t* menu_button = NULL;
  if (include_optional) {
    menu_button = menu_button_create(
      "default",
      "0",
       // false, not to have infinite recursion
      instantiate_web_app_info(0)
    );
  } else {
    menu_button = menu_button_create(
      "default",
      "0",
      NULL
    );
  }

  return menu_button;
}


#ifdef menu_button_MAIN

void test_menu_button(int include_optional) {
    menu_button_t* menu_button_1 = instantiate_menu_button(include_optional);

	cJSON* jsonmenu_button_1 = menu_button_convertToJSON(menu_button_1);
	printf("menu_button :\n%s\n", cJSON_Print(jsonmenu_button_1));
	menu_button_t* menu_button_2 = menu_button_parseFromJSON(jsonmenu_button_1);
	cJSON* jsonmenu_button_2 = menu_button_convertToJSON(menu_button_2);
	printf("repeating menu_button:\n%s\n", cJSON_Print(jsonmenu_button_2));
}

int main() {
  test_menu_button(1);
  test_menu_button(0);

  printf("Hello world \n");
  return 0;
}

#endif // menu_button_MAIN
#endif // menu_button_TEST
