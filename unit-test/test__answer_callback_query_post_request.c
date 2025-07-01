#ifndef _answer_callback_query_post_request_TEST
#define _answer_callback_query_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _answer_callback_query_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_answer_callback_query_post_request.h"
_answer_callback_query_post_request_t* instantiate__answer_callback_query_post_request(int include_optional);



_answer_callback_query_post_request_t* instantiate__answer_callback_query_post_request(int include_optional) {
  _answer_callback_query_post_request_t* _answer_callback_query_post_request = NULL;
  if (include_optional) {
    _answer_callback_query_post_request = _answer_callback_query_post_request_create(
      "0",
      "0",
      1,
      "0",
      56
    );
  } else {
    _answer_callback_query_post_request = _answer_callback_query_post_request_create(
      "0",
      "0",
      1,
      "0",
      56
    );
  }

  return _answer_callback_query_post_request;
}


#ifdef _answer_callback_query_post_request_MAIN

void test__answer_callback_query_post_request(int include_optional) {
    _answer_callback_query_post_request_t* _answer_callback_query_post_request_1 = instantiate__answer_callback_query_post_request(include_optional);

	cJSON* json_answer_callback_query_post_request_1 = _answer_callback_query_post_request_convertToJSON(_answer_callback_query_post_request_1);
	printf("_answer_callback_query_post_request :\n%s\n", cJSON_Print(json_answer_callback_query_post_request_1));
	_answer_callback_query_post_request_t* _answer_callback_query_post_request_2 = _answer_callback_query_post_request_parseFromJSON(json_answer_callback_query_post_request_1);
	cJSON* json_answer_callback_query_post_request_2 = _answer_callback_query_post_request_convertToJSON(_answer_callback_query_post_request_2);
	printf("repeating _answer_callback_query_post_request:\n%s\n", cJSON_Print(json_answer_callback_query_post_request_2));
}

int main() {
  test__answer_callback_query_post_request(1);
  test__answer_callback_query_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _answer_callback_query_post_request_MAIN
#endif // _answer_callback_query_post_request_TEST
