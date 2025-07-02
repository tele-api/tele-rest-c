#ifndef set_webhook_response_TEST
#define set_webhook_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_webhook_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_webhook_response.h"
set_webhook_response_t* instantiate_set_webhook_response(int include_optional);



set_webhook_response_t* instantiate_set_webhook_response(int include_optional) {
  set_webhook_response_t* set_webhook_response = NULL;
  if (include_optional) {
    set_webhook_response = set_webhook_response_create(
      1,
      1
    );
  } else {
    set_webhook_response = set_webhook_response_create(
      1,
      1
    );
  }

  return set_webhook_response;
}


#ifdef set_webhook_response_MAIN

void test_set_webhook_response(int include_optional) {
    set_webhook_response_t* set_webhook_response_1 = instantiate_set_webhook_response(include_optional);

	cJSON* jsonset_webhook_response_1 = set_webhook_response_convertToJSON(set_webhook_response_1);
	printf("set_webhook_response :\n%s\n", cJSON_Print(jsonset_webhook_response_1));
	set_webhook_response_t* set_webhook_response_2 = set_webhook_response_parseFromJSON(jsonset_webhook_response_1);
	cJSON* jsonset_webhook_response_2 = set_webhook_response_convertToJSON(set_webhook_response_2);
	printf("repeating set_webhook_response:\n%s\n", cJSON_Print(jsonset_webhook_response_2));
}

int main() {
  test_set_webhook_response(1);
  test_set_webhook_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_webhook_response_MAIN
#endif // set_webhook_response_TEST
