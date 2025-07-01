#ifndef encrypted_credentials_TEST
#define encrypted_credentials_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define encrypted_credentials_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/encrypted_credentials.h"
encrypted_credentials_t* instantiate_encrypted_credentials(int include_optional);



encrypted_credentials_t* instantiate_encrypted_credentials(int include_optional) {
  encrypted_credentials_t* encrypted_credentials = NULL;
  if (include_optional) {
    encrypted_credentials = encrypted_credentials_create(
      "0",
      "0",
      "0"
    );
  } else {
    encrypted_credentials = encrypted_credentials_create(
      "0",
      "0",
      "0"
    );
  }

  return encrypted_credentials;
}


#ifdef encrypted_credentials_MAIN

void test_encrypted_credentials(int include_optional) {
    encrypted_credentials_t* encrypted_credentials_1 = instantiate_encrypted_credentials(include_optional);

	cJSON* jsonencrypted_credentials_1 = encrypted_credentials_convertToJSON(encrypted_credentials_1);
	printf("encrypted_credentials :\n%s\n", cJSON_Print(jsonencrypted_credentials_1));
	encrypted_credentials_t* encrypted_credentials_2 = encrypted_credentials_parseFromJSON(jsonencrypted_credentials_1);
	cJSON* jsonencrypted_credentials_2 = encrypted_credentials_convertToJSON(encrypted_credentials_2);
	printf("repeating encrypted_credentials:\n%s\n", cJSON_Print(jsonencrypted_credentials_2));
}

int main() {
  test_encrypted_credentials(1);
  test_encrypted_credentials(0);

  printf("Hello world \n");
  return 0;
}

#endif // encrypted_credentials_MAIN
#endif // encrypted_credentials_TEST
