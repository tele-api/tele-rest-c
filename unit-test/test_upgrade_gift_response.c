#ifndef upgrade_gift_response_TEST
#define upgrade_gift_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upgrade_gift_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upgrade_gift_response.h"
upgrade_gift_response_t* instantiate_upgrade_gift_response(int include_optional);



upgrade_gift_response_t* instantiate_upgrade_gift_response(int include_optional) {
  upgrade_gift_response_t* upgrade_gift_response = NULL;
  if (include_optional) {
    upgrade_gift_response = upgrade_gift_response_create(
      1,
      1
    );
  } else {
    upgrade_gift_response = upgrade_gift_response_create(
      1,
      1
    );
  }

  return upgrade_gift_response;
}


#ifdef upgrade_gift_response_MAIN

void test_upgrade_gift_response(int include_optional) {
    upgrade_gift_response_t* upgrade_gift_response_1 = instantiate_upgrade_gift_response(include_optional);

	cJSON* jsonupgrade_gift_response_1 = upgrade_gift_response_convertToJSON(upgrade_gift_response_1);
	printf("upgrade_gift_response :\n%s\n", cJSON_Print(jsonupgrade_gift_response_1));
	upgrade_gift_response_t* upgrade_gift_response_2 = upgrade_gift_response_parseFromJSON(jsonupgrade_gift_response_1);
	cJSON* jsonupgrade_gift_response_2 = upgrade_gift_response_convertToJSON(upgrade_gift_response_2);
	printf("repeating upgrade_gift_response:\n%s\n", cJSON_Print(jsonupgrade_gift_response_2));
}

int main() {
  test_upgrade_gift_response(1);
  test_upgrade_gift_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // upgrade_gift_response_MAIN
#endif // upgrade_gift_response_TEST
