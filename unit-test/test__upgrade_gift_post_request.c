#ifndef _upgrade_gift_post_request_TEST
#define _upgrade_gift_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _upgrade_gift_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_upgrade_gift_post_request.h"
_upgrade_gift_post_request_t* instantiate__upgrade_gift_post_request(int include_optional);



_upgrade_gift_post_request_t* instantiate__upgrade_gift_post_request(int include_optional) {
  _upgrade_gift_post_request_t* _upgrade_gift_post_request = NULL;
  if (include_optional) {
    _upgrade_gift_post_request = _upgrade_gift_post_request_create(
      "0",
      "0",
      1,
      56
    );
  } else {
    _upgrade_gift_post_request = _upgrade_gift_post_request_create(
      "0",
      "0",
      1,
      56
    );
  }

  return _upgrade_gift_post_request;
}


#ifdef _upgrade_gift_post_request_MAIN

void test__upgrade_gift_post_request(int include_optional) {
    _upgrade_gift_post_request_t* _upgrade_gift_post_request_1 = instantiate__upgrade_gift_post_request(include_optional);

	cJSON* json_upgrade_gift_post_request_1 = _upgrade_gift_post_request_convertToJSON(_upgrade_gift_post_request_1);
	printf("_upgrade_gift_post_request :\n%s\n", cJSON_Print(json_upgrade_gift_post_request_1));
	_upgrade_gift_post_request_t* _upgrade_gift_post_request_2 = _upgrade_gift_post_request_parseFromJSON(json_upgrade_gift_post_request_1);
	cJSON* json_upgrade_gift_post_request_2 = _upgrade_gift_post_request_convertToJSON(_upgrade_gift_post_request_2);
	printf("repeating _upgrade_gift_post_request:\n%s\n", cJSON_Print(json_upgrade_gift_post_request_2));
}

int main() {
  test__upgrade_gift_post_request(1);
  test__upgrade_gift_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _upgrade_gift_post_request_MAIN
#endif // _upgrade_gift_post_request_TEST
