#ifndef _answer_web_app_query_post_200_response_TEST
#define _answer_web_app_query_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _answer_web_app_query_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_answer_web_app_query_post_200_response.h"
_answer_web_app_query_post_200_response_t* instantiate__answer_web_app_query_post_200_response(int include_optional);

#include "test_sent_web_app_message.c"


_answer_web_app_query_post_200_response_t* instantiate__answer_web_app_query_post_200_response(int include_optional) {
  _answer_web_app_query_post_200_response_t* _answer_web_app_query_post_200_response = NULL;
  if (include_optional) {
    _answer_web_app_query_post_200_response = _answer_web_app_query_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_sent_web_app_message(0)
    );
  } else {
    _answer_web_app_query_post_200_response = _answer_web_app_query_post_200_response_create(
      1,
      NULL
    );
  }

  return _answer_web_app_query_post_200_response;
}


#ifdef _answer_web_app_query_post_200_response_MAIN

void test__answer_web_app_query_post_200_response(int include_optional) {
    _answer_web_app_query_post_200_response_t* _answer_web_app_query_post_200_response_1 = instantiate__answer_web_app_query_post_200_response(include_optional);

	cJSON* json_answer_web_app_query_post_200_response_1 = _answer_web_app_query_post_200_response_convertToJSON(_answer_web_app_query_post_200_response_1);
	printf("_answer_web_app_query_post_200_response :\n%s\n", cJSON_Print(json_answer_web_app_query_post_200_response_1));
	_answer_web_app_query_post_200_response_t* _answer_web_app_query_post_200_response_2 = _answer_web_app_query_post_200_response_parseFromJSON(json_answer_web_app_query_post_200_response_1);
	cJSON* json_answer_web_app_query_post_200_response_2 = _answer_web_app_query_post_200_response_convertToJSON(_answer_web_app_query_post_200_response_2);
	printf("repeating _answer_web_app_query_post_200_response:\n%s\n", cJSON_Print(json_answer_web_app_query_post_200_response_2));
}

int main() {
  test__answer_web_app_query_post_200_response(1);
  test__answer_web_app_query_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _answer_web_app_query_post_200_response_MAIN
#endif // _answer_web_app_query_post_200_response_TEST
