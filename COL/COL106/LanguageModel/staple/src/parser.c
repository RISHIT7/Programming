#include "../include/parser.h"

ParserStatus parser_start(TokenList *list, const char *source)
{
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;

    while (1)
    {
        // memset(lex, 0, 256);

        while (source[i] != '\0' && source[i] != ' ' && source[i] != '\n')
        {
            lex[lexi] = source[i];
            lexi++;
            i++;
        }
        lex[lexi] = '\0';

        if (lex[0] == '\0')
        {
            break;
        }

        // This is a numerical constant
        if (lex[0] == '#')
        {
            int num = parser_get_number(lex);
            printf("NUMBER: %d\n", num);
            token_list_add(list, token_create(num, NUMBER, line));
        }

        // Must be an expression
        else
        {
            TokenInst inst = parser_get_inst(lex);
            if (inst >= 0)
            {
                printf("INST: %s\n", lex);
                token_list_add(list, token_create(INST, inst, line));
            }
            else
            {
                printf("Syntax error: no such instruction '%s' \n", lex);
                return PARSER_SYNTAX_ERROR;
            }
        }

        // New line
        if (source[i] == '\n')
        {
            line++;
        }
        // EOF
        else if (source[i] == '\0')
        {
            break;
        }

        // Reset lex
        lexi = 0;
        i++;
    }

    return PARSER_SUCCESS;
}

uint32_t parser_get_number(const char *buf)
{
    long num = atoi(&buf[1]);
    return (num <= UINT32_MAX) ? num : 0;
}

TokenInst parser_get_inst(const char *buf)
{
    if (strcmp(buf, "push") == 0)
    {
        return PUSH;
    }
    else if (strcmp(buf, "add") == 0)
    {
        return ADD;
    }
    else if (strcmp(buf, "hlt") == 0)
    {
        return HLT;
    }
    return (TokenInst)-1;
}