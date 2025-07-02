#ifndef answer_web_app_query_request_TEST
#define answer_web_app_query_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define answer_web_app_query_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/answer_web_app_query_request.h"
answer_web_app_query_request_t* instantiate_answer_web_app_query_request(int include_optional);

#include "test_inline_query_result.c"


answer_web_app_query_request_t* instantiate_answer_web_app_query_request(int include_optional) {
  answer_web_app_query_request_t* answer_web_app_query_request = NULL;
  if (include_optional) {
    answer_web_app_query_request = answer_web_app_query_request_create(
      "0",
      null
    );
  } else {
    answer_web_app_query_request = answer_web_app_query_request_create(
      "0",
      null
    );
  }

  return answer_web_app_query_request;
}


#ifdef answer_web_app_query_request_MAIN

void test_answer_web_app_query_request(int include_optional) {
    answer_web_app_query_request_t* answer_web_app_query_request_1 = instantiate_answer_web_app_query_request(include_optional);

	cJSON* jsonanswer_web_app_query_request_1 = answer_web_app_query_request_convertToJSON(answer_web_app_query_request_1);
	printf("answer_web_app_query_request :\n%s\n", cJSON_Print(jsonanswer_web_app_query_request_1));
	answer_web_app_query_request_t* answer_web_app_query_request_2 = answer_web_app_query_request_parseFromJSON(jsonanswer_web_app_query_request_1);
	cJSON* jsonanswer_web_app_query_request_2 = answer_web_app_query_request_convertToJSON(answer_web_app_query_request_2);
	printf("repeating answer_web_app_query_request:\n%s\n", cJSON_Print(jsonanswer_web_app_query_request_2));
}

int main() {
  test_answer_web_app_query_request(1);
  test_answer_web_app_query_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // answer_web_app_query_request_MAIN
#endif // answer_web_app_query_request_TEST
