#ifndef reply_parameters_TEST
#define reply_parameters_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reply_parameters_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reply_parameters.h"
reply_parameters_t* instantiate_reply_parameters(int include_optional);

#include "test_reply_parameters_chat_id.c"


reply_parameters_t* instantiate_reply_parameters(int include_optional) {
  reply_parameters_t* reply_parameters = NULL;
  if (include_optional) {
    reply_parameters = reply_parameters_create(
      56,
      null,
      1,
      "0",
      "0",
      list_createList(),
      56
    );
  } else {
    reply_parameters = reply_parameters_create(
      56,
      null,
      1,
      "0",
      "0",
      list_createList(),
      56
    );
  }

  return reply_parameters;
}


#ifdef reply_parameters_MAIN

void test_reply_parameters(int include_optional) {
    reply_parameters_t* reply_parameters_1 = instantiate_reply_parameters(include_optional);

	cJSON* jsonreply_parameters_1 = reply_parameters_convertToJSON(reply_parameters_1);
	printf("reply_parameters :\n%s\n", cJSON_Print(jsonreply_parameters_1));
	reply_parameters_t* reply_parameters_2 = reply_parameters_parseFromJSON(jsonreply_parameters_1);
	cJSON* jsonreply_parameters_2 = reply_parameters_convertToJSON(reply_parameters_2);
	printf("repeating reply_parameters:\n%s\n", cJSON_Print(jsonreply_parameters_2));
}

int main() {
  test_reply_parameters(1);
  test_reply_parameters(0);

  printf("Hello world \n");
  return 0;
}

#endif // reply_parameters_MAIN
#endif // reply_parameters_TEST
