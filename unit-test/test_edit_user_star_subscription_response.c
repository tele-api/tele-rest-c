#ifndef edit_user_star_subscription_response_TEST
#define edit_user_star_subscription_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_user_star_subscription_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_user_star_subscription_response.h"
edit_user_star_subscription_response_t* instantiate_edit_user_star_subscription_response(int include_optional);



edit_user_star_subscription_response_t* instantiate_edit_user_star_subscription_response(int include_optional) {
  edit_user_star_subscription_response_t* edit_user_star_subscription_response = NULL;
  if (include_optional) {
    edit_user_star_subscription_response = edit_user_star_subscription_response_create(
      1,
      1
    );
  } else {
    edit_user_star_subscription_response = edit_user_star_subscription_response_create(
      1,
      1
    );
  }

  return edit_user_star_subscription_response;
}


#ifdef edit_user_star_subscription_response_MAIN

void test_edit_user_star_subscription_response(int include_optional) {
    edit_user_star_subscription_response_t* edit_user_star_subscription_response_1 = instantiate_edit_user_star_subscription_response(include_optional);

	cJSON* jsonedit_user_star_subscription_response_1 = edit_user_star_subscription_response_convertToJSON(edit_user_star_subscription_response_1);
	printf("edit_user_star_subscription_response :\n%s\n", cJSON_Print(jsonedit_user_star_subscription_response_1));
	edit_user_star_subscription_response_t* edit_user_star_subscription_response_2 = edit_user_star_subscription_response_parseFromJSON(jsonedit_user_star_subscription_response_1);
	cJSON* jsonedit_user_star_subscription_response_2 = edit_user_star_subscription_response_convertToJSON(edit_user_star_subscription_response_2);
	printf("repeating edit_user_star_subscription_response:\n%s\n", cJSON_Print(jsonedit_user_star_subscription_response_2));
}

int main() {
  test_edit_user_star_subscription_response(1);
  test_edit_user_star_subscription_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_user_star_subscription_response_MAIN
#endif // edit_user_star_subscription_response_TEST
