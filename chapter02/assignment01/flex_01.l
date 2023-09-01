%option noyywrap
%x INFILE

%{

struct bufstack
{
    struct bufstack* prev;
    YY_BUFFER_STATE bs;
    int lineno;
    char *filename;
    FILE* fhandler;

} *currBufferPtr;

char* currentFileName;
int newFile(char *fn);
int popFile(void);

%}
%%

^"#include"[ \t]*\"[a-zA-Z\.]*\" {BEGIN INFILE;}

%%