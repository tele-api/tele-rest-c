#ifndef message_id_TEST
#define message_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_id.h"
message_id_t* instantiate_message_id(int include_optional);



message_id_t* instantiate_message_id(int include_optional) {
  message_id_t* message_id = NULL;
  if (include_optional) {
    message_id = message_id_create(
      56
    );
  } else {
    message_id = message_id_create(
      56
    );
  }

  return message_id;
}


#ifdef message_id_MAIN

void test_message_id(int include_optional) {
    message_id_t* message_id_1 = instantiate_message_id(include_optional);

	cJSON* jsonmessage_id_1 = message_id_convertToJSON(message_id_1);
	printf("message_id :\n%s\n", cJSON_Print(jsonmessage_id_1));
	message_id_t* message_id_2 = message_id_parseFromJSON(jsonmessage_id_1);
	cJSON* jsonmessage_id_2 = message_id_convertToJSON(message_id_2);
	printf("repeating message_id:\n%s\n", cJSON_Print(jsonmessage_id_2));
}

int main() {
  test_message_id(1);
  test_message_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_id_MAIN
#endif // message_id_TEST
