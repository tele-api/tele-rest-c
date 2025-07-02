#ifndef post_send_photo_request_photo_TEST
#define post_send_photo_request_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_photo_request_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_photo_request_photo.h"
post_send_photo_request_photo_t* instantiate_post_send_photo_request_photo(int include_optional);



post_send_photo_request_photo_t* instantiate_post_send_photo_request_photo(int include_optional) {
  post_send_photo_request_photo_t* post_send_photo_request_photo = NULL;
  if (include_optional) {
    post_send_photo_request_photo = post_send_photo_request_photo_create(
    );
  } else {
    post_send_photo_request_photo = post_send_photo_request_photo_create(
    );
  }

  return post_send_photo_request_photo;
}


#ifdef post_send_photo_request_photo_MAIN

void test_post_send_photo_request_photo(int include_optional) {
    post_send_photo_request_photo_t* post_send_photo_request_photo_1 = instantiate_post_send_photo_request_photo(include_optional);

	cJSON* jsonpost_send_photo_request_photo_1 = post_send_photo_request_photo_convertToJSON(post_send_photo_request_photo_1);
	printf("post_send_photo_request_photo :\n%s\n", cJSON_Print(jsonpost_send_photo_request_photo_1));
	post_send_photo_request_photo_t* post_send_photo_request_photo_2 = post_send_photo_request_photo_parseFromJSON(jsonpost_send_photo_request_photo_1);
	cJSON* jsonpost_send_photo_request_photo_2 = post_send_photo_request_photo_convertToJSON(post_send_photo_request_photo_2);
	printf("repeating post_send_photo_request_photo:\n%s\n", cJSON_Print(jsonpost_send_photo_request_photo_2));
}

int main() {
  test_post_send_photo_request_photo(1);
  test_post_send_photo_request_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_photo_request_photo_MAIN
#endif // post_send_photo_request_photo_TEST
