#ifndef upgrade_gift_request_TEST
#define upgrade_gift_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upgrade_gift_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upgrade_gift_request.h"
upgrade_gift_request_t* instantiate_upgrade_gift_request(int include_optional);



upgrade_gift_request_t* instantiate_upgrade_gift_request(int include_optional) {
  upgrade_gift_request_t* upgrade_gift_request = NULL;
  if (include_optional) {
    upgrade_gift_request = upgrade_gift_request_create(
      "0",
      "0",
      1,
      56
    );
  } else {
    upgrade_gift_request = upgrade_gift_request_create(
      "0",
      "0",
      1,
      56
    );
  }

  return upgrade_gift_request;
}


#ifdef upgrade_gift_request_MAIN

void test_upgrade_gift_request(int include_optional) {
    upgrade_gift_request_t* upgrade_gift_request_1 = instantiate_upgrade_gift_request(include_optional);

	cJSON* jsonupgrade_gift_request_1 = upgrade_gift_request_convertToJSON(upgrade_gift_request_1);
	printf("upgrade_gift_request :\n%s\n", cJSON_Print(jsonupgrade_gift_request_1));
	upgrade_gift_request_t* upgrade_gift_request_2 = upgrade_gift_request_parseFromJSON(jsonupgrade_gift_request_1);
	cJSON* jsonupgrade_gift_request_2 = upgrade_gift_request_convertToJSON(upgrade_gift_request_2);
	printf("repeating upgrade_gift_request:\n%s\n", cJSON_Print(jsonupgrade_gift_request_2));
}

int main() {
  test_upgrade_gift_request(1);
  test_upgrade_gift_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // upgrade_gift_request_MAIN
#endif // upgrade_gift_request_TEST
