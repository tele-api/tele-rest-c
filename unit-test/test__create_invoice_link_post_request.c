#ifndef _create_invoice_link_post_request_TEST
#define _create_invoice_link_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _create_invoice_link_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_create_invoice_link_post_request.h"
_create_invoice_link_post_request_t* instantiate__create_invoice_link_post_request(int include_optional);



_create_invoice_link_post_request_t* instantiate__create_invoice_link_post_request(int include_optional) {
  _create_invoice_link_post_request_t* _create_invoice_link_post_request = NULL;
  if (include_optional) {
    _create_invoice_link_post_request = _create_invoice_link_post_request_create(
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      56,
      56,
      list_createList(),
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    _create_invoice_link_post_request = _create_invoice_link_post_request_create(
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      56,
      56,
      list_createList(),
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return _create_invoice_link_post_request;
}


#ifdef _create_invoice_link_post_request_MAIN

void test__create_invoice_link_post_request(int include_optional) {
    _create_invoice_link_post_request_t* _create_invoice_link_post_request_1 = instantiate__create_invoice_link_post_request(include_optional);

	cJSON* json_create_invoice_link_post_request_1 = _create_invoice_link_post_request_convertToJSON(_create_invoice_link_post_request_1);
	printf("_create_invoice_link_post_request :\n%s\n", cJSON_Print(json_create_invoice_link_post_request_1));
	_create_invoice_link_post_request_t* _create_invoice_link_post_request_2 = _create_invoice_link_post_request_parseFromJSON(json_create_invoice_link_post_request_1);
	cJSON* json_create_invoice_link_post_request_2 = _create_invoice_link_post_request_convertToJSON(_create_invoice_link_post_request_2);
	printf("repeating _create_invoice_link_post_request:\n%s\n", cJSON_Print(json_create_invoice_link_post_request_2));
}

int main() {
  test__create_invoice_link_post_request(1);
  test__create_invoice_link_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _create_invoice_link_post_request_MAIN
#endif // _create_invoice_link_post_request_TEST
