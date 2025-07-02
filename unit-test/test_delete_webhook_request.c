#ifndef delete_webhook_request_TEST
#define delete_webhook_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_webhook_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_webhook_request.h"
delete_webhook_request_t* instantiate_delete_webhook_request(int include_optional);



delete_webhook_request_t* instantiate_delete_webhook_request(int include_optional) {
  delete_webhook_request_t* delete_webhook_request = NULL;
  if (include_optional) {
    delete_webhook_request = delete_webhook_request_create(
      1
    );
  } else {
    delete_webhook_request = delete_webhook_request_create(
      1
    );
  }

  return delete_webhook_request;
}


#ifdef delete_webhook_request_MAIN

void test_delete_webhook_request(int include_optional) {
    delete_webhook_request_t* delete_webhook_request_1 = instantiate_delete_webhook_request(include_optional);

	cJSON* jsondelete_webhook_request_1 = delete_webhook_request_convertToJSON(delete_webhook_request_1);
	printf("delete_webhook_request :\n%s\n", cJSON_Print(jsondelete_webhook_request_1));
	delete_webhook_request_t* delete_webhook_request_2 = delete_webhook_request_parseFromJSON(jsondelete_webhook_request_1);
	cJSON* jsondelete_webhook_request_2 = delete_webhook_request_convertToJSON(delete_webhook_request_2);
	printf("repeating delete_webhook_request:\n%s\n", cJSON_Print(jsondelete_webhook_request_2));
}

int main() {
  test_delete_webhook_request(1);
  test_delete_webhook_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_webhook_request_MAIN
#endif // delete_webhook_request_TEST
