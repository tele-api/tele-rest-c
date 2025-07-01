#ifndef webhook_info_TEST
#define webhook_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define webhook_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/webhook_info.h"
webhook_info_t* instantiate_webhook_info(int include_optional);



webhook_info_t* instantiate_webhook_info(int include_optional) {
  webhook_info_t* webhook_info = NULL;
  if (include_optional) {
    webhook_info = webhook_info_create(
      "0",
      1,
      56,
      "0",
      56,
      "0",
      56,
      56,
      list_createList()
    );
  } else {
    webhook_info = webhook_info_create(
      "0",
      1,
      56,
      "0",
      56,
      "0",
      56,
      56,
      list_createList()
    );
  }

  return webhook_info;
}


#ifdef webhook_info_MAIN

void test_webhook_info(int include_optional) {
    webhook_info_t* webhook_info_1 = instantiate_webhook_info(include_optional);

	cJSON* jsonwebhook_info_1 = webhook_info_convertToJSON(webhook_info_1);
	printf("webhook_info :\n%s\n", cJSON_Print(jsonwebhook_info_1));
	webhook_info_t* webhook_info_2 = webhook_info_parseFromJSON(jsonwebhook_info_1);
	cJSON* jsonwebhook_info_2 = webhook_info_convertToJSON(webhook_info_2);
	printf("repeating webhook_info:\n%s\n", cJSON_Print(jsonwebhook_info_2));
}

int main() {
  test_webhook_info(1);
  test_webhook_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // webhook_info_MAIN
#endif // webhook_info_TEST
