#ifndef bot_command_scope_chat_TEST
#define bot_command_scope_chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_chat.h"
bot_command_scope_chat_t* instantiate_bot_command_scope_chat(int include_optional);

#include "test_post_restrict_chat_member_request_chat_id.c"


bot_command_scope_chat_t* instantiate_bot_command_scope_chat(int include_optional) {
  bot_command_scope_chat_t* bot_command_scope_chat = NULL;
  if (include_optional) {
    bot_command_scope_chat = bot_command_scope_chat_create(
      "chat",
      null
    );
  } else {
    bot_command_scope_chat = bot_command_scope_chat_create(
      "chat",
      null
    );
  }

  return bot_command_scope_chat;
}


#ifdef bot_command_scope_chat_MAIN

void test_bot_command_scope_chat(int include_optional) {
    bot_command_scope_chat_t* bot_command_scope_chat_1 = instantiate_bot_command_scope_chat(include_optional);

	cJSON* jsonbot_command_scope_chat_1 = bot_command_scope_chat_convertToJSON(bot_command_scope_chat_1);
	printf("bot_command_scope_chat :\n%s\n", cJSON_Print(jsonbot_command_scope_chat_1));
	bot_command_scope_chat_t* bot_command_scope_chat_2 = bot_command_scope_chat_parseFromJSON(jsonbot_command_scope_chat_1);
	cJSON* jsonbot_command_scope_chat_2 = bot_command_scope_chat_convertToJSON(bot_command_scope_chat_2);
	printf("repeating bot_command_scope_chat:\n%s\n", cJSON_Print(jsonbot_command_scope_chat_2));
}

int main() {
  test_bot_command_scope_chat(1);
  test_bot_command_scope_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_chat_MAIN
#endif // bot_command_scope_chat_TEST
