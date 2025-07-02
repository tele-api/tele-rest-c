#ifndef post_copy_message_200_response_TEST
#define post_copy_message_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_copy_message_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_copy_message_200_response.h"
post_copy_message_200_response_t* instantiate_post_copy_message_200_response(int include_optional);

#include "test_message_id.c"


post_copy_message_200_response_t* instantiate_post_copy_message_200_response(int include_optional) {
  post_copy_message_200_response_t* post_copy_message_200_response = NULL;
  if (include_optional) {
    post_copy_message_200_response = post_copy_message_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message_id(0)
    );
  } else {
    post_copy_message_200_response = post_copy_message_200_response_create(
      1,
      NULL
    );
  }

  return post_copy_message_200_response;
}


#ifdef post_copy_message_200_response_MAIN

void test_post_copy_message_200_response(int include_optional) {
    post_copy_message_200_response_t* post_copy_message_200_response_1 = instantiate_post_copy_message_200_response(include_optional);

	cJSON* jsonpost_copy_message_200_response_1 = post_copy_message_200_response_convertToJSON(post_copy_message_200_response_1);
	printf("post_copy_message_200_response :\n%s\n", cJSON_Print(jsonpost_copy_message_200_response_1));
	post_copy_message_200_response_t* post_copy_message_200_response_2 = post_copy_message_200_response_parseFromJSON(jsonpost_copy_message_200_response_1);
	cJSON* jsonpost_copy_message_200_response_2 = post_copy_message_200_response_convertToJSON(post_copy_message_200_response_2);
	printf("repeating post_copy_message_200_response:\n%s\n", cJSON_Print(jsonpost_copy_message_200_response_2));
}

int main() {
  test_post_copy_message_200_response(1);
  test_post_copy_message_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_copy_message_200_response_MAIN
#endif // post_copy_message_200_response_TEST
