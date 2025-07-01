#ifndef story_area_type_location_TEST
#define story_area_type_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type_location.h"
story_area_type_location_t* instantiate_story_area_type_location(int include_optional);

#include "test_location_address.c"


story_area_type_location_t* instantiate_story_area_type_location(int include_optional) {
  story_area_type_location_t* story_area_type_location = NULL;
  if (include_optional) {
    story_area_type_location = story_area_type_location_create(
      "location",
      1.337,
      1.337,
       // false, not to have infinite recursion
      instantiate_location_address(0)
    );
  } else {
    story_area_type_location = story_area_type_location_create(
      "location",
      1.337,
      1.337,
      NULL
    );
  }

  return story_area_type_location;
}


#ifdef story_area_type_location_MAIN

void test_story_area_type_location(int include_optional) {
    story_area_type_location_t* story_area_type_location_1 = instantiate_story_area_type_location(include_optional);

	cJSON* jsonstory_area_type_location_1 = story_area_type_location_convertToJSON(story_area_type_location_1);
	printf("story_area_type_location :\n%s\n", cJSON_Print(jsonstory_area_type_location_1));
	story_area_type_location_t* story_area_type_location_2 = story_area_type_location_parseFromJSON(jsonstory_area_type_location_1);
	cJSON* jsonstory_area_type_location_2 = story_area_type_location_convertToJSON(story_area_type_location_2);
	printf("repeating story_area_type_location:\n%s\n", cJSON_Print(jsonstory_area_type_location_2));
}

int main() {
  test_story_area_type_location(1);
  test_story_area_type_location(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_location_MAIN
#endif // story_area_type_location_TEST
