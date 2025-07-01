#ifndef story_area_type_TEST
#define story_area_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type.h"
story_area_type_t* instantiate_story_area_type(int include_optional);

#include "test_reaction_type.c"
#include "test_location_address.c"


story_area_type_t* instantiate_story_area_type(int include_optional) {
  story_area_type_t* story_area_type = NULL;
  if (include_optional) {
    story_area_type = story_area_type_create(
      "unique_gift",
      1.337,
      1.337,
      null,
      "0",
      1.337,
      "0",
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_location_address(0),
      1,
      1
    );
  } else {
    story_area_type = story_area_type_create(
      "unique_gift",
      1.337,
      1.337,
      null,
      "0",
      1.337,
      "0",
      56,
      "0",
      NULL,
      1,
      1
    );
  }

  return story_area_type;
}


#ifdef story_area_type_MAIN

void test_story_area_type(int include_optional) {
    story_area_type_t* story_area_type_1 = instantiate_story_area_type(include_optional);

	cJSON* jsonstory_area_type_1 = story_area_type_convertToJSON(story_area_type_1);
	printf("story_area_type :\n%s\n", cJSON_Print(jsonstory_area_type_1));
	story_area_type_t* story_area_type_2 = story_area_type_parseFromJSON(jsonstory_area_type_1);
	cJSON* jsonstory_area_type_2 = story_area_type_convertToJSON(story_area_type_2);
	printf("repeating story_area_type:\n%s\n", cJSON_Print(jsonstory_area_type_2));
}

int main() {
  test_story_area_type(1);
  test_story_area_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_MAIN
#endif // story_area_type_TEST
