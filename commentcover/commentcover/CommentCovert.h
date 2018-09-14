#ifndef _CommentCovert__
#define _CommentCovert__

#include <stdio.h>
#include <stdlib.h>

enum State //¶¨Òå4ÖÖ×´Ì¬
{
	NUL_State,//ÎÞ×´Ì¬
	C_State,//C×¢ÊÍ×´Ì¬
	Cpp_State,//C++×¢ÊÍ×´Ì¬
	End_State//½áÊø×´Ì¬
};

void CommentCovert(FILE *pIn,FILE *pOut);//×¢ÊÍ×ª»»
void Do_NUL_State(FILE *pIn,FILE *pOut,enum State *ps); //ÎÞ×´Ì¬º¯Êý
void Do_C_State(FILE *pIn,FILE *pOut,enum State *ps); //C×¢ÊÍ
void Do_Cpp_State(FILE *pIn,FILE *pOut,enum State *ps);//C++×¢ÊÍ
//
#endif //_CommentCovert__