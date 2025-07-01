#ifndef external_reply_info_TEST
#define external_reply_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define external_reply_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/external_reply_info.h"
external_reply_info_t* instantiate_external_reply_info(int include_optional);

#include "test_message_origin.c"
#include "test_chat.c"
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
#include "test_giveaway.c"
#include "test_giveaway_winners.c"
#include "test_invoice.c"
#include "test_location.c"
#include "test_poll.c"
#include "test_venue.c"


external_reply_info_t* instantiate_external_reply_info(int include_optional) {
  external_reply_info_t* external_reply_info = NULL;
  if (include_optional) {
    external_reply_info = external_reply_info_create(
      null,
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
       // false, not to have infinite recursion
      instantiate_link_preview_options(0),
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
      1,
       // false, not to have infinite recursion
      instantiate_contact(0),
       // false, not to have infinite recursion
      instantiate_dice(0),
       // false, not to have infinite recursion
      instantiate_game(0),
       // false, not to have infinite recursion
      instantiate_giveaway(0),
       // false, not to have infinite recursion
      instantiate_giveaway_winners(0),
       // false, not to have infinite recursion
      instantiate_invoice(0),
       // false, not to have infinite recursion
      instantiate_location(0),
       // false, not to have infinite recursion
      instantiate_poll(0),
       // false, not to have infinite recursion
      instantiate_venue(0)
    );
  } else {
    external_reply_info = external_reply_info_create(
      null,
      NULL,
      56,
      NULL,
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
      1,
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

  return external_reply_info;
}


#ifdef external_reply_info_MAIN

void test_external_reply_info(int include_optional) {
    external_reply_info_t* external_reply_info_1 = instantiate_external_reply_info(include_optional);

	cJSON* jsonexternal_reply_info_1 = external_reply_info_convertToJSON(external_reply_info_1);
	printf("external_reply_info :\n%s\n", cJSON_Print(jsonexternal_reply_info_1));
	external_reply_info_t* external_reply_info_2 = external_reply_info_parseFromJSON(jsonexternal_reply_info_1);
	cJSON* jsonexternal_reply_info_2 = external_reply_info_convertToJSON(external_reply_info_2);
	printf("repeating external_reply_info:\n%s\n", cJSON_Print(jsonexternal_reply_info_2));
}

int main() {
  test_external_reply_info(1);
  test_external_reply_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // external_reply_info_MAIN
#endif // external_reply_info_TEST
