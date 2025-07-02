#ifndef create_invoice_link_request_TEST
#define create_invoice_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_invoice_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_invoice_link_request.h"
create_invoice_link_request_t* instantiate_create_invoice_link_request(int include_optional);



create_invoice_link_request_t* instantiate_create_invoice_link_request(int include_optional) {
  create_invoice_link_request_t* create_invoice_link_request = NULL;
  if (include_optional) {
    create_invoice_link_request = create_invoice_link_request_create(
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
    create_invoice_link_request = create_invoice_link_request_create(
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

  return create_invoice_link_request;
}


#ifdef create_invoice_link_request_MAIN

void test_create_invoice_link_request(int include_optional) {
    create_invoice_link_request_t* create_invoice_link_request_1 = instantiate_create_invoice_link_request(include_optional);

	cJSON* jsoncreate_invoice_link_request_1 = create_invoice_link_request_convertToJSON(create_invoice_link_request_1);
	printf("create_invoice_link_request :\n%s\n", cJSON_Print(jsoncreate_invoice_link_request_1));
	create_invoice_link_request_t* create_invoice_link_request_2 = create_invoice_link_request_parseFromJSON(jsoncreate_invoice_link_request_1);
	cJSON* jsoncreate_invoice_link_request_2 = create_invoice_link_request_convertToJSON(create_invoice_link_request_2);
	printf("repeating create_invoice_link_request:\n%s\n", cJSON_Print(jsoncreate_invoice_link_request_2));
}

int main() {
  test_create_invoice_link_request(1);
  test_create_invoice_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_invoice_link_request_MAIN
#endif // create_invoice_link_request_TEST
