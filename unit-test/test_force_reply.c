#ifndef force_reply_TEST
#define force_reply_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define force_reply_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/force_reply.h"
force_reply_t* instantiate_force_reply(int include_optional);



force_reply_t* instantiate_force_reply(int include_optional) {
  force_reply_t* force_reply = NULL;
  if (include_optional) {
    force_reply = force_reply_create(
      1,
      "0",
      1
    );
  } else {
    force_reply = force_reply_create(
      1,
      "0",
      1
    );
  }

  return force_reply;
}


#ifdef force_reply_MAIN

void test_force_reply(int include_optional) {
    force_reply_t* force_reply_1 = instantiate_force_reply(include_optional);

	cJSON* jsonforce_reply_1 = force_reply_convertToJSON(force_reply_1);
	printf("force_reply :\n%s\n", cJSON_Print(jsonforce_reply_1));
	force_reply_t* force_reply_2 = force_reply_parseFromJSON(jsonforce_reply_1);
	cJSON* jsonforce_reply_2 = force_reply_convertToJSON(force_reply_2);
	printf("repeating force_reply:\n%s\n", cJSON_Print(jsonforce_reply_2));
}

int main() {
  test_force_reply(1);
  test_force_reply(0);

  printf("Hello world \n");
  return 0;
}

#endif // force_reply_MAIN
#endif // force_reply_TEST
