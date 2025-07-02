#ifndef bot_command_scope_chat_member_TEST
#define bot_command_scope_chat_member_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_chat_member_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_chat_member.h"
bot_command_scope_chat_member_t* instantiate_bot_command_scope_chat_member(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


bot_command_scope_chat_member_t* instantiate_bot_command_scope_chat_member(int include_optional) {
  bot_command_scope_chat_member_t* bot_command_scope_chat_member = NULL;
  if (include_optional) {
    bot_command_scope_chat_member = bot_command_scope_chat_member_create(
      "chat_member",
      null,
      56
    );
  } else {
    bot_command_scope_chat_member = bot_command_scope_chat_member_create(
      "chat_member",
      null,
      56
    );
  }

  return bot_command_scope_chat_member;
}


#ifdef bot_command_scope_chat_member_MAIN

void test_bot_command_scope_chat_member(int include_optional) {
    bot_command_scope_chat_member_t* bot_command_scope_chat_member_1 = instantiate_bot_command_scope_chat_member(include_optional);

	cJSON* jsonbot_command_scope_chat_member_1 = bot_command_scope_chat_member_convertToJSON(bot_command_scope_chat_member_1);
	printf("bot_command_scope_chat_member :\n%s\n", cJSON_Print(jsonbot_command_scope_chat_member_1));
	bot_command_scope_chat_member_t* bot_command_scope_chat_member_2 = bot_command_scope_chat_member_parseFromJSON(jsonbot_command_scope_chat_member_1);
	cJSON* jsonbot_command_scope_chat_member_2 = bot_command_scope_chat_member_convertToJSON(bot_command_scope_chat_member_2);
	printf("repeating bot_command_scope_chat_member:\n%s\n", cJSON_Print(jsonbot_command_scope_chat_member_2));
}

int main() {
  test_bot_command_scope_chat_member(1);
  test_bot_command_scope_chat_member(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_chat_member_MAIN
#endif // bot_command_scope_chat_member_TEST
