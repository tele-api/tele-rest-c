#ifndef background_type_TEST
#define background_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_type.h"
background_type_t* instantiate_background_type(int include_optional);

#include "test_background_fill.c"
#include "test_document.c"


background_type_t* instantiate_background_type(int include_optional) {
  background_type_t* background_type = NULL;
  if (include_optional) {
    background_type = background_type_create(
      "chat_theme",
      null,
      56,
       // false, not to have infinite recursion
      instantiate_document(0),
      56,
      "0",
      1,
      1,
      1
    );
  } else {
    background_type = background_type_create(
      "chat_theme",
      null,
      56,
      NULL,
      56,
      "0",
      1,
      1,
      1
    );
  }

  return background_type;
}


#ifdef background_type_MAIN

void test_background_type(int include_optional) {
    background_type_t* background_type_1 = instantiate_background_type(include_optional);

	cJSON* jsonbackground_type_1 = background_type_convertToJSON(background_type_1);
	printf("background_type :\n%s\n", cJSON_Print(jsonbackground_type_1));
	background_type_t* background_type_2 = background_type_parseFromJSON(jsonbackground_type_1);
	cJSON* jsonbackground_type_2 = background_type_convertToJSON(background_type_2);
	printf("repeating background_type:\n%s\n", cJSON_Print(jsonbackground_type_2));
}

int main() {
  test_background_type(1);
  test_background_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_type_MAIN
#endif // background_type_TEST
