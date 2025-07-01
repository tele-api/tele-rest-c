#ifndef switch_inline_query_chosen_chat_TEST
#define switch_inline_query_chosen_chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define switch_inline_query_chosen_chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/switch_inline_query_chosen_chat.h"
switch_inline_query_chosen_chat_t* instantiate_switch_inline_query_chosen_chat(int include_optional);



switch_inline_query_chosen_chat_t* instantiate_switch_inline_query_chosen_chat(int include_optional) {
  switch_inline_query_chosen_chat_t* switch_inline_query_chosen_chat = NULL;
  if (include_optional) {
    switch_inline_query_chosen_chat = switch_inline_query_chosen_chat_create(
      "0",
      1,
      1,
      1,
      1
    );
  } else {
    switch_inline_query_chosen_chat = switch_inline_query_chosen_chat_create(
      "0",
      1,
      1,
      1,
      1
    );
  }

  return switch_inline_query_chosen_chat;
}


#ifdef switch_inline_query_chosen_chat_MAIN

void test_switch_inline_query_chosen_chat(int include_optional) {
    switch_inline_query_chosen_chat_t* switch_inline_query_chosen_chat_1 = instantiate_switch_inline_query_chosen_chat(include_optional);

	cJSON* jsonswitch_inline_query_chosen_chat_1 = switch_inline_query_chosen_chat_convertToJSON(switch_inline_query_chosen_chat_1);
	printf("switch_inline_query_chosen_chat :\n%s\n", cJSON_Print(jsonswitch_inline_query_chosen_chat_1));
	switch_inline_query_chosen_chat_t* switch_inline_query_chosen_chat_2 = switch_inline_query_chosen_chat_parseFromJSON(jsonswitch_inline_query_chosen_chat_1);
	cJSON* jsonswitch_inline_query_chosen_chat_2 = switch_inline_query_chosen_chat_convertToJSON(switch_inline_query_chosen_chat_2);
	printf("repeating switch_inline_query_chosen_chat:\n%s\n", cJSON_Print(jsonswitch_inline_query_chosen_chat_2));
}

int main() {
  test_switch_inline_query_chosen_chat(1);
  test_switch_inline_query_chosen_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // switch_inline_query_chosen_chat_MAIN
#endif // switch_inline_query_chosen_chat_TEST
