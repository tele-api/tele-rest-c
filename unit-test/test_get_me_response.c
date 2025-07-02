#ifndef get_me_response_TEST
#define get_me_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_me_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_me_response.h"
get_me_response_t* instantiate_get_me_response(int include_optional);

#include "test_user.c"


get_me_response_t* instantiate_get_me_response(int include_optional) {
  get_me_response_t* get_me_response = NULL;
  if (include_optional) {
    get_me_response = get_me_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    get_me_response = get_me_response_create(
      1,
      NULL
    );
  }

  return get_me_response;
}


#ifdef get_me_response_MAIN

void test_get_me_response(int include_optional) {
    get_me_response_t* get_me_response_1 = instantiate_get_me_response(include_optional);

	cJSON* jsonget_me_response_1 = get_me_response_convertToJSON(get_me_response_1);
	printf("get_me_response :\n%s\n", cJSON_Print(jsonget_me_response_1));
	get_me_response_t* get_me_response_2 = get_me_response_parseFromJSON(jsonget_me_response_1);
	cJSON* jsonget_me_response_2 = get_me_response_convertToJSON(get_me_response_2);
	printf("repeating get_me_response:\n%s\n", cJSON_Print(jsonget_me_response_2));
}

int main() {
  test_get_me_response(1);
  test_get_me_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_me_response_MAIN
#endif // get_me_response_TEST
