#ifndef _transfer_gift_post_request_TEST
#define _transfer_gift_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _transfer_gift_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_transfer_gift_post_request.h"
_transfer_gift_post_request_t* instantiate__transfer_gift_post_request(int include_optional);



_transfer_gift_post_request_t* instantiate__transfer_gift_post_request(int include_optional) {
  _transfer_gift_post_request_t* _transfer_gift_post_request = NULL;
  if (include_optional) {
    _transfer_gift_post_request = _transfer_gift_post_request_create(
      "0",
      "0",
      56,
      56
    );
  } else {
    _transfer_gift_post_request = _transfer_gift_post_request_create(
      "0",
      "0",
      56,
      56
    );
  }

  return _transfer_gift_post_request;
}


#ifdef _transfer_gift_post_request_MAIN

void test__transfer_gift_post_request(int include_optional) {
    _transfer_gift_post_request_t* _transfer_gift_post_request_1 = instantiate__transfer_gift_post_request(include_optional);

	cJSON* json_transfer_gift_post_request_1 = _transfer_gift_post_request_convertToJSON(_transfer_gift_post_request_1);
	printf("_transfer_gift_post_request :\n%s\n", cJSON_Print(json_transfer_gift_post_request_1));
	_transfer_gift_post_request_t* _transfer_gift_post_request_2 = _transfer_gift_post_request_parseFromJSON(json_transfer_gift_post_request_1);
	cJSON* json_transfer_gift_post_request_2 = _transfer_gift_post_request_convertToJSON(_transfer_gift_post_request_2);
	printf("repeating _transfer_gift_post_request:\n%s\n", cJSON_Print(json_transfer_gift_post_request_2));
}

int main() {
  test__transfer_gift_post_request(1);
  test__transfer_gift_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _transfer_gift_post_request_MAIN
#endif // _transfer_gift_post_request_TEST
