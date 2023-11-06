#ifndef STAPLE_TOKEN_H
#define STAPLE_TOKEN_H

struct _Token {
    int data;
    int type;
    int line;

};

typedef struct _Token Token;

#endif // STAPLE_TOKEN_H