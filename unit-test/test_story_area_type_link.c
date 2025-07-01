#ifndef story_area_type_link_TEST
#define story_area_type_link_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_link_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type_link.h"
story_area_type_link_t* instantiate_story_area_type_link(int include_optional);



story_area_type_link_t* instantiate_story_area_type_link(int include_optional) {
  story_area_type_link_t* story_area_type_link = NULL;
  if (include_optional) {
    story_area_type_link = story_area_type_link_create(
      "link",
      "0"
    );
  } else {
    story_area_type_link = story_area_type_link_create(
      "link",
      "0"
    );
  }

  return story_area_type_link;
}


#ifdef story_area_type_link_MAIN

void test_story_area_type_link(int include_optional) {
    story_area_type_link_t* story_area_type_link_1 = instantiate_story_area_type_link(include_optional);

	cJSON* jsonstory_area_type_link_1 = story_area_type_link_convertToJSON(story_area_type_link_1);
	printf("story_area_type_link :\n%s\n", cJSON_Print(jsonstory_area_type_link_1));
	story_area_type_link_t* story_area_type_link_2 = story_area_type_link_parseFromJSON(jsonstory_area_type_link_1);
	cJSON* jsonstory_area_type_link_2 = story_area_type_link_convertToJSON(story_area_type_link_2);
	printf("repeating story_area_type_link:\n%s\n", cJSON_Print(jsonstory_area_type_link_2));
}

int main() {
  test_story_area_type_link(1);
  test_story_area_type_link(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_link_MAIN
#endif // story_area_type_link_TEST
