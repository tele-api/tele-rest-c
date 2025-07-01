#ifndef story_area_type_suggested_reaction_TEST
#define story_area_type_suggested_reaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_suggested_reaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type_suggested_reaction.h"
story_area_type_suggested_reaction_t* instantiate_story_area_type_suggested_reaction(int include_optional);

#include "test_reaction_type.c"


story_area_type_suggested_reaction_t* instantiate_story_area_type_suggested_reaction(int include_optional) {
  story_area_type_suggested_reaction_t* story_area_type_suggested_reaction = NULL;
  if (include_optional) {
    story_area_type_suggested_reaction = story_area_type_suggested_reaction_create(
      "suggested_reaction",
      null,
      1,
      1
    );
  } else {
    story_area_type_suggested_reaction = story_area_type_suggested_reaction_create(
      "suggested_reaction",
      null,
      1,
      1
    );
  }

  return story_area_type_suggested_reaction;
}


#ifdef story_area_type_suggested_reaction_MAIN

void test_story_area_type_suggested_reaction(int include_optional) {
    story_area_type_suggested_reaction_t* story_area_type_suggested_reaction_1 = instantiate_story_area_type_suggested_reaction(include_optional);

	cJSON* jsonstory_area_type_suggested_reaction_1 = story_area_type_suggested_reaction_convertToJSON(story_area_type_suggested_reaction_1);
	printf("story_area_type_suggested_reaction :\n%s\n", cJSON_Print(jsonstory_area_type_suggested_reaction_1));
	story_area_type_suggested_reaction_t* story_area_type_suggested_reaction_2 = story_area_type_suggested_reaction_parseFromJSON(jsonstory_area_type_suggested_reaction_1);
	cJSON* jsonstory_area_type_suggested_reaction_2 = story_area_type_suggested_reaction_convertToJSON(story_area_type_suggested_reaction_2);
	printf("repeating story_area_type_suggested_reaction:\n%s\n", cJSON_Print(jsonstory_area_type_suggested_reaction_2));
}

int main() {
  test_story_area_type_suggested_reaction(1);
  test_story_area_type_suggested_reaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_suggested_reaction_MAIN
#endif // story_area_type_suggested_reaction_TEST
