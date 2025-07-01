#ifndef story_TEST
#define story_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story.h"
story_t* instantiate_story(int include_optional);

#include "test_chat.c"


story_t* instantiate_story(int include_optional) {
  story_t* story = NULL;
  if (include_optional) {
    story = story_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
      56
    );
  } else {
    story = story_create(
      NULL,
      56
    );
  }

  return story;
}


#ifdef story_MAIN

void test_story(int include_optional) {
    story_t* story_1 = instantiate_story(include_optional);

	cJSON* jsonstory_1 = story_convertToJSON(story_1);
	printf("story :\n%s\n", cJSON_Print(jsonstory_1));
	story_t* story_2 = story_parseFromJSON(jsonstory_1);
	cJSON* jsonstory_2 = story_convertToJSON(story_2);
	printf("repeating story:\n%s\n", cJSON_Print(jsonstory_2));
}

int main() {
  test_story(1);
  test_story(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_MAIN
#endif // story_TEST
