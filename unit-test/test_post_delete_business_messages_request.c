#ifndef post_delete_business_messages_request_TEST
#define post_delete_business_messages_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_delete_business_messages_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_delete_business_messages_request.h"
post_delete_business_messages_request_t* instantiate_post_delete_business_messages_request(int include_optional);



post_delete_business_messages_request_t* instantiate_post_delete_business_messages_request(int include_optional) {
  post_delete_business_messages_request_t* post_delete_business_messages_request = NULL;
  if (include_optional) {
    post_delete_business_messages_request = post_delete_business_messages_request_create(
      "0",
      list_createList()
    );
  } else {
    post_delete_business_messages_request = post_delete_business_messages_request_create(
      "0",
      list_createList()
    );
  }

  return post_delete_business_messages_request;
}


#ifdef post_delete_business_messages_request_MAIN

void test_post_delete_business_messages_request(int include_optional) {
    post_delete_business_messages_request_t* post_delete_business_messages_request_1 = instantiate_post_delete_business_messages_request(include_optional);

	cJSON* jsonpost_delete_business_messages_request_1 = post_delete_business_messages_request_convertToJSON(post_delete_business_messages_request_1);
	printf("post_delete_business_messages_request :\n%s\n", cJSON_Print(jsonpost_delete_business_messages_request_1));
	post_delete_business_messages_request_t* post_delete_business_messages_request_2 = post_delete_business_messages_request_parseFromJSON(jsonpost_delete_business_messages_request_1);
	cJSON* jsonpost_delete_business_messages_request_2 = post_delete_business_messages_request_convertToJSON(post_delete_business_messages_request_2);
	printf("repeating post_delete_business_messages_request:\n%s\n", cJSON_Print(jsonpost_delete_business_messages_request_2));
}

int main() {
  test_post_delete_business_messages_request(1);
  test_post_delete_business_messages_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_delete_business_messages_request_MAIN
#endif // post_delete_business_messages_request_TEST
