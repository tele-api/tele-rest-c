#ifndef story_area_TEST
#define story_area_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area.h"
story_area_t* instantiate_story_area(int include_optional);

#include "test_story_area_position.c"
#include "test_story_area_type.c"


story_area_t* instantiate_story_area(int include_optional) {
  story_area_t* story_area = NULL;
  if (include_optional) {
    story_area = story_area_create(
       // false, not to have infinite recursion
      instantiate_story_area_position(0),
      null
    );
  } else {
    story_area = story_area_create(
      NULL,
      null
    );
  }

  return story_area;
}


#ifdef story_area_MAIN

void test_story_area(int include_optional) {
    story_area_t* story_area_1 = instantiate_story_area(include_optional);

	cJSON* jsonstory_area_1 = story_area_convertToJSON(story_area_1);
	printf("story_area :\n%s\n", cJSON_Print(jsonstory_area_1));
	story_area_t* story_area_2 = story_area_parseFromJSON(jsonstory_area_1);
	cJSON* jsonstory_area_2 = story_area_convertToJSON(story_area_2);
	printf("repeating story_area:\n%s\n", cJSON_Print(jsonstory_area_2));
}

int main() {
  test_story_area(1);
  test_story_area(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_MAIN
#endif // story_area_TEST
