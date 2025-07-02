#ifndef set_webhook_request_TEST
#define set_webhook_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_webhook_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_webhook_request.h"
set_webhook_request_t* instantiate_set_webhook_request(int include_optional);



set_webhook_request_t* instantiate_set_webhook_request(int include_optional) {
  set_webhook_request_t* set_webhook_request = NULL;
  if (include_optional) {
    set_webhook_request = set_webhook_request_create(
      "0",
      null,
      "0",
      56,
      list_createList(),
      1,
      "0"
    );
  } else {
    set_webhook_request = set_webhook_request_create(
      "0",
      null,
      "0",
      56,
      list_createList(),
      1,
      "0"
    );
  }

  return set_webhook_request;
}


#ifdef set_webhook_request_MAIN

void test_set_webhook_request(int include_optional) {
    set_webhook_request_t* set_webhook_request_1 = instantiate_set_webhook_request(include_optional);

	cJSON* jsonset_webhook_request_1 = set_webhook_request_convertToJSON(set_webhook_request_1);
	printf("set_webhook_request :\n%s\n", cJSON_Print(jsonset_webhook_request_1));
	set_webhook_request_t* set_webhook_request_2 = set_webhook_request_parseFromJSON(jsonset_webhook_request_1);
	cJSON* jsonset_webhook_request_2 = set_webhook_request_convertToJSON(set_webhook_request_2);
	printf("repeating set_webhook_request:\n%s\n", cJSON_Print(jsonset_webhook_request_2));
}

int main() {
  test_set_webhook_request(1);
  test_set_webhook_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_webhook_request_MAIN
#endif // set_webhook_request_TEST
