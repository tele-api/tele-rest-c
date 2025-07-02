#ifndef get_file_response_TEST
#define get_file_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_file_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_file_response.h"
get_file_response_t* instantiate_get_file_response(int include_optional);

#include "test_binary_t*.c"


get_file_response_t* instantiate_get_file_response(int include_optional) {
  get_file_response_t* get_file_response = NULL;
  if (include_optional) {
    get_file_response = get_file_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_binary_t*(0)
    );
  } else {
    get_file_response = get_file_response_create(
      1,
      NULL
    );
  }

  return get_file_response;
}


#ifdef get_file_response_MAIN

void test_get_file_response(int include_optional) {
    get_file_response_t* get_file_response_1 = instantiate_get_file_response(include_optional);

	cJSON* jsonget_file_response_1 = get_file_response_convertToJSON(get_file_response_1);
	printf("get_file_response :\n%s\n", cJSON_Print(jsonget_file_response_1));
	get_file_response_t* get_file_response_2 = get_file_response_parseFromJSON(jsonget_file_response_1);
	cJSON* jsonget_file_response_2 = get_file_response_convertToJSON(get_file_response_2);
	printf("repeating get_file_response:\n%s\n", cJSON_Print(jsonget_file_response_2));
}

int main() {
  test_get_file_response(1);
  test_get_file_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_file_response_MAIN
#endif // get_file_response_TEST
