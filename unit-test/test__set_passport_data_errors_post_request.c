#ifndef _set_passport_data_errors_post_request_TEST
#define _set_passport_data_errors_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _set_passport_data_errors_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_set_passport_data_errors_post_request.h"
_set_passport_data_errors_post_request_t* instantiate__set_passport_data_errors_post_request(int include_optional);



_set_passport_data_errors_post_request_t* instantiate__set_passport_data_errors_post_request(int include_optional) {
  _set_passport_data_errors_post_request_t* _set_passport_data_errors_post_request = NULL;
  if (include_optional) {
    _set_passport_data_errors_post_request = _set_passport_data_errors_post_request_create(
      56,
      list_createList()
    );
  } else {
    _set_passport_data_errors_post_request = _set_passport_data_errors_post_request_create(
      56,
      list_createList()
    );
  }

  return _set_passport_data_errors_post_request;
}


#ifdef _set_passport_data_errors_post_request_MAIN

void test__set_passport_data_errors_post_request(int include_optional) {
    _set_passport_data_errors_post_request_t* _set_passport_data_errors_post_request_1 = instantiate__set_passport_data_errors_post_request(include_optional);

	cJSON* json_set_passport_data_errors_post_request_1 = _set_passport_data_errors_post_request_convertToJSON(_set_passport_data_errors_post_request_1);
	printf("_set_passport_data_errors_post_request :\n%s\n", cJSON_Print(json_set_passport_data_errors_post_request_1));
	_set_passport_data_errors_post_request_t* _set_passport_data_errors_post_request_2 = _set_passport_data_errors_post_request_parseFromJSON(json_set_passport_data_errors_post_request_1);
	cJSON* json_set_passport_data_errors_post_request_2 = _set_passport_data_errors_post_request_convertToJSON(_set_passport_data_errors_post_request_2);
	printf("repeating _set_passport_data_errors_post_request:\n%s\n", cJSON_Print(json_set_passport_data_errors_post_request_2));
}

int main() {
  test__set_passport_data_errors_post_request(1);
  test__set_passport_data_errors_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _set_passport_data_errors_post_request_MAIN
#endif // _set_passport_data_errors_post_request_TEST
