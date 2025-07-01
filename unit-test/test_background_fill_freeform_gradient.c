#ifndef background_fill_freeform_gradient_TEST
#define background_fill_freeform_gradient_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_fill_freeform_gradient_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_fill_freeform_gradient.h"
background_fill_freeform_gradient_t* instantiate_background_fill_freeform_gradient(int include_optional);



background_fill_freeform_gradient_t* instantiate_background_fill_freeform_gradient(int include_optional) {
  background_fill_freeform_gradient_t* background_fill_freeform_gradient = NULL;
  if (include_optional) {
    background_fill_freeform_gradient = background_fill_freeform_gradient_create(
      "freeform_gradient",
      list_createList()
    );
  } else {
    background_fill_freeform_gradient = background_fill_freeform_gradient_create(
      "freeform_gradient",
      list_createList()
    );
  }

  return background_fill_freeform_gradient;
}


#ifdef background_fill_freeform_gradient_MAIN

void test_background_fill_freeform_gradient(int include_optional) {
    background_fill_freeform_gradient_t* background_fill_freeform_gradient_1 = instantiate_background_fill_freeform_gradient(include_optional);

	cJSON* jsonbackground_fill_freeform_gradient_1 = background_fill_freeform_gradient_convertToJSON(background_fill_freeform_gradient_1);
	printf("background_fill_freeform_gradient :\n%s\n", cJSON_Print(jsonbackground_fill_freeform_gradient_1));
	background_fill_freeform_gradient_t* background_fill_freeform_gradient_2 = background_fill_freeform_gradient_parseFromJSON(jsonbackground_fill_freeform_gradient_1);
	cJSON* jsonbackground_fill_freeform_gradient_2 = background_fill_freeform_gradient_convertToJSON(background_fill_freeform_gradient_2);
	printf("repeating background_fill_freeform_gradient:\n%s\n", cJSON_Print(jsonbackground_fill_freeform_gradient_2));
}

int main() {
  test_background_fill_freeform_gradient(1);
  test_background_fill_freeform_gradient(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_fill_freeform_gradient_MAIN
#endif // background_fill_freeform_gradient_TEST
