#ifndef update_TEST
#define update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update.h"
update_t* instantiate_update(int include_optional);

#include "test_message.c"
#include "test_message.c"
#include "test_message.c"
#include "test_message.c"
#include "test_business_connection.c"
#include "test_message.c"
#include "test_message.c"
#include "test_business_messages_deleted.c"
#include "test_message_reaction_updated.c"
#include "test_message_reaction_count_updated.c"
#include "test_inline_query.c"
#include "test_chosen_inline_result.c"
#include "test_callback_query.c"
#include "test_shipping_query.c"
#include "test_pre_checkout_query.c"
#include "test_paid_media_purchased.c"
#include "test_poll.c"
#include "test_poll_answer.c"
#include "test_chat_member_updated.c"
#include "test_chat_member_updated.c"
#include "test_chat_join_request.c"
#include "test_chat_boost_updated.c"
#include "test_chat_boost_removed.c"


update_t* instantiate_update(int include_optional) {
  update_t* update = NULL;
  if (include_optional) {
    update = update_create(
      56,
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_business_connection(0),
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_business_messages_deleted(0),
       // false, not to have infinite recursion
      instantiate_message_reaction_updated(0),
       // false, not to have infinite recursion
      instantiate_message_reaction_count_updated(0),
       // false, not to have infinite recursion
      instantiate_inline_query(0),
       // false, not to have infinite recursion
      instantiate_chosen_inline_result(0),
       // false, not to have infinite recursion
      instantiate_callback_query(0),
       // false, not to have infinite recursion
      instantiate_shipping_query(0),
       // false, not to have infinite recursion
      instantiate_pre_checkout_query(0),
       // false, not to have infinite recursion
      instantiate_paid_media_purchased(0),
       // false, not to have infinite recursion
      instantiate_poll(0),
       // false, not to have infinite recursion
      instantiate_poll_answer(0),
       // false, not to have infinite recursion
      instantiate_chat_member_updated(0),
       // false, not to have infinite recursion
      instantiate_chat_member_updated(0),
       // false, not to have infinite recursion
      instantiate_chat_join_request(0),
       // false, not to have infinite recursion
      instantiate_chat_boost_updated(0),
       // false, not to have infinite recursion
      instantiate_chat_boost_removed(0)
    );
  } else {
    update = update_create(
      56,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return update;
}


#ifdef update_MAIN

void test_update(int include_optional) {
    update_t* update_1 = instantiate_update(include_optional);

	cJSON* jsonupdate_1 = update_convertToJSON(update_1);
	printf("update :\n%s\n", cJSON_Print(jsonupdate_1));
	update_t* update_2 = update_parseFromJSON(jsonupdate_1);
	cJSON* jsonupdate_2 = update_convertToJSON(update_2);
	printf("repeating update:\n%s\n", cJSON_Print(jsonupdate_2));
}

int main() {
  test_update(1);
  test_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_MAIN
#endif // update_TEST
