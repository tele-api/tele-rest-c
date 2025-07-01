#ifndef menu_button_web_app_TEST
#define menu_button_web_app_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define menu_button_web_app_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/menu_button_web_app.h"
menu_button_web_app_t* instantiate_menu_button_web_app(int include_optional);

#include "test_web_app_info.c"


menu_button_web_app_t* instantiate_menu_button_web_app(int include_optional) {
  menu_button_web_app_t* menu_button_web_app = NULL;
  if (include_optional) {
    menu_button_web_app = menu_button_web_app_create(
      "web_app",
      "0",
       // false, not to have infinite recursion
      instantiate_web_app_info(0)
    );
  } else {
    menu_button_web_app = menu_button_web_app_create(
      "web_app",
      "0",
      NULL
    );
  }

  return menu_button_web_app;
}


#ifdef menu_button_web_app_MAIN

void test_menu_button_web_app(int include_optional) {
    menu_button_web_app_t* menu_button_web_app_1 = instantiate_menu_button_web_app(include_optional);

	cJSON* jsonmenu_button_web_app_1 = menu_button_web_app_convertToJSON(menu_button_web_app_1);
	printf("menu_button_web_app :\n%s\n", cJSON_Print(jsonmenu_button_web_app_1));
	menu_button_web_app_t* menu_button_web_app_2 = menu_button_web_app_parseFromJSON(jsonmenu_button_web_app_1);
	cJSON* jsonmenu_button_web_app_2 = menu_button_web_app_convertToJSON(menu_button_web_app_2);
	printf("repeating menu_button_web_app:\n%s\n", cJSON_Print(jsonmenu_button_web_app_2));
}

int main() {
  test_menu_button_web_app(1);
  test_menu_button_web_app(0);

  printf("Hello world \n");
  return 0;
}

#endif // menu_button_web_app_MAIN
#endif // menu_button_web_app_TEST
