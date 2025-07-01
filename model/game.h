/*
 * game.h
 *
 * This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
 */

#ifndef _game_H_
#define _game_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct game_t game_t;

#include "animation.h"
#include "message_entity.h"
#include "photo_size.h"



typedef struct game_t {
    char *title; // string
    char *description; // string
    list_t *photo; //nonprimitive container
    char *text; // string
    list_t *text_entities; //nonprimitive container
    struct animation_t *animation; //model

    int _library_owned; // Is the library responsible for freeing this object?
} game_t;

__attribute__((deprecated)) game_t *game_create(
    char *title,
    char *description,
    list_t *photo,
    char *text,
    list_t *text_entities,
    animation_t *animation
);

void game_free(game_t *game);

game_t *game_parseFromJSON(cJSON *gameJSON);

cJSON *game_convertToJSON(game_t *game);

#endif /* _game_H_ */

