#ifndef _convert_gift_to_stars_post_request_TEST
#define _convert_gift_to_stars_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _convert_gift_to_stars_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_convert_gift_to_stars_post_request.h"
_convert_gift_to_stars_post_request_t* instantiate__convert_gift_to_stars_post_request(int include_optional);



_convert_gift_to_stars_post_request_t* instantiate__convert_gift_to_stars_post_request(int include_optional) {
  _convert_gift_to_stars_post_request_t* _convert_gift_to_stars_post_request = NULL;
  if (include_optional) {
    _convert_gift_to_stars_post_request = _convert_gift_to_stars_post_request_create(
      "0",
      "0"
    );
  } else {
    _convert_gift_to_stars_post_request = _convert_gift_to_stars_post_request_create(
      "0",
      "0"
    );
  }

  return _convert_gift_to_stars_post_request;
}


#ifdef _convert_gift_to_stars_post_request_MAIN

void test__convert_gift_to_stars_post_request(int include_optional) {
    _convert_gift_to_stars_post_request_t* _convert_gift_to_stars_post_request_1 = instantiate__convert_gift_to_stars_post_request(include_optional);

	cJSON* json_convert_gift_to_stars_post_request_1 = _convert_gift_to_stars_post_request_convertToJSON(_convert_gift_to_stars_post_request_1);
	printf("_convert_gift_to_stars_post_request :\n%s\n", cJSON_Print(json_convert_gift_to_stars_post_request_1));
	_convert_gift_to_stars_post_request_t* _convert_gift_to_stars_post_request_2 = _convert_gift_to_stars_post_request_parseFromJSON(json_convert_gift_to_stars_post_request_1);
	cJSON* json_convert_gift_to_stars_post_request_2 = _convert_gift_to_stars_post_request_convertToJSON(_convert_gift_to_stars_post_request_2);
	printf("repeating _convert_gift_to_stars_post_request:\n%s\n", cJSON_Print(json_convert_gift_to_stars_post_request_2));
}

int main() {
  test__convert_gift_to_stars_post_request(1);
  test__convert_gift_to_stars_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _convert_gift_to_stars_post_request_MAIN
#endif // _convert_gift_to_stars_post_request_TEST
