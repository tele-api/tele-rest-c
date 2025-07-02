#ifndef post_post_story_200_response_TEST
#define post_post_story_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_post_story_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_post_story_200_response.h"
post_post_story_200_response_t* instantiate_post_post_story_200_response(int include_optional);

#include "test_story.c"


post_post_story_200_response_t* instantiate_post_post_story_200_response(int include_optional) {
  post_post_story_200_response_t* post_post_story_200_response = NULL;
  if (include_optional) {
    post_post_story_200_response = post_post_story_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_story(0)
    );
  } else {
    post_post_story_200_response = post_post_story_200_response_create(
      1,
      NULL
    );
  }

  return post_post_story_200_response;
}


#ifdef post_post_story_200_response_MAIN

void test_post_post_story_200_response(int include_optional) {
    post_post_story_200_response_t* post_post_story_200_response_1 = instantiate_post_post_story_200_response(include_optional);

	cJSON* jsonpost_post_story_200_response_1 = post_post_story_200_response_convertToJSON(post_post_story_200_response_1);
	printf("post_post_story_200_response :\n%s\n", cJSON_Print(jsonpost_post_story_200_response_1));
	post_post_story_200_response_t* post_post_story_200_response_2 = post_post_story_200_response_parseFromJSON(jsonpost_post_story_200_response_1);
	cJSON* jsonpost_post_story_200_response_2 = post_post_story_200_response_convertToJSON(post_post_story_200_response_2);
	printf("repeating post_post_story_200_response:\n%s\n", cJSON_Print(jsonpost_post_story_200_response_2));
}

int main() {
  test_post_post_story_200_response(1);
  test_post_post_story_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_post_story_200_response_MAIN
#endif // post_post_story_200_response_TEST
