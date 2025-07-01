#ifndef background_type_pattern_TEST
#define background_type_pattern_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_type_pattern_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_type_pattern.h"
background_type_pattern_t* instantiate_background_type_pattern(int include_optional);

#include "test_document.c"
#include "test_background_fill.c"


background_type_pattern_t* instantiate_background_type_pattern(int include_optional) {
  background_type_pattern_t* background_type_pattern = NULL;
  if (include_optional) {
    background_type_pattern = background_type_pattern_create(
      "pattern",
       // false, not to have infinite recursion
      instantiate_document(0),
      null,
      56,
      1,
      1
    );
  } else {
    background_type_pattern = background_type_pattern_create(
      "pattern",
      NULL,
      null,
      56,
      1,
      1
    );
  }

  return background_type_pattern;
}


#ifdef background_type_pattern_MAIN

void test_background_type_pattern(int include_optional) {
    background_type_pattern_t* background_type_pattern_1 = instantiate_background_type_pattern(include_optional);

	cJSON* jsonbackground_type_pattern_1 = background_type_pattern_convertToJSON(background_type_pattern_1);
	printf("background_type_pattern :\n%s\n", cJSON_Print(jsonbackground_type_pattern_1));
	background_type_pattern_t* background_type_pattern_2 = background_type_pattern_parseFromJSON(jsonbackground_type_pattern_1);
	cJSON* jsonbackground_type_pattern_2 = background_type_pattern_convertToJSON(background_type_pattern_2);
	printf("repeating background_type_pattern:\n%s\n", cJSON_Print(jsonbackground_type_pattern_2));
}

int main() {
  test_background_type_pattern(1);
  test_background_type_pattern(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_type_pattern_MAIN
#endif // background_type_pattern_TEST
