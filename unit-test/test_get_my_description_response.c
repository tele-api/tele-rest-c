#ifndef get_my_description_response_TEST
#define get_my_description_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_my_description_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_my_description_response.h"
get_my_description_response_t* instantiate_get_my_description_response(int include_optional);

#include "test_bot_description.c"


get_my_description_response_t* instantiate_get_my_description_response(int include_optional) {
  get_my_description_response_t* get_my_description_response = NULL;
  if (include_optional) {
    get_my_description_response = get_my_description_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_bot_description(0)
    );
  } else {
    get_my_description_response = get_my_description_response_create(
      1,
      NULL
    );
  }

  return get_my_description_response;
}


#ifdef get_my_description_response_MAIN

void test_get_my_description_response(int include_optional) {
    get_my_description_response_t* get_my_description_response_1 = instantiate_get_my_description_response(include_optional);

	cJSON* jsonget_my_description_response_1 = get_my_description_response_convertToJSON(get_my_description_response_1);
	printf("get_my_description_response :\n%s\n", cJSON_Print(jsonget_my_description_response_1));
	get_my_description_response_t* get_my_description_response_2 = get_my_description_response_parseFromJSON(jsonget_my_description_response_1);
	cJSON* jsonget_my_description_response_2 = get_my_description_response_convertToJSON(get_my_description_response_2);
	printf("repeating get_my_description_response:\n%s\n", cJSON_Print(jsonget_my_description_response_2));
}

int main() {
  test_get_my_description_response(1);
  test_get_my_description_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_my_description_response_MAIN
#endif // get_my_description_response_TEST
