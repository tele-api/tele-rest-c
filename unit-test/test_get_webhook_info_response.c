#ifndef get_webhook_info_response_TEST
#define get_webhook_info_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_webhook_info_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_webhook_info_response.h"
get_webhook_info_response_t* instantiate_get_webhook_info_response(int include_optional);

#include "test_webhook_info.c"


get_webhook_info_response_t* instantiate_get_webhook_info_response(int include_optional) {
  get_webhook_info_response_t* get_webhook_info_response = NULL;
  if (include_optional) {
    get_webhook_info_response = get_webhook_info_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_webhook_info(0)
    );
  } else {
    get_webhook_info_response = get_webhook_info_response_create(
      1,
      NULL
    );
  }

  return get_webhook_info_response;
}


#ifdef get_webhook_info_response_MAIN

void test_get_webhook_info_response(int include_optional) {
    get_webhook_info_response_t* get_webhook_info_response_1 = instantiate_get_webhook_info_response(include_optional);

	cJSON* jsonget_webhook_info_response_1 = get_webhook_info_response_convertToJSON(get_webhook_info_response_1);
	printf("get_webhook_info_response :\n%s\n", cJSON_Print(jsonget_webhook_info_response_1));
	get_webhook_info_response_t* get_webhook_info_response_2 = get_webhook_info_response_parseFromJSON(jsonget_webhook_info_response_1);
	cJSON* jsonget_webhook_info_response_2 = get_webhook_info_response_convertToJSON(get_webhook_info_response_2);
	printf("repeating get_webhook_info_response:\n%s\n", cJSON_Print(jsonget_webhook_info_response_2));
}

int main() {
  test_get_webhook_info_response(1);
  test_get_webhook_info_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_webhook_info_response_MAIN
#endif // get_webhook_info_response_TEST
