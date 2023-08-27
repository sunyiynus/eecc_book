%option noyywrap
%{

int words = 0;

%}
%%
[a-zA-Z]+	{words++;}
%%

int main(int arg, char **argv)
{
	if (arg > 1) {
		if ((yyin = fopen(argv[1], "r"))) {
			yylex();
		} else {
			perror("ERROR ON OPEN FILE!");
		}
		printf("output words:%d\n", words);
	}

}
