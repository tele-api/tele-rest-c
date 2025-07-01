#ifndef background_fill_solid_TEST
#define background_fill_solid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_fill_solid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_fill_solid.h"
background_fill_solid_t* instantiate_background_fill_solid(int include_optional);



background_fill_solid_t* instantiate_background_fill_solid(int include_optional) {
  background_fill_solid_t* background_fill_solid = NULL;
  if (include_optional) {
    background_fill_solid = background_fill_solid_create(
      "solid",
      56
    );
  } else {
    background_fill_solid = background_fill_solid_create(
      "solid",
      56
    );
  }

  return background_fill_solid;
}


#ifdef background_fill_solid_MAIN

void test_background_fill_solid(int include_optional) {
    background_fill_solid_t* background_fill_solid_1 = instantiate_background_fill_solid(include_optional);

	cJSON* jsonbackground_fill_solid_1 = background_fill_solid_convertToJSON(background_fill_solid_1);
	printf("background_fill_solid :\n%s\n", cJSON_Print(jsonbackground_fill_solid_1));
	background_fill_solid_t* background_fill_solid_2 = background_fill_solid_parseFromJSON(jsonbackground_fill_solid_1);
	cJSON* jsonbackground_fill_solid_2 = background_fill_solid_convertToJSON(background_fill_solid_2);
	printf("repeating background_fill_solid:\n%s\n", cJSON_Print(jsonbackground_fill_solid_2));
}

int main() {
  test_background_fill_solid(1);
  test_background_fill_solid(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_fill_solid_MAIN
#endif // background_fill_solid_TEST
