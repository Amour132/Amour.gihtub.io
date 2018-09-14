#include "CommentCovert.h"

void Do_NUL_State(FILE *pIn,FILE *pOut,enum State *ps)
{
	int frist = fgetc(pIn);//读取一个字符
	switch(frist)
	{
	case '/'://如果是/就有可能进入注释状态
		{
			int second = fgetc(pIn);//再读取一个字符
			switch(second)
			{
			case '*'://是*进入C注释状态
				{
					fputc('/',pOut);
					fputc('/',pOut);//输出  //  
					*ps = C_State;//状态转换到C注释
				}
				break;
			case '/'://  是/就是C++的注释状态
				{
					fputc(frist,pOut);
					fputc(second,pOut);
					*ps = Cpp_State;//状态转换到C++状态
				}
				break;
			default://正常情况就输出
				{
					fputc(frist,pOut);
					fputc(second,pOut);
				}
				break;
			}
		}
		break;
	case EOF://遇到EOF则结束
		{
			*ps = End_State;
		}
		break;
	default://正常输出
		{
			fputc(frist,pOut);
		}
		break;
	}
}

void Do_Cpp_State(FILE *pIn,FILE *pOut,enum State *ps)//C++状态
{
	int frist = fgetc(pIn);
	switch(frist)
	{
	case '\n'://读一个字符如果是换行
		{
			*ps = NUL_State;//进入无注释状态
		}
		break;
	case EOF://有可能遇到EOF 结束
		{
			*ps = End_State;
		}
		break;
	default:
		{
			fputc(frist,pOut);
		}
		break;
	}
}


void Do_C_State(FILE *pIn,FILE *pOut,enum State *ps)//C注释状态
{
	int frist = fgetc(pIn);
	switch(frist)
	{
	case '*'://遇到 * 说明有可能会结束
		{
			int second = fgetc(pIn);//读取第二个字符
			switch(second)
			{
			case '/'://是  /  代表注释结束
				{
					int thrid = fgetc(pIn);//是否换行的判断及处理
				    if(thrid == '\n')
					{
						fputc(thrid,pOut);

					}
					else
					{
						fputc('\n',pOut);
						ungetc(thrid,pIn);
					}
					*ps = NUL_State;//注释完后转换到无注释状态
				}
				break;
			default://如果读到 * 下一个不是 /  那就必须把 * 放回去防止和结束的 * 混淆
				{
					fputc(frist,pOut);
					ungetc(second,pIn);	//把字符放回流	
				}
				break;
			}
		}
		break;
	case '\n'://注释内的换行情况  
		{
			fputc(frist,pOut);
			fputc('/',pOut);
			fputc('/',pOut);
		}
		break;
	default:
		{
			fputc(frist,pOut);
		}
		break;
	}
}


void CommentCovert(FILE *pIn,FILE *pOut)
{
	enum State state = NUL_State;
	while(state != End_State)
	{
		switch(state)
		{
		case NUL_State:
			Do_NUL_State(pIn,pOut,&state);
			break;
		case C_State:
			Do_C_State(pIn,pOut,&state);
			break;
		case Cpp_State:
			Do_Cpp_State(pIn,pOut,&state);
			break;
		default:
			break;
		}
	}
}