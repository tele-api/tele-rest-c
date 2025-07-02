#ifndef post_get_me_200_response_TEST
#define post_get_me_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_get_me_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_get_me_200_response.h"
post_get_me_200_response_t* instantiate_post_get_me_200_response(int include_optional);

#include "test_user.c"


post_get_me_200_response_t* instantiate_post_get_me_200_response(int include_optional) {
  post_get_me_200_response_t* post_get_me_200_response = NULL;
  if (include_optional) {
    post_get_me_200_response = post_get_me_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    post_get_me_200_response = post_get_me_200_response_create(
      1,
      NULL
    );
  }

  return post_get_me_200_response;
}


#ifdef post_get_me_200_response_MAIN

void test_post_get_me_200_response(int include_optional) {
    post_get_me_200_response_t* post_get_me_200_response_1 = instantiate_post_get_me_200_response(include_optional);

	cJSON* jsonpost_get_me_200_response_1 = post_get_me_200_response_convertToJSON(post_get_me_200_response_1);
	printf("post_get_me_200_response :\n%s\n", cJSON_Print(jsonpost_get_me_200_response_1));
	post_get_me_200_response_t* post_get_me_200_response_2 = post_get_me_200_response_parseFromJSON(jsonpost_get_me_200_response_1);
	cJSON* jsonpost_get_me_200_response_2 = post_get_me_200_response_convertToJSON(post_get_me_200_response_2);
	printf("repeating post_get_me_200_response:\n%s\n", cJSON_Print(jsonpost_get_me_200_response_2));
}

int main() {
  test_post_get_me_200_response(1);
  test_post_get_me_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_get_me_200_response_MAIN
#endif // post_get_me_200_response_TEST
