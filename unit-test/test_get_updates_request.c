#ifndef get_updates_request_TEST
#define get_updates_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_updates_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_updates_request.h"
get_updates_request_t* instantiate_get_updates_request(int include_optional);



get_updates_request_t* instantiate_get_updates_request(int include_optional) {
  get_updates_request_t* get_updates_request = NULL;
  if (include_optional) {
    get_updates_request = get_updates_request_create(
      56,
      1,
      56,
      list_createList()
    );
  } else {
    get_updates_request = get_updates_request_create(
      56,
      1,
      56,
      list_createList()
    );
  }

  return get_updates_request;
}


#ifdef get_updates_request_MAIN

void test_get_updates_request(int include_optional) {
    get_updates_request_t* get_updates_request_1 = instantiate_get_updates_request(include_optional);

	cJSON* jsonget_updates_request_1 = get_updates_request_convertToJSON(get_updates_request_1);
	printf("get_updates_request :\n%s\n", cJSON_Print(jsonget_updates_request_1));
	get_updates_request_t* get_updates_request_2 = get_updates_request_parseFromJSON(jsonget_updates_request_1);
	cJSON* jsonget_updates_request_2 = get_updates_request_convertToJSON(get_updates_request_2);
	printf("repeating get_updates_request:\n%s\n", cJSON_Print(jsonget_updates_request_2));
}

int main() {
  test_get_updates_request(1);
  test_get_updates_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_updates_request_MAIN
#endif // get_updates_request_TEST
