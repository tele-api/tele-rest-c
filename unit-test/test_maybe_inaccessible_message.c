#ifndef maybe_inaccessible_message_TEST
#define maybe_inaccessible_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define maybe_inaccessible_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/maybe_inaccessible_message.h"
maybe_inaccessible_message_t* instantiate_maybe_inaccessible_message(int include_optional);

#include "test_chat.c"
#include "test_user.c"
#include "test_chat.c"
#include "test_user.c"
#include "test_message_origin.c"
#include "test_message.c"
#include "test_external_reply_info.c"
#include "test_text_quote.c"
#include "test_story.c"
#include "test_user.c"
#include "test_link_preview_options.c"
#include "test_animation.c"
#include "test_audio.c"
#include "test_document.c"
#include "test_paid_media_info.c"
#include "test_sticker.c"
#include "test_story.c"
#include "test_video.c"
#include "test_video_note.c"
#include "test_voice.c"
#include "test_contact.c"
#include "test_dice.c"
#include "test_game.c"
#include "test_poll.c"
#include "test_venue.c"
#include "test_location.c"
#include "test_user.c"
#include "test_message_auto_delete_timer_changed.c"
#include "test_maybe_inaccessible_message.c"
#include "test_invoice.c"
#include "test_successful_payment.c"
#include "test_refunded_payment.c"
#include "test_users_shared.c"
#include "test_chat_shared.c"
#include "test_gift_info.c"
#include "test_unique_gift_info.c"
#include "test_write_access_allowed.c"
#include "test_passport_data.c"
#include "test_proximity_alert_triggered.c"
#include "test_chat_boost_added.c"
#include "test_chat_background.c"
#include "test_forum_topic_created.c"
#include "test_forum_topic_edited.c"
#include "test_giveaway_created.c"
#include "test_giveaway.c"
#include "test_giveaway_winners.c"
#include "test_giveaway_completed.c"
#include "test_paid_message_price_changed.c"
#include "test_video_chat_scheduled.c"
#include "test_video_chat_ended.c"
#include "test_video_chat_participants_invited.c"
#include "test_web_app_data.c"
#include "test_inline_keyboard_markup.c"


maybe_inaccessible_message_t* instantiate_maybe_inaccessible_message(int include_optional) {
  maybe_inaccessible_message_t* maybe_inaccessible_message = NULL;
  if (include_optional) {
    maybe_inaccessible_message = maybe_inaccessible_message_create(
      56,
      56,
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      null,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_external_reply_info(0),
       // false, not to have infinite recursion
      instantiate_text_quote(0),
       // false, not to have infinite recursion
      instantiate_story(0),
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      1,
      1,
      "0",
      "0",
      56,
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_link_preview_options(0),
      "0",
       // false, not to have infinite recursion
      instantiate_animation(0),
       // false, not to have infinite recursion
      instantiate_audio(0),
       // false, not to have infinite recursion
      instantiate_document(0),
       // false, not to have infinite recursion
      instantiate_paid_media_info(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_sticker(0),
       // false, not to have infinite recursion
      instantiate_story(0),
       // false, not to have infinite recursion
      instantiate_video(0),
       // false, not to have infinite recursion
      instantiate_video_note(0),
       // false, not to have infinite recursion
      instantiate_voice(0),
      "0",
      list_createList(),
      1,
      1,
       // false, not to have infinite recursion
      instantiate_contact(0),
       // false, not to have infinite recursion
      instantiate_dice(0),
       // false, not to have infinite recursion
      instantiate_game(0),
       // false, not to have infinite recursion
      instantiate_poll(0),
       // false, not to have infinite recursion
      instantiate_venue(0),
       // false, not to have infinite recursion
      instantiate_location(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_message_auto_delete_timer_changed(0),
      56,
      56,
      null,
       // false, not to have infinite recursion
      instantiate_invoice(0),
       // false, not to have infinite recursion
      instantiate_successful_payment(0),
       // false, not to have infinite recursion
      instantiate_refunded_payment(0),
       // false, not to have infinite recursion
      instantiate_users_shared(0),
       // false, not to have infinite recursion
      instantiate_chat_shared(0),
       // false, not to have infinite recursion
      instantiate_gift_info(0),
       // false, not to have infinite recursion
      instantiate_unique_gift_info(0),
      "0",
       // false, not to have infinite recursion
      instantiate_write_access_allowed(0),
       // false, not to have infinite recursion
      instantiate_passport_data(0),
       // false, not to have infinite recursion
      instantiate_proximity_alert_triggered(0),
       // false, not to have infinite recursion
      instantiate_chat_boost_added(0),
       // false, not to have infinite recursion
      instantiate_chat_background(0),
       // false, not to have infinite recursion
      instantiate_forum_topic_created(0),
       // false, not to have infinite recursion
      instantiate_forum_topic_edited(0),
      null,
      null,
      null,
      null,
       // false, not to have infinite recursion
      instantiate_giveaway_created(0),
       // false, not to have infinite recursion
      instantiate_giveaway(0),
       // false, not to have infinite recursion
      instantiate_giveaway_winners(0),
       // false, not to have infinite recursion
      instantiate_giveaway_completed(0),
       // false, not to have infinite recursion
      instantiate_paid_message_price_changed(0),
       // false, not to have infinite recursion
      instantiate_video_chat_scheduled(0),
      null,
       // false, not to have infinite recursion
      instantiate_video_chat_ended(0),
       // false, not to have infinite recursion
      instantiate_video_chat_participants_invited(0),
       // false, not to have infinite recursion
      instantiate_web_app_data(0),
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    maybe_inaccessible_message = maybe_inaccessible_message_create(
      56,
      56,
      NULL,
      56,
      NULL,
      NULL,
      56,
      NULL,
      "0",
      null,
      1,
      1,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      56,
      1,
      1,
      "0",
      "0",
      56,
      "0",
      list_createList(),
      NULL,
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      list_createList(),
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      list_createList(),
      1,
      1,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      list_createList(),
      NULL,
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
      NULL,
      56,
      56,
      null,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      null,
      null,
      null,
      null,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      null,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return maybe_inaccessible_message;
}


#ifdef maybe_inaccessible_message_MAIN

void test_maybe_inaccessible_message(int include_optional) {
    maybe_inaccessible_message_t* maybe_inaccessible_message_1 = instantiate_maybe_inaccessible_message(include_optional);

	cJSON* jsonmaybe_inaccessible_message_1 = maybe_inaccessible_message_convertToJSON(maybe_inaccessible_message_1);
	printf("maybe_inaccessible_message :\n%s\n", cJSON_Print(jsonmaybe_inaccessible_message_1));
	maybe_inaccessible_message_t* maybe_inaccessible_message_2 = maybe_inaccessible_message_parseFromJSON(jsonmaybe_inaccessible_message_1);
	cJSON* jsonmaybe_inaccessible_message_2 = maybe_inaccessible_message_convertToJSON(maybe_inaccessible_message_2);
	printf("repeating maybe_inaccessible_message:\n%s\n", cJSON_Print(jsonmaybe_inaccessible_message_2));
}

int main() {
  test_maybe_inaccessible_message(1);
  test_maybe_inaccessible_message(0);

  printf("Hello world \n");
  return 0;
}

#endif // maybe_inaccessible_message_MAIN
#endif // maybe_inaccessible_message_TEST
