#ifndef background_type_chat_theme_TEST
#define background_type_chat_theme_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_type_chat_theme_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_type_chat_theme.h"
background_type_chat_theme_t* instantiate_background_type_chat_theme(int include_optional);



background_type_chat_theme_t* instantiate_background_type_chat_theme(int include_optional) {
  background_type_chat_theme_t* background_type_chat_theme = NULL;
  if (include_optional) {
    background_type_chat_theme = background_type_chat_theme_create(
      "chat_theme",
      "0"
    );
  } else {
    background_type_chat_theme = background_type_chat_theme_create(
      "chat_theme",
      "0"
    );
  }

  return background_type_chat_theme;
}


#ifdef background_type_chat_theme_MAIN

void test_background_type_chat_theme(int include_optional) {
    background_type_chat_theme_t* background_type_chat_theme_1 = instantiate_background_type_chat_theme(include_optional);

	cJSON* jsonbackground_type_chat_theme_1 = background_type_chat_theme_convertToJSON(background_type_chat_theme_1);
	printf("background_type_chat_theme :\n%s\n", cJSON_Print(jsonbackground_type_chat_theme_1));
	background_type_chat_theme_t* background_type_chat_theme_2 = background_type_chat_theme_parseFromJSON(jsonbackground_type_chat_theme_1);
	cJSON* jsonbackground_type_chat_theme_2 = background_type_chat_theme_convertToJSON(background_type_chat_theme_2);
	printf("repeating background_type_chat_theme:\n%s\n", cJSON_Print(jsonbackground_type_chat_theme_2));
}

int main() {
  test_background_type_chat_theme(1);
  test_background_type_chat_theme(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_type_chat_theme_MAIN
#endif // background_type_chat_theme_TEST
