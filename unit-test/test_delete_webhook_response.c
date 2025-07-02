#ifndef delete_webhook_response_TEST
#define delete_webhook_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_webhook_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_webhook_response.h"
delete_webhook_response_t* instantiate_delete_webhook_response(int include_optional);



delete_webhook_response_t* instantiate_delete_webhook_response(int include_optional) {
  delete_webhook_response_t* delete_webhook_response = NULL;
  if (include_optional) {
    delete_webhook_response = delete_webhook_response_create(
      1,
      1
    );
  } else {
    delete_webhook_response = delete_webhook_response_create(
      1,
      1
    );
  }

  return delete_webhook_response;
}


#ifdef delete_webhook_response_MAIN

void test_delete_webhook_response(int include_optional) {
    delete_webhook_response_t* delete_webhook_response_1 = instantiate_delete_webhook_response(include_optional);

	cJSON* jsondelete_webhook_response_1 = delete_webhook_response_convertToJSON(delete_webhook_response_1);
	printf("delete_webhook_response :\n%s\n", cJSON_Print(jsondelete_webhook_response_1));
	delete_webhook_response_t* delete_webhook_response_2 = delete_webhook_response_parseFromJSON(jsondelete_webhook_response_1);
	cJSON* jsondelete_webhook_response_2 = delete_webhook_response_convertToJSON(delete_webhook_response_2);
	printf("repeating delete_webhook_response:\n%s\n", cJSON_Print(jsondelete_webhook_response_2));
}

int main() {
  test_delete_webhook_response(1);
  test_delete_webhook_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_webhook_response_MAIN
#endif // delete_webhook_response_TEST
