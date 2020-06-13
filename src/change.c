#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>    
#include <windows.h>    
#include <locale.h>    
#define BUFF_SIZE 1024    

wchar_t * ANSIToUnicode(const char* str)  
{  
    int textlen;  
    wchar_t * result;  
    textlen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);  
    result = (wchar_t *)malloc((textlen + 1)*sizeof(wchar_t));  
    memset(result, 0, (textlen + 1)*sizeof(wchar_t));  
    MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)result, textlen);  
    return result;  
}  

char * UnicodeToANSI(const wchar_t* str)  
{  
    char* result;  
    int textlen;  
    textlen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);  
    result = (char *)malloc((textlen + 1)*sizeof(char));  
    memset(result, 0, sizeof(char) * (textlen + 1));  
    WideCharToMultiByte(CP_ACP, 0, str, -1, result, textlen, NULL, NULL);  
    return result;  
}  

wchar_t * UTF8ToUnicode(const char* str)  
{  
    int textlen;  
    wchar_t * result;  
    textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);  
    result = (wchar_t *)malloc((textlen + 1)*sizeof(wchar_t));  
    memset(result, 0, (textlen + 1)*sizeof(wchar_t));  
    MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);  
    return result;  
}  

char * UnicodeToUTF8(const wchar_t* str)  
{  
    char* result;  
    int textlen;  
    textlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);  
    result = (char *)malloc((textlen + 1)*sizeof(char));  
    memset(result, 0, sizeof(char) * (textlen + 1));  
    WideCharToMultiByte(CP_UTF8, 0, str, -1, result, textlen, NULL, NULL);  
    return result;  
}  
/*宽字符转换为多字符Unicode - ANSI*/  
char* w2m(const wchar_t* wcs)  
{  
    int len;  
    char* buf;  
    len = wcstombs(NULL, wcs, 0);  
    if (len == 0)  
        return NULL;  
    buf = (char *)malloc(sizeof(char)*(len + 1));  
    memset(buf, 0, sizeof(char) *(len + 1));  
    len = wcstombs(buf, wcs, len + 1);  
    return buf;  
}  
/*多字符转换为宽字符ANSI - Unicode*/  
wchar_t* m2w(const char* mbs)  
{  
    int len;  
    wchar_t* buf;  
    len = mbstowcs(NULL, mbs, 0);  
    if (len == 0)  
        return NULL;  
    buf = (wchar_t *)malloc(sizeof(wchar_t)*(len + 1));  
    memset(buf, 0, sizeof(wchar_t) *(len + 1));  
    len = mbstowcs(buf, mbs, len + 1);  
    return buf;  
}  

char* ANSIToUTF8(const char* str)  
{  
    wchar_t * buf = ANSIToUnicode(str);  
    char * ret =  UnicodeToUTF8(buf);  
    free(buf);  
    return ret;  
}  

char* UTF8ToANSI(const char* str)  
{  
    wchar_t * buf = UTF8ToUnicode(str);  
    char * ret = UnicodeToANSI(buf);  
    free(buf);  
    return ret;  
}  

int main()  
{  
    ///*使用wcstombs和mbstowcs之前必须调用setlocale，以便决定内码*/  
    //setlocale(LC_ALL, ".936");  
    ///*假定有一个Unicode(UTF-16LE)编码的文件，将其打开，重新编码为ANSI，写入aa.txt中，再继续编码回Unicode，写入aw.txt中*/  
    ///*如果不存在a.txt文件，则程序出错，没有做错误处理*/  
    //char* filename = "a.txt";  
    //char* filenamea = "aa.txt";  
    //char* filenamew = "aw.txt";  
    //FILE*     input = fopen(filename, "rb");  
    //FILE*     inputa = fopen(filenamea, "wb");  
    //FILE*     inputw = fopen(filenamew, "wb");  
    //wchar_t * buf;  
    ///*BOE设置，UTF-16LE的BOE为FEFF，如果不先将其读取出来，wcstombs会调用失败*/  
    //fgetwc(input);  
    //fputwc(0xFEFF, inputw);  
    ///*开始读取文件*/  
    //while (!feof(input))  
    //{  
    //  buf = (wchar_t *)malloc(sizeof(wchar_t)*BUFF_SIZE);  
    //  memset(buf, 0, sizeof(wchar_t) * BUFF_SIZE);  
    //  fgetws(buf, BUFF_SIZE, input);  
    //  fputs(w2m(buf), inputa);  
    //  fputws(m2w(w2m(buf)), inputw);  
    //}  
    ///*后续处理*/  
    //fclose(input);  
    //fclose(inputa);  
    //fclose(inputw);  
    //free(buf);  
    char str[] = "多选控件";  
    char * buf = ANSIToUTF8(str);  
    BYTE pbuf[255];  
    memcpy(pbuf, buf, strlen(buf) + 1);  
    int i = 0;  
    char outbuff[BUFF_SIZE];  
    FILE*     outfile = fopen("out.txt", "wb");  
    while (pbuf[i])  
    {  
        sprintf(outbuff, "0x%02x, ", pbuf[i++]);  
        fputs(outbuff, outfile);  
    }  
    sprintf(outbuff, "0x00}");  
    fputs(outbuff, outfile);  
    fclose(outfile);  

    free(buf);  
    return 0;  
}  