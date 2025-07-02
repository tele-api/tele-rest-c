#ifndef delete_business_messages_request_TEST
#define delete_business_messages_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_business_messages_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_business_messages_request.h"
delete_business_messages_request_t* instantiate_delete_business_messages_request(int include_optional);



delete_business_messages_request_t* instantiate_delete_business_messages_request(int include_optional) {
  delete_business_messages_request_t* delete_business_messages_request = NULL;
  if (include_optional) {
    delete_business_messages_request = delete_business_messages_request_create(
      "0",
      list_createList()
    );
  } else {
    delete_business_messages_request = delete_business_messages_request_create(
      "0",
      list_createList()
    );
  }

  return delete_business_messages_request;
}


#ifdef delete_business_messages_request_MAIN

void test_delete_business_messages_request(int include_optional) {
    delete_business_messages_request_t* delete_business_messages_request_1 = instantiate_delete_business_messages_request(include_optional);

	cJSON* jsondelete_business_messages_request_1 = delete_business_messages_request_convertToJSON(delete_business_messages_request_1);
	printf("delete_business_messages_request :\n%s\n", cJSON_Print(jsondelete_business_messages_request_1));
	delete_business_messages_request_t* delete_business_messages_request_2 = delete_business_messages_request_parseFromJSON(jsondelete_business_messages_request_1);
	cJSON* jsondelete_business_messages_request_2 = delete_business_messages_request_convertToJSON(delete_business_messages_request_2);
	printf("repeating delete_business_messages_request:\n%s\n", cJSON_Print(jsondelete_business_messages_request_2));
}

int main() {
  test_delete_business_messages_request(1);
  test_delete_business_messages_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_business_messages_request_MAIN
#endif // delete_business_messages_request_TEST
