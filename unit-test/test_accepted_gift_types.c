#ifndef accepted_gift_types_TEST
#define accepted_gift_types_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accepted_gift_types_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accepted_gift_types.h"
accepted_gift_types_t* instantiate_accepted_gift_types(int include_optional);



accepted_gift_types_t* instantiate_accepted_gift_types(int include_optional) {
  accepted_gift_types_t* accepted_gift_types = NULL;
  if (include_optional) {
    accepted_gift_types = accepted_gift_types_create(
      1,
      1,
      1,
      1
    );
  } else {
    accepted_gift_types = accepted_gift_types_create(
      1,
      1,
      1,
      1
    );
  }

  return accepted_gift_types;
}


#ifdef accepted_gift_types_MAIN

void test_accepted_gift_types(int include_optional) {
    accepted_gift_types_t* accepted_gift_types_1 = instantiate_accepted_gift_types(include_optional);

	cJSON* jsonaccepted_gift_types_1 = accepted_gift_types_convertToJSON(accepted_gift_types_1);
	printf("accepted_gift_types :\n%s\n", cJSON_Print(jsonaccepted_gift_types_1));
	accepted_gift_types_t* accepted_gift_types_2 = accepted_gift_types_parseFromJSON(jsonaccepted_gift_types_1);
	cJSON* jsonaccepted_gift_types_2 = accepted_gift_types_convertToJSON(accepted_gift_types_2);
	printf("repeating accepted_gift_types:\n%s\n", cJSON_Print(jsonaccepted_gift_types_2));
}

int main() {
  test_accepted_gift_types(1);
  test_accepted_gift_types(0);

  printf("Hello world \n");
  return 0;
}

#endif // accepted_gift_types_MAIN
#endif // accepted_gift_types_TEST
