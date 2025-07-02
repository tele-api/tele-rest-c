#ifndef get_my_default_administrator_rights_request_TEST
#define get_my_default_administrator_rights_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_my_default_administrator_rights_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_my_default_administrator_rights_request.h"
get_my_default_administrator_rights_request_t* instantiate_get_my_default_administrator_rights_request(int include_optional);



get_my_default_administrator_rights_request_t* instantiate_get_my_default_administrator_rights_request(int include_optional) {
  get_my_default_administrator_rights_request_t* get_my_default_administrator_rights_request = NULL;
  if (include_optional) {
    get_my_default_administrator_rights_request = get_my_default_administrator_rights_request_create(
      1
    );
  } else {
    get_my_default_administrator_rights_request = get_my_default_administrator_rights_request_create(
      1
    );
  }

  return get_my_default_administrator_rights_request;
}


#ifdef get_my_default_administrator_rights_request_MAIN

void test_get_my_default_administrator_rights_request(int include_optional) {
    get_my_default_administrator_rights_request_t* get_my_default_administrator_rights_request_1 = instantiate_get_my_default_administrator_rights_request(include_optional);

	cJSON* jsonget_my_default_administrator_rights_request_1 = get_my_default_administrator_rights_request_convertToJSON(get_my_default_administrator_rights_request_1);
	printf("get_my_default_administrator_rights_request :\n%s\n", cJSON_Print(jsonget_my_default_administrator_rights_request_1));
	get_my_default_administrator_rights_request_t* get_my_default_administrator_rights_request_2 = get_my_default_administrator_rights_request_parseFromJSON(jsonget_my_default_administrator_rights_request_1);
	cJSON* jsonget_my_default_administrator_rights_request_2 = get_my_default_administrator_rights_request_convertToJSON(get_my_default_administrator_rights_request_2);
	printf("repeating get_my_default_administrator_rights_request:\n%s\n", cJSON_Print(jsonget_my_default_administrator_rights_request_2));
}

int main() {
  test_get_my_default_administrator_rights_request(1);
  test_get_my_default_administrator_rights_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_my_default_administrator_rights_request_MAIN
#endif // get_my_default_administrator_rights_request_TEST
