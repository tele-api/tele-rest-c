#ifndef background_fill_TEST
#define background_fill_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_fill_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_fill.h"
background_fill_t* instantiate_background_fill(int include_optional);



background_fill_t* instantiate_background_fill(int include_optional) {
  background_fill_t* background_fill = NULL;
  if (include_optional) {
    background_fill = background_fill_create(
      "freeform_gradient",
      56,
      56,
      56,
      56,
      list_createList()
    );
  } else {
    background_fill = background_fill_create(
      "freeform_gradient",
      56,
      56,
      56,
      56,
      list_createList()
    );
  }

  return background_fill;
}


#ifdef background_fill_MAIN

void test_background_fill(int include_optional) {
    background_fill_t* background_fill_1 = instantiate_background_fill(include_optional);

	cJSON* jsonbackground_fill_1 = background_fill_convertToJSON(background_fill_1);
	printf("background_fill :\n%s\n", cJSON_Print(jsonbackground_fill_1));
	background_fill_t* background_fill_2 = background_fill_parseFromJSON(jsonbackground_fill_1);
	cJSON* jsonbackground_fill_2 = background_fill_convertToJSON(background_fill_2);
	printf("repeating background_fill:\n%s\n", cJSON_Print(jsonbackground_fill_2));
}

int main() {
  test_background_fill(1);
  test_background_fill(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_fill_MAIN
#endif // background_fill_TEST
