#ifndef get_file_request_TEST
#define get_file_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_file_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_file_request.h"
get_file_request_t* instantiate_get_file_request(int include_optional);



get_file_request_t* instantiate_get_file_request(int include_optional) {
  get_file_request_t* get_file_request = NULL;
  if (include_optional) {
    get_file_request = get_file_request_create(
      "0"
    );
  } else {
    get_file_request = get_file_request_create(
      "0"
    );
  }

  return get_file_request;
}


#ifdef get_file_request_MAIN

void test_get_file_request(int include_optional) {
    get_file_request_t* get_file_request_1 = instantiate_get_file_request(include_optional);

	cJSON* jsonget_file_request_1 = get_file_request_convertToJSON(get_file_request_1);
	printf("get_file_request :\n%s\n", cJSON_Print(jsonget_file_request_1));
	get_file_request_t* get_file_request_2 = get_file_request_parseFromJSON(jsonget_file_request_1);
	cJSON* jsonget_file_request_2 = get_file_request_convertToJSON(get_file_request_2);
	printf("repeating get_file_request:\n%s\n", cJSON_Print(jsonget_file_request_2));
}

int main() {
  test_get_file_request(1);
  test_get_file_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_file_request_MAIN
#endif // get_file_request_TEST
