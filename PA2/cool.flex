/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */
int commentorder=0;
int mystrlen;
%}

/*
 * Define names for regular expressions here.
 */
%x block_comment str
DARROW          =>
ASSIGN		<-
LE		<=

%%

 /*
  *  Nested comments
  */
"--"	{ register int c;
	  while((c=yyinput())!='\n'&&c!=EOF){
	  ;
	  }
	  if(c=='\n') curr_lineno++;
	 }
"(\*"	 {BEGIN(block_comment);commentorder++;}
<block_comment>\n	{curr_lineno++;}
<block_comment>"\*)"	{commentorder--;
			if(commentorder==0) BEGIN(0);}
<block_comment>"(\*"	{commentorder++;}
<block_comment><<EOF>>	{yylval.error_msg="EOF in comment";yyrestart(yyin);
			BEGIN(0);return ERROR;}
"\*)"			{yylval.error_msg="Unmatched *)"; return ERROR;}
<block_comment>.	{}
 /*
  *  The multiple-character operators.
  */
{DARROW}		{ return (DARROW); }
{ASSIGN}		{return ASSIGN;}
{LE}			{return LE;}


 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */
[cC][lL][aA][sS][sS]	{return CLASS;}
[Ee][lL][Ss][eE]	{return ELSE;}
f[aA][lL][sS][eE]	{yylval.boolean=0;
			return BOOL_CONST;}
[fF][iI]		{return FI;}
[iI][fF]		{return IF;}
[iI][nN]	{return IN;}
[iI][nN][hH][eE][rR][iI][tT][sS]	{return INHERITS;}
(?i:isvoid)		{return ISVOID;}
[lL][eE][tT]				{return LET;}
[lL][oO][oO][pP]			{return LOOP;}
[pP][oO][oO][lL]			{return POOL;}
[tT][hH][eE][nN]			{return THEN;}
[wW][hH][iI][lL][eE]			{return WHILE;}
[Cc][aA][sS][eE]			{return CASE;}
[eE][sS][aA][cC]			{return ESAC;}
[nN][eE][wW]				{return NEW;}
[oO][fF]				{return OF;}
[nN][oO][tT]				{return NOT;}
t[rR][uU][eE]				{yylval.boolean=1;return BOOL_CONST;}
 /*
 * Integers and identifiers.
 */
[0-9]+			{yylval.symbol=inttable.add_string(yytext);
			 return INT_CONST;}
[A-Z][a-zA-Z0-9_]*	 {yylval.symbol=idtable.add_string(yytext);
			 return TYPEID;}
[a-z][a-zA-Z0-9_]*	 {yylval.symbol=idtable.add_string(yytext);
			 return OBJECTID;}					

 /*
 * punctuation
 */
[ \f\r\t\v]+	{}
\n		{curr_lineno=curr_lineno+1;}
\;		{return(';');}
\:		{return(':');}
\{		{return('{');}
\}		{return('}');}
\(		{return('(');}
\)		{return(')');}

 /*
 * \[		{return('[');}
 * \]		{return(']');}
 */
\,		{return(',');}
\+		{return('+');}
\-		{return('-');}
\*		{return('*');}
\/		{return('/');}
\<		{return('<');}
\=		{return('=');}
\.		{return('.');}
\~		{return('~');}
\@		{return('@');}

 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  * so difficult
  */
\"	{string_buf_ptr=string_buf;mystrlen=0; BEGIN(str);}
<str>{
\"	{
	BEGIN(0);*string_buf_ptr='\0';
	if(mystrlen>=MAX_STR_CONST){
	yylval.error_msg="String constant too long";
	return ERROR;}else{
	yylval.symbol=stringtable.add_string(string_buf);
	return STR_CONST;}}
\n	{BEGIN(0);yylval.error_msg="Unterminated string constant";
	 return ERROR;}
\\\0 {yylval.error_msg="String contains escaped null character";BEGIN 0; yyrestart(yyin); return ERROR;}
 /*
 * \\[0-7]{1,3}	{ int result;
 *	(void) sscanf(yytext+1,"%o",&result);
 *	if(result>0xff){
 *	yylval.error_msg="constant is out-of-bounds";
 *	return ERROR;}else{
 *	*string_buf_ptr=result;
 *	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}}
 * \\[0-9]+       {yylval.error_msg="bad eccaped sequence";
 *	       return ERROR;}
 */
\\n	       {*string_buf_ptr='\n';
	       mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}
\\t	{*string_buf_ptr='\t';
	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}
\\b	{*string_buf_ptr='\b';
	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}
\\f	{*string_buf_ptr='\f';
	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}
\\(.|\n)	{*string_buf_ptr=yytext[1];
	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;
	 curr_lineno++;}
[^\\\n\"]+     {
	       char *yptr=yytext;
	       while(*yptr!='\0'){
	       *string_buf_ptr=*yptr;
	       yptr++;
	mystrlen++;string_buf_ptr=string_buf+mystrlen%MAX_STR_CONST;}
	if(yptr-yytext<yyleng){
		yylval.error_msg="String contains null character";BEGIN 0;
		int c;while((c=yyinput())!='"'&&c!='\n'&&c!=EOF){}return ERROR;}}

<<EOF>> {yylval.error_msg="EOF in string constant"; BEGIN 0; yyrestart(yyin); return ERROR;}

}
.	{yylval.error_msg=yytext;return ERROR;}

%%
