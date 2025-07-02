#ifndef answer_shipping_query_response_TEST
#define answer_shipping_query_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define answer_shipping_query_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/answer_shipping_query_response.h"
answer_shipping_query_response_t* instantiate_answer_shipping_query_response(int include_optional);



answer_shipping_query_response_t* instantiate_answer_shipping_query_response(int include_optional) {
  answer_shipping_query_response_t* answer_shipping_query_response = NULL;
  if (include_optional) {
    answer_shipping_query_response = answer_shipping_query_response_create(
      1,
      1
    );
  } else {
    answer_shipping_query_response = answer_shipping_query_response_create(
      1,
      1
    );
  }

  return answer_shipping_query_response;
}


#ifdef answer_shipping_query_response_MAIN

void test_answer_shipping_query_response(int include_optional) {
    answer_shipping_query_response_t* answer_shipping_query_response_1 = instantiate_answer_shipping_query_response(include_optional);

	cJSON* jsonanswer_shipping_query_response_1 = answer_shipping_query_response_convertToJSON(answer_shipping_query_response_1);
	printf("answer_shipping_query_response :\n%s\n", cJSON_Print(jsonanswer_shipping_query_response_1));
	answer_shipping_query_response_t* answer_shipping_query_response_2 = answer_shipping_query_response_parseFromJSON(jsonanswer_shipping_query_response_1);
	cJSON* jsonanswer_shipping_query_response_2 = answer_shipping_query_response_convertToJSON(answer_shipping_query_response_2);
	printf("repeating answer_shipping_query_response:\n%s\n", cJSON_Print(jsonanswer_shipping_query_response_2));
}

int main() {
  test_answer_shipping_query_response(1);
  test_answer_shipping_query_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // answer_shipping_query_response_MAIN
#endif // answer_shipping_query_response_TEST
