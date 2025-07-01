#ifndef message_auto_delete_timer_changed_TEST
#define message_auto_delete_timer_changed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_auto_delete_timer_changed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_auto_delete_timer_changed.h"
message_auto_delete_timer_changed_t* instantiate_message_auto_delete_timer_changed(int include_optional);



message_auto_delete_timer_changed_t* instantiate_message_auto_delete_timer_changed(int include_optional) {
  message_auto_delete_timer_changed_t* message_auto_delete_timer_changed = NULL;
  if (include_optional) {
    message_auto_delete_timer_changed = message_auto_delete_timer_changed_create(
      56
    );
  } else {
    message_auto_delete_timer_changed = message_auto_delete_timer_changed_create(
      56
    );
  }

  return message_auto_delete_timer_changed;
}


#ifdef message_auto_delete_timer_changed_MAIN

void test_message_auto_delete_timer_changed(int include_optional) {
    message_auto_delete_timer_changed_t* message_auto_delete_timer_changed_1 = instantiate_message_auto_delete_timer_changed(include_optional);

	cJSON* jsonmessage_auto_delete_timer_changed_1 = message_auto_delete_timer_changed_convertToJSON(message_auto_delete_timer_changed_1);
	printf("message_auto_delete_timer_changed :\n%s\n", cJSON_Print(jsonmessage_auto_delete_timer_changed_1));
	message_auto_delete_timer_changed_t* message_auto_delete_timer_changed_2 = message_auto_delete_timer_changed_parseFromJSON(jsonmessage_auto_delete_timer_changed_1);
	cJSON* jsonmessage_auto_delete_timer_changed_2 = message_auto_delete_timer_changed_convertToJSON(message_auto_delete_timer_changed_2);
	printf("repeating message_auto_delete_timer_changed:\n%s\n", cJSON_Print(jsonmessage_auto_delete_timer_changed_2));
}

int main() {
  test_message_auto_delete_timer_changed(1);
  test_message_auto_delete_timer_changed(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_auto_delete_timer_changed_MAIN
#endif // message_auto_delete_timer_changed_TEST
