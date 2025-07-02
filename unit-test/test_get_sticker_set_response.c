#ifndef get_sticker_set_response_TEST
#define get_sticker_set_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_sticker_set_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_sticker_set_response.h"
get_sticker_set_response_t* instantiate_get_sticker_set_response(int include_optional);

#include "test_sticker_set.c"


get_sticker_set_response_t* instantiate_get_sticker_set_response(int include_optional) {
  get_sticker_set_response_t* get_sticker_set_response = NULL;
  if (include_optional) {
    get_sticker_set_response = get_sticker_set_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_sticker_set(0)
    );
  } else {
    get_sticker_set_response = get_sticker_set_response_create(
      1,
      NULL
    );
  }

  return get_sticker_set_response;
}


#ifdef get_sticker_set_response_MAIN

void test_get_sticker_set_response(int include_optional) {
    get_sticker_set_response_t* get_sticker_set_response_1 = instantiate_get_sticker_set_response(include_optional);

	cJSON* jsonget_sticker_set_response_1 = get_sticker_set_response_convertToJSON(get_sticker_set_response_1);
	printf("get_sticker_set_response :\n%s\n", cJSON_Print(jsonget_sticker_set_response_1));
	get_sticker_set_response_t* get_sticker_set_response_2 = get_sticker_set_response_parseFromJSON(jsonget_sticker_set_response_1);
	cJSON* jsonget_sticker_set_response_2 = get_sticker_set_response_convertToJSON(get_sticker_set_response_2);
	printf("repeating get_sticker_set_response:\n%s\n", cJSON_Print(jsonget_sticker_set_response_2));
}

int main() {
  test_get_sticker_set_response(1);
  test_get_sticker_set_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_sticker_set_response_MAIN
#endif // get_sticker_set_response_TEST
