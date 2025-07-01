#ifndef reply_parameters_chat_id_TEST
#define reply_parameters_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reply_parameters_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reply_parameters_chat_id.h"
reply_parameters_chat_id_t* instantiate_reply_parameters_chat_id(int include_optional);



reply_parameters_chat_id_t* instantiate_reply_parameters_chat_id(int include_optional) {
  reply_parameters_chat_id_t* reply_parameters_chat_id = NULL;
  if (include_optional) {
    reply_parameters_chat_id = reply_parameters_chat_id_create(
    );
  } else {
    reply_parameters_chat_id = reply_parameters_chat_id_create(
    );
  }

  return reply_parameters_chat_id;
}


#ifdef reply_parameters_chat_id_MAIN

void test_reply_parameters_chat_id(int include_optional) {
    reply_parameters_chat_id_t* reply_parameters_chat_id_1 = instantiate_reply_parameters_chat_id(include_optional);

	cJSON* jsonreply_parameters_chat_id_1 = reply_parameters_chat_id_convertToJSON(reply_parameters_chat_id_1);
	printf("reply_parameters_chat_id :\n%s\n", cJSON_Print(jsonreply_parameters_chat_id_1));
	reply_parameters_chat_id_t* reply_parameters_chat_id_2 = reply_parameters_chat_id_parseFromJSON(jsonreply_parameters_chat_id_1);
	cJSON* jsonreply_parameters_chat_id_2 = reply_parameters_chat_id_convertToJSON(reply_parameters_chat_id_2);
	printf("repeating reply_parameters_chat_id:\n%s\n", cJSON_Print(jsonreply_parameters_chat_id_2));
}

int main() {
  test_reply_parameters_chat_id(1);
  test_reply_parameters_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // reply_parameters_chat_id_MAIN
#endif // reply_parameters_chat_id_TEST
