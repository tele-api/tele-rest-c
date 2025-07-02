#ifndef set_passport_data_errors_request_TEST
#define set_passport_data_errors_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_passport_data_errors_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_passport_data_errors_request.h"
set_passport_data_errors_request_t* instantiate_set_passport_data_errors_request(int include_optional);



set_passport_data_errors_request_t* instantiate_set_passport_data_errors_request(int include_optional) {
  set_passport_data_errors_request_t* set_passport_data_errors_request = NULL;
  if (include_optional) {
    set_passport_data_errors_request = set_passport_data_errors_request_create(
      56,
      list_createList()
    );
  } else {
    set_passport_data_errors_request = set_passport_data_errors_request_create(
      56,
      list_createList()
    );
  }

  return set_passport_data_errors_request;
}


#ifdef set_passport_data_errors_request_MAIN

void test_set_passport_data_errors_request(int include_optional) {
    set_passport_data_errors_request_t* set_passport_data_errors_request_1 = instantiate_set_passport_data_errors_request(include_optional);

	cJSON* jsonset_passport_data_errors_request_1 = set_passport_data_errors_request_convertToJSON(set_passport_data_errors_request_1);
	printf("set_passport_data_errors_request :\n%s\n", cJSON_Print(jsonset_passport_data_errors_request_1));
	set_passport_data_errors_request_t* set_passport_data_errors_request_2 = set_passport_data_errors_request_parseFromJSON(jsonset_passport_data_errors_request_1);
	cJSON* jsonset_passport_data_errors_request_2 = set_passport_data_errors_request_convertToJSON(set_passport_data_errors_request_2);
	printf("repeating set_passport_data_errors_request:\n%s\n", cJSON_Print(jsonset_passport_data_errors_request_2));
}

int main() {
  test_set_passport_data_errors_request(1);
  test_set_passport_data_errors_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_passport_data_errors_request_MAIN
#endif // set_passport_data_errors_request_TEST
