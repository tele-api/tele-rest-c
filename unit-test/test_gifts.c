#ifndef gifts_TEST
#define gifts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gifts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gifts.h"
gifts_t* instantiate_gifts(int include_optional);



gifts_t* instantiate_gifts(int include_optional) {
  gifts_t* gifts = NULL;
  if (include_optional) {
    gifts = gifts_create(
      list_createList()
    );
  } else {
    gifts = gifts_create(
      list_createList()
    );
  }

  return gifts;
}


#ifdef gifts_MAIN

void test_gifts(int include_optional) {
    gifts_t* gifts_1 = instantiate_gifts(include_optional);

	cJSON* jsongifts_1 = gifts_convertToJSON(gifts_1);
	printf("gifts :\n%s\n", cJSON_Print(jsongifts_1));
	gifts_t* gifts_2 = gifts_parseFromJSON(jsongifts_1);
	cJSON* jsongifts_2 = gifts_convertToJSON(gifts_2);
	printf("repeating gifts:\n%s\n", cJSON_Print(jsongifts_2));
}

int main() {
  test_gifts(1);
  test_gifts(0);

  printf("Hello world \n");
  return 0;
}

#endif // gifts_MAIN
#endif // gifts_TEST
