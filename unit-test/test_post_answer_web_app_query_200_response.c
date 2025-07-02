#ifndef post_answer_web_app_query_200_response_TEST
#define post_answer_web_app_query_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_answer_web_app_query_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_answer_web_app_query_200_response.h"
post_answer_web_app_query_200_response_t* instantiate_post_answer_web_app_query_200_response(int include_optional);

#include "test_sent_web_app_message.c"


post_answer_web_app_query_200_response_t* instantiate_post_answer_web_app_query_200_response(int include_optional) {
  post_answer_web_app_query_200_response_t* post_answer_web_app_query_200_response = NULL;
  if (include_optional) {
    post_answer_web_app_query_200_response = post_answer_web_app_query_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_sent_web_app_message(0)
    );
  } else {
    post_answer_web_app_query_200_response = post_answer_web_app_query_200_response_create(
      1,
      NULL
    );
  }

  return post_answer_web_app_query_200_response;
}


#ifdef post_answer_web_app_query_200_response_MAIN

void test_post_answer_web_app_query_200_response(int include_optional) {
    post_answer_web_app_query_200_response_t* post_answer_web_app_query_200_response_1 = instantiate_post_answer_web_app_query_200_response(include_optional);

	cJSON* jsonpost_answer_web_app_query_200_response_1 = post_answer_web_app_query_200_response_convertToJSON(post_answer_web_app_query_200_response_1);
	printf("post_answer_web_app_query_200_response :\n%s\n", cJSON_Print(jsonpost_answer_web_app_query_200_response_1));
	post_answer_web_app_query_200_response_t* post_answer_web_app_query_200_response_2 = post_answer_web_app_query_200_response_parseFromJSON(jsonpost_answer_web_app_query_200_response_1);
	cJSON* jsonpost_answer_web_app_query_200_response_2 = post_answer_web_app_query_200_response_convertToJSON(post_answer_web_app_query_200_response_2);
	printf("repeating post_answer_web_app_query_200_response:\n%s\n", cJSON_Print(jsonpost_answer_web_app_query_200_response_2));
}

int main() {
  test_post_answer_web_app_query_200_response(1);
  test_post_answer_web_app_query_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_answer_web_app_query_200_response_MAIN
#endif // post_answer_web_app_query_200_response_TEST
