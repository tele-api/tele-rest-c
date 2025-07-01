#ifndef story_area_type_unique_gift_TEST
#define story_area_type_unique_gift_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_unique_gift_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type_unique_gift.h"
story_area_type_unique_gift_t* instantiate_story_area_type_unique_gift(int include_optional);



story_area_type_unique_gift_t* instantiate_story_area_type_unique_gift(int include_optional) {
  story_area_type_unique_gift_t* story_area_type_unique_gift = NULL;
  if (include_optional) {
    story_area_type_unique_gift = story_area_type_unique_gift_create(
      "unique_gift",
      "0"
    );
  } else {
    story_area_type_unique_gift = story_area_type_unique_gift_create(
      "unique_gift",
      "0"
    );
  }

  return story_area_type_unique_gift;
}


#ifdef story_area_type_unique_gift_MAIN

void test_story_area_type_unique_gift(int include_optional) {
    story_area_type_unique_gift_t* story_area_type_unique_gift_1 = instantiate_story_area_type_unique_gift(include_optional);

	cJSON* jsonstory_area_type_unique_gift_1 = story_area_type_unique_gift_convertToJSON(story_area_type_unique_gift_1);
	printf("story_area_type_unique_gift :\n%s\n", cJSON_Print(jsonstory_area_type_unique_gift_1));
	story_area_type_unique_gift_t* story_area_type_unique_gift_2 = story_area_type_unique_gift_parseFromJSON(jsonstory_area_type_unique_gift_1);
	cJSON* jsonstory_area_type_unique_gift_2 = story_area_type_unique_gift_convertToJSON(story_area_type_unique_gift_2);
	printf("repeating story_area_type_unique_gift:\n%s\n", cJSON_Print(jsonstory_area_type_unique_gift_2));
}

int main() {
  test_story_area_type_unique_gift(1);
  test_story_area_type_unique_gift(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_unique_gift_MAIN
#endif // story_area_type_unique_gift_TEST
