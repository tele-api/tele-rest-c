#ifndef post_story_request_TEST
#define post_story_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_story_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_story_request.h"
post_story_request_t* instantiate_post_story_request(int include_optional);

#include "test_input_story_content.c"


post_story_request_t* instantiate_post_story_request(int include_optional) {
  post_story_request_t* post_story_request = NULL;
  if (include_optional) {
    post_story_request = post_story_request_create(
      "0",
      null,
      telegram_bot_api_post_story_request_ACTIVEPERIOD_86400,
      "0",
      "0",
      list_createList(),
      list_createList(),
      1,
      1
    );
  } else {
    post_story_request = post_story_request_create(
      "0",
      null,
      telegram_bot_api_post_story_request_ACTIVEPERIOD_86400,
      "0",
      "0",
      list_createList(),
      list_createList(),
      1,
      1
    );
  }

  return post_story_request;
}


#ifdef post_story_request_MAIN

void test_post_story_request(int include_optional) {
    post_story_request_t* post_story_request_1 = instantiate_post_story_request(include_optional);

	cJSON* jsonpost_story_request_1 = post_story_request_convertToJSON(post_story_request_1);
	printf("post_story_request :\n%s\n", cJSON_Print(jsonpost_story_request_1));
	post_story_request_t* post_story_request_2 = post_story_request_parseFromJSON(jsonpost_story_request_1);
	cJSON* jsonpost_story_request_2 = post_story_request_convertToJSON(post_story_request_2);
	printf("repeating post_story_request:\n%s\n", cJSON_Print(jsonpost_story_request_2));
}

int main() {
  test_post_story_request(1);
  test_post_story_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_story_request_MAIN
#endif // post_story_request_TEST
