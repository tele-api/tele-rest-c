#ifndef post_read_business_message_request_TEST
#define post_read_business_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_read_business_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_read_business_message_request.h"
post_read_business_message_request_t* instantiate_post_read_business_message_request(int include_optional);



post_read_business_message_request_t* instantiate_post_read_business_message_request(int include_optional) {
  post_read_business_message_request_t* post_read_business_message_request = NULL;
  if (include_optional) {
    post_read_business_message_request = post_read_business_message_request_create(
      "0",
      56,
      56
    );
  } else {
    post_read_business_message_request = post_read_business_message_request_create(
      "0",
      56,
      56
    );
  }

  return post_read_business_message_request;
}


#ifdef post_read_business_message_request_MAIN

void test_post_read_business_message_request(int include_optional) {
    post_read_business_message_request_t* post_read_business_message_request_1 = instantiate_post_read_business_message_request(include_optional);

	cJSON* jsonpost_read_business_message_request_1 = post_read_business_message_request_convertToJSON(post_read_business_message_request_1);
	printf("post_read_business_message_request :\n%s\n", cJSON_Print(jsonpost_read_business_message_request_1));
	post_read_business_message_request_t* post_read_business_message_request_2 = post_read_business_message_request_parseFromJSON(jsonpost_read_business_message_request_1);
	cJSON* jsonpost_read_business_message_request_2 = post_read_business_message_request_convertToJSON(post_read_business_message_request_2);
	printf("repeating post_read_business_message_request:\n%s\n", cJSON_Print(jsonpost_read_business_message_request_2));
}

int main() {
  test_post_read_business_message_request(1);
  test_post_read_business_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_read_business_message_request_MAIN
#endif // post_read_business_message_request_TEST
