#ifndef post_convert_gift_to_stars_request_TEST
#define post_convert_gift_to_stars_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_convert_gift_to_stars_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_convert_gift_to_stars_request.h"
post_convert_gift_to_stars_request_t* instantiate_post_convert_gift_to_stars_request(int include_optional);



post_convert_gift_to_stars_request_t* instantiate_post_convert_gift_to_stars_request(int include_optional) {
  post_convert_gift_to_stars_request_t* post_convert_gift_to_stars_request = NULL;
  if (include_optional) {
    post_convert_gift_to_stars_request = post_convert_gift_to_stars_request_create(
      "0",
      "0"
    );
  } else {
    post_convert_gift_to_stars_request = post_convert_gift_to_stars_request_create(
      "0",
      "0"
    );
  }

  return post_convert_gift_to_stars_request;
}


#ifdef post_convert_gift_to_stars_request_MAIN

void test_post_convert_gift_to_stars_request(int include_optional) {
    post_convert_gift_to_stars_request_t* post_convert_gift_to_stars_request_1 = instantiate_post_convert_gift_to_stars_request(include_optional);

	cJSON* jsonpost_convert_gift_to_stars_request_1 = post_convert_gift_to_stars_request_convertToJSON(post_convert_gift_to_stars_request_1);
	printf("post_convert_gift_to_stars_request :\n%s\n", cJSON_Print(jsonpost_convert_gift_to_stars_request_1));
	post_convert_gift_to_stars_request_t* post_convert_gift_to_stars_request_2 = post_convert_gift_to_stars_request_parseFromJSON(jsonpost_convert_gift_to_stars_request_1);
	cJSON* jsonpost_convert_gift_to_stars_request_2 = post_convert_gift_to_stars_request_convertToJSON(post_convert_gift_to_stars_request_2);
	printf("repeating post_convert_gift_to_stars_request:\n%s\n", cJSON_Print(jsonpost_convert_gift_to_stars_request_2));
}

int main() {
  test_post_convert_gift_to_stars_request(1);
  test_post_convert_gift_to_stars_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_convert_gift_to_stars_request_MAIN
#endif // post_convert_gift_to_stars_request_TEST
