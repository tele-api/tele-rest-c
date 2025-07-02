#ifndef post_verify_user_request_TEST
#define post_verify_user_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_verify_user_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_verify_user_request.h"
post_verify_user_request_t* instantiate_post_verify_user_request(int include_optional);



post_verify_user_request_t* instantiate_post_verify_user_request(int include_optional) {
  post_verify_user_request_t* post_verify_user_request = NULL;
  if (include_optional) {
    post_verify_user_request = post_verify_user_request_create(
      56,
      "0"
    );
  } else {
    post_verify_user_request = post_verify_user_request_create(
      56,
      "0"
    );
  }

  return post_verify_user_request;
}


#ifdef post_verify_user_request_MAIN

void test_post_verify_user_request(int include_optional) {
    post_verify_user_request_t* post_verify_user_request_1 = instantiate_post_verify_user_request(include_optional);

	cJSON* jsonpost_verify_user_request_1 = post_verify_user_request_convertToJSON(post_verify_user_request_1);
	printf("post_verify_user_request :\n%s\n", cJSON_Print(jsonpost_verify_user_request_1));
	post_verify_user_request_t* post_verify_user_request_2 = post_verify_user_request_parseFromJSON(jsonpost_verify_user_request_1);
	cJSON* jsonpost_verify_user_request_2 = post_verify_user_request_convertToJSON(post_verify_user_request_2);
	printf("repeating post_verify_user_request:\n%s\n", cJSON_Print(jsonpost_verify_user_request_2));
}

int main() {
  test_post_verify_user_request(1);
  test_post_verify_user_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_verify_user_request_MAIN
#endif // post_verify_user_request_TEST
