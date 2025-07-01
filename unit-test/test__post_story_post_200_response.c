#ifndef _post_story_post_200_response_TEST
#define _post_story_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _post_story_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_post_story_post_200_response.h"
_post_story_post_200_response_t* instantiate__post_story_post_200_response(int include_optional);

#include "test_story.c"


_post_story_post_200_response_t* instantiate__post_story_post_200_response(int include_optional) {
  _post_story_post_200_response_t* _post_story_post_200_response = NULL;
  if (include_optional) {
    _post_story_post_200_response = _post_story_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_story(0)
    );
  } else {
    _post_story_post_200_response = _post_story_post_200_response_create(
      1,
      NULL
    );
  }

  return _post_story_post_200_response;
}


#ifdef _post_story_post_200_response_MAIN

void test__post_story_post_200_response(int include_optional) {
    _post_story_post_200_response_t* _post_story_post_200_response_1 = instantiate__post_story_post_200_response(include_optional);

	cJSON* json_post_story_post_200_response_1 = _post_story_post_200_response_convertToJSON(_post_story_post_200_response_1);
	printf("_post_story_post_200_response :\n%s\n", cJSON_Print(json_post_story_post_200_response_1));
	_post_story_post_200_response_t* _post_story_post_200_response_2 = _post_story_post_200_response_parseFromJSON(json_post_story_post_200_response_1);
	cJSON* json_post_story_post_200_response_2 = _post_story_post_200_response_convertToJSON(_post_story_post_200_response_2);
	printf("repeating _post_story_post_200_response:\n%s\n", cJSON_Print(json_post_story_post_200_response_2));
}

int main() {
  test__post_story_post_200_response(1);
  test__post_story_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _post_story_post_200_response_MAIN
#endif // _post_story_post_200_response_TEST
