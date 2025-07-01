#ifndef story_area_position_TEST
#define story_area_position_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_position_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_position.h"
story_area_position_t* instantiate_story_area_position(int include_optional);



story_area_position_t* instantiate_story_area_position(int include_optional) {
  story_area_position_t* story_area_position = NULL;
  if (include_optional) {
    story_area_position = story_area_position_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    story_area_position = story_area_position_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return story_area_position;
}


#ifdef story_area_position_MAIN

void test_story_area_position(int include_optional) {
    story_area_position_t* story_area_position_1 = instantiate_story_area_position(include_optional);

	cJSON* jsonstory_area_position_1 = story_area_position_convertToJSON(story_area_position_1);
	printf("story_area_position :\n%s\n", cJSON_Print(jsonstory_area_position_1));
	story_area_position_t* story_area_position_2 = story_area_position_parseFromJSON(jsonstory_area_position_1);
	cJSON* jsonstory_area_position_2 = story_area_position_convertToJSON(story_area_position_2);
	printf("repeating story_area_position:\n%s\n", cJSON_Print(jsonstory_area_position_2));
}

int main() {
  test_story_area_position(1);
  test_story_area_position(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_position_MAIN
#endif // story_area_position_TEST
