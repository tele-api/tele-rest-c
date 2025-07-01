#ifndef background_type_fill_TEST
#define background_type_fill_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_type_fill_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_type_fill.h"
background_type_fill_t* instantiate_background_type_fill(int include_optional);

#include "test_background_fill.c"


background_type_fill_t* instantiate_background_type_fill(int include_optional) {
  background_type_fill_t* background_type_fill = NULL;
  if (include_optional) {
    background_type_fill = background_type_fill_create(
      "fill",
      null,
      56
    );
  } else {
    background_type_fill = background_type_fill_create(
      "fill",
      null,
      56
    );
  }

  return background_type_fill;
}


#ifdef background_type_fill_MAIN

void test_background_type_fill(int include_optional) {
    background_type_fill_t* background_type_fill_1 = instantiate_background_type_fill(include_optional);

	cJSON* jsonbackground_type_fill_1 = background_type_fill_convertToJSON(background_type_fill_1);
	printf("background_type_fill :\n%s\n", cJSON_Print(jsonbackground_type_fill_1));
	background_type_fill_t* background_type_fill_2 = background_type_fill_parseFromJSON(jsonbackground_type_fill_1);
	cJSON* jsonbackground_type_fill_2 = background_type_fill_convertToJSON(background_type_fill_2);
	printf("repeating background_type_fill:\n%s\n", cJSON_Print(jsonbackground_type_fill_2));
}

int main() {
  test_background_type_fill(1);
  test_background_type_fill(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_type_fill_MAIN
#endif // background_type_fill_TEST
