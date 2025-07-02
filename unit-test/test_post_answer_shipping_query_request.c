#ifndef post_answer_shipping_query_request_TEST
#define post_answer_shipping_query_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_answer_shipping_query_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_answer_shipping_query_request.h"
post_answer_shipping_query_request_t* instantiate_post_answer_shipping_query_request(int include_optional);



post_answer_shipping_query_request_t* instantiate_post_answer_shipping_query_request(int include_optional) {
  post_answer_shipping_query_request_t* post_answer_shipping_query_request = NULL;
  if (include_optional) {
    post_answer_shipping_query_request = post_answer_shipping_query_request_create(
      "0",
      1,
      list_createList(),
      "0"
    );
  } else {
    post_answer_shipping_query_request = post_answer_shipping_query_request_create(
      "0",
      1,
      list_createList(),
      "0"
    );
  }

  return post_answer_shipping_query_request;
}


#ifdef post_answer_shipping_query_request_MAIN

void test_post_answer_shipping_query_request(int include_optional) {
    post_answer_shipping_query_request_t* post_answer_shipping_query_request_1 = instantiate_post_answer_shipping_query_request(include_optional);

	cJSON* jsonpost_answer_shipping_query_request_1 = post_answer_shipping_query_request_convertToJSON(post_answer_shipping_query_request_1);
	printf("post_answer_shipping_query_request :\n%s\n", cJSON_Print(jsonpost_answer_shipping_query_request_1));
	post_answer_shipping_query_request_t* post_answer_shipping_query_request_2 = post_answer_shipping_query_request_parseFromJSON(jsonpost_answer_shipping_query_request_1);
	cJSON* jsonpost_answer_shipping_query_request_2 = post_answer_shipping_query_request_convertToJSON(post_answer_shipping_query_request_2);
	printf("repeating post_answer_shipping_query_request:\n%s\n", cJSON_Print(jsonpost_answer_shipping_query_request_2));
}

int main() {
  test_post_answer_shipping_query_request(1);
  test_post_answer_shipping_query_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_answer_shipping_query_request_MAIN
#endif // post_answer_shipping_query_request_TEST
