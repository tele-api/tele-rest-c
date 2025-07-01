#ifndef message_reaction_count_updated_TEST
#define message_reaction_count_updated_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_reaction_count_updated_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_reaction_count_updated.h"
message_reaction_count_updated_t* instantiate_message_reaction_count_updated(int include_optional);

#include "test_chat.c"


message_reaction_count_updated_t* instantiate_message_reaction_count_updated(int include_optional) {
  message_reaction_count_updated_t* message_reaction_count_updated = NULL;
  if (include_optional) {
    message_reaction_count_updated = message_reaction_count_updated_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      56,
      list_createList()
    );
  } else {
    message_reaction_count_updated = message_reaction_count_updated_create(
      NULL,
      56,
      56,
      list_createList()
    );
  }

  return message_reaction_count_updated;
}


#ifdef message_reaction_count_updated_MAIN

void test_message_reaction_count_updated(int include_optional) {
    message_reaction_count_updated_t* message_reaction_count_updated_1 = instantiate_message_reaction_count_updated(include_optional);

	cJSON* jsonmessage_reaction_count_updated_1 = message_reaction_count_updated_convertToJSON(message_reaction_count_updated_1);
	printf("message_reaction_count_updated :\n%s\n", cJSON_Print(jsonmessage_reaction_count_updated_1));
	message_reaction_count_updated_t* message_reaction_count_updated_2 = message_reaction_count_updated_parseFromJSON(jsonmessage_reaction_count_updated_1);
	cJSON* jsonmessage_reaction_count_updated_2 = message_reaction_count_updated_convertToJSON(message_reaction_count_updated_2);
	printf("repeating message_reaction_count_updated:\n%s\n", cJSON_Print(jsonmessage_reaction_count_updated_2));
}

int main() {
  test_message_reaction_count_updated(1);
  test_message_reaction_count_updated(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_reaction_count_updated_MAIN
#endif // message_reaction_count_updated_TEST
