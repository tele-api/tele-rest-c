#ifndef menu_button_default_TEST
#define menu_button_default_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define menu_button_default_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/menu_button_default.h"
menu_button_default_t* instantiate_menu_button_default(int include_optional);



menu_button_default_t* instantiate_menu_button_default(int include_optional) {
  menu_button_default_t* menu_button_default = NULL;
  if (include_optional) {
    menu_button_default = menu_button_default_create(
      "default"
    );
  } else {
    menu_button_default = menu_button_default_create(
      "default"
    );
  }

  return menu_button_default;
}


#ifdef menu_button_default_MAIN

void test_menu_button_default(int include_optional) {
    menu_button_default_t* menu_button_default_1 = instantiate_menu_button_default(include_optional);

	cJSON* jsonmenu_button_default_1 = menu_button_default_convertToJSON(menu_button_default_1);
	printf("menu_button_default :\n%s\n", cJSON_Print(jsonmenu_button_default_1));
	menu_button_default_t* menu_button_default_2 = menu_button_default_parseFromJSON(jsonmenu_button_default_1);
	cJSON* jsonmenu_button_default_2 = menu_button_default_convertToJSON(menu_button_default_2);
	printf("repeating menu_button_default:\n%s\n", cJSON_Print(jsonmenu_button_default_2));
}

int main() {
  test_menu_button_default(1);
  test_menu_button_default(0);

  printf("Hello world \n");
  return 0;
}

#endif // menu_button_default_MAIN
#endif // menu_button_default_TEST
