#ifndef answer_shipping_query_request_TEST
#define answer_shipping_query_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define answer_shipping_query_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/answer_shipping_query_request.h"
answer_shipping_query_request_t* instantiate_answer_shipping_query_request(int include_optional);



answer_shipping_query_request_t* instantiate_answer_shipping_query_request(int include_optional) {
  answer_shipping_query_request_t* answer_shipping_query_request = NULL;
  if (include_optional) {
    answer_shipping_query_request = answer_shipping_query_request_create(
      "0",
      1,
      list_createList(),
      "0"
    );
  } else {
    answer_shipping_query_request = answer_shipping_query_request_create(
      "0",
      1,
      list_createList(),
      "0"
    );
  }

  return answer_shipping_query_request;
}


#ifdef answer_shipping_query_request_MAIN

void test_answer_shipping_query_request(int include_optional) {
    answer_shipping_query_request_t* answer_shipping_query_request_1 = instantiate_answer_shipping_query_request(include_optional);

	cJSON* jsonanswer_shipping_query_request_1 = answer_shipping_query_request_convertToJSON(answer_shipping_query_request_1);
	printf("answer_shipping_query_request :\n%s\n", cJSON_Print(jsonanswer_shipping_query_request_1));
	answer_shipping_query_request_t* answer_shipping_query_request_2 = answer_shipping_query_request_parseFromJSON(jsonanswer_shipping_query_request_1);
	cJSON* jsonanswer_shipping_query_request_2 = answer_shipping_query_request_convertToJSON(answer_shipping_query_request_2);
	printf("repeating answer_shipping_query_request:\n%s\n", cJSON_Print(jsonanswer_shipping_query_request_2));
}

int main() {
  test_answer_shipping_query_request(1);
  test_answer_shipping_query_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // answer_shipping_query_request_MAIN
#endif // answer_shipping_query_request_TEST
