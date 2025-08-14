#ifndef _TOKENIZATION_H_
#define _TOKENIZATION_H_

enum Tokens
{
    CLASS_DECLARATION,
    PUBLIC_VISIBILITY,
    OPEN_CURLY,
    CLOSE_CURLY,
    FUNCTION_DECLARATION,
    VOID_RETURN
};

void tokenize(char *buffer);

#endif
