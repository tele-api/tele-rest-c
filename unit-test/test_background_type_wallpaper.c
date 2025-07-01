#ifndef background_type_wallpaper_TEST
#define background_type_wallpaper_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define background_type_wallpaper_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/background_type_wallpaper.h"
background_type_wallpaper_t* instantiate_background_type_wallpaper(int include_optional);

#include "test_document.c"


background_type_wallpaper_t* instantiate_background_type_wallpaper(int include_optional) {
  background_type_wallpaper_t* background_type_wallpaper = NULL;
  if (include_optional) {
    background_type_wallpaper = background_type_wallpaper_create(
      "wallpaper",
       // false, not to have infinite recursion
      instantiate_document(0),
      56,
      1,
      1
    );
  } else {
    background_type_wallpaper = background_type_wallpaper_create(
      "wallpaper",
      NULL,
      56,
      1,
      1
    );
  }

  return background_type_wallpaper;
}


#ifdef background_type_wallpaper_MAIN

void test_background_type_wallpaper(int include_optional) {
    background_type_wallpaper_t* background_type_wallpaper_1 = instantiate_background_type_wallpaper(include_optional);

	cJSON* jsonbackground_type_wallpaper_1 = background_type_wallpaper_convertToJSON(background_type_wallpaper_1);
	printf("background_type_wallpaper :\n%s\n", cJSON_Print(jsonbackground_type_wallpaper_1));
	background_type_wallpaper_t* background_type_wallpaper_2 = background_type_wallpaper_parseFromJSON(jsonbackground_type_wallpaper_1);
	cJSON* jsonbackground_type_wallpaper_2 = background_type_wallpaper_convertToJSON(background_type_wallpaper_2);
	printf("repeating background_type_wallpaper:\n%s\n", cJSON_Print(jsonbackground_type_wallpaper_2));
}

int main() {
  test_background_type_wallpaper(1);
  test_background_type_wallpaper(0);

  printf("Hello world \n");
  return 0;
}

#endif // background_type_wallpaper_MAIN
#endif // background_type_wallpaper_TEST
