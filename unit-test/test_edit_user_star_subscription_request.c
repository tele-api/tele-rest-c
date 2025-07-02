#ifndef edit_user_star_subscription_request_TEST
#define edit_user_star_subscription_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_user_star_subscription_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_user_star_subscription_request.h"
edit_user_star_subscription_request_t* instantiate_edit_user_star_subscription_request(int include_optional);



edit_user_star_subscription_request_t* instantiate_edit_user_star_subscription_request(int include_optional) {
  edit_user_star_subscription_request_t* edit_user_star_subscription_request = NULL;
  if (include_optional) {
    edit_user_star_subscription_request = edit_user_star_subscription_request_create(
      56,
      "0",
      1
    );
  } else {
    edit_user_star_subscription_request = edit_user_star_subscription_request_create(
      56,
      "0",
      1
    );
  }

  return edit_user_star_subscription_request;
}


#ifdef edit_user_star_subscription_request_MAIN

void test_edit_user_star_subscription_request(int include_optional) {
    edit_user_star_subscription_request_t* edit_user_star_subscription_request_1 = instantiate_edit_user_star_subscription_request(include_optional);

	cJSON* jsonedit_user_star_subscription_request_1 = edit_user_star_subscription_request_convertToJSON(edit_user_star_subscription_request_1);
	printf("edit_user_star_subscription_request :\n%s\n", cJSON_Print(jsonedit_user_star_subscription_request_1));
	edit_user_star_subscription_request_t* edit_user_star_subscription_request_2 = edit_user_star_subscription_request_parseFromJSON(jsonedit_user_star_subscription_request_1);
	cJSON* jsonedit_user_star_subscription_request_2 = edit_user_star_subscription_request_convertToJSON(edit_user_star_subscription_request_2);
	printf("repeating edit_user_star_subscription_request:\n%s\n", cJSON_Print(jsonedit_user_star_subscription_request_2));
}

int main() {
  test_edit_user_star_subscription_request(1);
  test_edit_user_star_subscription_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_user_star_subscription_request_MAIN
#endif // edit_user_star_subscription_request_TEST
