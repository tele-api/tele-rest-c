#ifndef bot_command_scope_chat_administrators_TEST
#define bot_command_scope_chat_administrators_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_chat_administrators_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_chat_administrators.h"
bot_command_scope_chat_administrators_t* instantiate_bot_command_scope_chat_administrators(int include_optional);

#include "test__restrict_chat_member_post_request_chat_id.c"


bot_command_scope_chat_administrators_t* instantiate_bot_command_scope_chat_administrators(int include_optional) {
  bot_command_scope_chat_administrators_t* bot_command_scope_chat_administrators = NULL;
  if (include_optional) {
    bot_command_scope_chat_administrators = bot_command_scope_chat_administrators_create(
      "chat_administrators",
      null
    );
  } else {
    bot_command_scope_chat_administrators = bot_command_scope_chat_administrators_create(
      "chat_administrators",
      null
    );
  }

  return bot_command_scope_chat_administrators;
}


#ifdef bot_command_scope_chat_administrators_MAIN

void test_bot_command_scope_chat_administrators(int include_optional) {
    bot_command_scope_chat_administrators_t* bot_command_scope_chat_administrators_1 = instantiate_bot_command_scope_chat_administrators(include_optional);

	cJSON* jsonbot_command_scope_chat_administrators_1 = bot_command_scope_chat_administrators_convertToJSON(bot_command_scope_chat_administrators_1);
	printf("bot_command_scope_chat_administrators :\n%s\n", cJSON_Print(jsonbot_command_scope_chat_administrators_1));
	bot_command_scope_chat_administrators_t* bot_command_scope_chat_administrators_2 = bot_command_scope_chat_administrators_parseFromJSON(jsonbot_command_scope_chat_administrators_1);
	cJSON* jsonbot_command_scope_chat_administrators_2 = bot_command_scope_chat_administrators_convertToJSON(bot_command_scope_chat_administrators_2);
	printf("repeating bot_command_scope_chat_administrators:\n%s\n", cJSON_Print(jsonbot_command_scope_chat_administrators_2));
}

int main() {
  test_bot_command_scope_chat_administrators(1);
  test_bot_command_scope_chat_administrators(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_chat_administrators_MAIN
#endif // bot_command_scope_chat_administrators_TEST
