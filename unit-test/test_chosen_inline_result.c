#ifndef chosen_inline_result_TEST
#define chosen_inline_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chosen_inline_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chosen_inline_result.h"
chosen_inline_result_t* instantiate_chosen_inline_result(int include_optional);

#include "test_user.c"
#include "test_location.c"


chosen_inline_result_t* instantiate_chosen_inline_result(int include_optional) {
  chosen_inline_result_t* chosen_inline_result = NULL;
  if (include_optional) {
    chosen_inline_result = chosen_inline_result_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
       // false, not to have infinite recursion
      instantiate_location(0),
      "0"
    );
  } else {
    chosen_inline_result = chosen_inline_result_create(
      "0",
      NULL,
      "0",
      NULL,
      "0"
    );
  }

  return chosen_inline_result;
}


#ifdef chosen_inline_result_MAIN

void test_chosen_inline_result(int include_optional) {
    chosen_inline_result_t* chosen_inline_result_1 = instantiate_chosen_inline_result(include_optional);

	cJSON* jsonchosen_inline_result_1 = chosen_inline_result_convertToJSON(chosen_inline_result_1);
	printf("chosen_inline_result :\n%s\n", cJSON_Print(jsonchosen_inline_result_1));
	chosen_inline_result_t* chosen_inline_result_2 = chosen_inline_result_parseFromJSON(jsonchosen_inline_result_1);
	cJSON* jsonchosen_inline_result_2 = chosen_inline_result_convertToJSON(chosen_inline_result_2);
	printf("repeating chosen_inline_result:\n%s\n", cJSON_Print(jsonchosen_inline_result_2));
}

int main() {
  test_chosen_inline_result(1);
  test_chosen_inline_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // chosen_inline_result_MAIN
#endif // chosen_inline_result_TEST
