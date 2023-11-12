#ifndef STAPLE_TOKEN_H
#define STAPLE_TOKEN_H

#include <stdlib.h>

enum _Tokentype {
    INST,
    NUMBER
};

enum _TokenInst {
    PUSH,
    ADD,
    HLT
};

typedef enum _TokenInst TokenInst;

struct _Token
{
    int data;
    int type;
    int line;
};

typedef struct _Token Token;

Token* token_create(int data, int type, int line);
void destroy_token(Token* tok);

struct _TokenList
{
    Token **data;
    int ptr;
    int size;
};

typedef struct _TokenList TokenList;

void token_list_create(TokenList* list, int size);
// Don't heap allocate these
void token_list_add(TokenList* list, Token* tok);
Token* token_list_get(TokenList* list, int index);
void token_list_destroy(TokenList* list);

#endif // STAPLE_TOKEN_H