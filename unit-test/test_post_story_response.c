#ifndef post_story_response_TEST
#define post_story_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_story_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_story_response.h"
post_story_response_t* instantiate_post_story_response(int include_optional);

#include "test_story.c"


post_story_response_t* instantiate_post_story_response(int include_optional) {
  post_story_response_t* post_story_response = NULL;
  if (include_optional) {
    post_story_response = post_story_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_story(0)
    );
  } else {
    post_story_response = post_story_response_create(
      1,
      NULL
    );
  }

  return post_story_response;
}


#ifdef post_story_response_MAIN

void test_post_story_response(int include_optional) {
    post_story_response_t* post_story_response_1 = instantiate_post_story_response(include_optional);

	cJSON* jsonpost_story_response_1 = post_story_response_convertToJSON(post_story_response_1);
	printf("post_story_response :\n%s\n", cJSON_Print(jsonpost_story_response_1));
	post_story_response_t* post_story_response_2 = post_story_response_parseFromJSON(jsonpost_story_response_1);
	cJSON* jsonpost_story_response_2 = post_story_response_convertToJSON(post_story_response_2);
	printf("repeating post_story_response:\n%s\n", cJSON_Print(jsonpost_story_response_2));
}

int main() {
  test_post_story_response(1);
  test_post_story_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_story_response_MAIN
#endif // post_story_response_TEST
