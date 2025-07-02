#ifndef get_updates_response_TEST
#define get_updates_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_updates_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_updates_response.h"
get_updates_response_t* instantiate_get_updates_response(int include_optional);



get_updates_response_t* instantiate_get_updates_response(int include_optional) {
  get_updates_response_t* get_updates_response = NULL;
  if (include_optional) {
    get_updates_response = get_updates_response_create(
      1,
      list_createList()
    );
  } else {
    get_updates_response = get_updates_response_create(
      1,
      list_createList()
    );
  }

  return get_updates_response;
}


#ifdef get_updates_response_MAIN

void test_get_updates_response(int include_optional) {
    get_updates_response_t* get_updates_response_1 = instantiate_get_updates_response(include_optional);

	cJSON* jsonget_updates_response_1 = get_updates_response_convertToJSON(get_updates_response_1);
	printf("get_updates_response :\n%s\n", cJSON_Print(jsonget_updates_response_1));
	get_updates_response_t* get_updates_response_2 = get_updates_response_parseFromJSON(jsonget_updates_response_1);
	cJSON* jsonget_updates_response_2 = get_updates_response_convertToJSON(get_updates_response_2);
	printf("repeating get_updates_response:\n%s\n", cJSON_Print(jsonget_updates_response_2));
}

int main() {
  test_get_updates_response(1);
  test_get_updates_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_updates_response_MAIN
#endif // get_updates_response_TEST
