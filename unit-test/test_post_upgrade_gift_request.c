#ifndef post_upgrade_gift_request_TEST
#define post_upgrade_gift_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_upgrade_gift_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_upgrade_gift_request.h"
post_upgrade_gift_request_t* instantiate_post_upgrade_gift_request(int include_optional);



post_upgrade_gift_request_t* instantiate_post_upgrade_gift_request(int include_optional) {
  post_upgrade_gift_request_t* post_upgrade_gift_request = NULL;
  if (include_optional) {
    post_upgrade_gift_request = post_upgrade_gift_request_create(
      "0",
      "0",
      1,
      56
    );
  } else {
    post_upgrade_gift_request = post_upgrade_gift_request_create(
      "0",
      "0",
      1,
      56
    );
  }

  return post_upgrade_gift_request;
}


#ifdef post_upgrade_gift_request_MAIN

void test_post_upgrade_gift_request(int include_optional) {
    post_upgrade_gift_request_t* post_upgrade_gift_request_1 = instantiate_post_upgrade_gift_request(include_optional);

	cJSON* jsonpost_upgrade_gift_request_1 = post_upgrade_gift_request_convertToJSON(post_upgrade_gift_request_1);
	printf("post_upgrade_gift_request :\n%s\n", cJSON_Print(jsonpost_upgrade_gift_request_1));
	post_upgrade_gift_request_t* post_upgrade_gift_request_2 = post_upgrade_gift_request_parseFromJSON(jsonpost_upgrade_gift_request_1);
	cJSON* jsonpost_upgrade_gift_request_2 = post_upgrade_gift_request_convertToJSON(post_upgrade_gift_request_2);
	printf("repeating post_upgrade_gift_request:\n%s\n", cJSON_Print(jsonpost_upgrade_gift_request_2));
}

int main() {
  test_post_upgrade_gift_request(1);
  test_post_upgrade_gift_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_upgrade_gift_request_MAIN
#endif // post_upgrade_gift_request_TEST
