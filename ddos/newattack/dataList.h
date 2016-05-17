#ifndef _DATALIST_H_
#define _DATALIST_H_
#include <libxml/parser.h>

/********************************************************************************/
struct dataList_st 
{
	int num;
	char * data;
	struct dataList_st * next;
};
typedef struct dataList_st dataList;
/********************************************************************************/
/* 将数据序列字符串格式化为链表                                                 */
/* 输入参数:数据字符串                                                          */
/* 输出:链表头指针                                                              */
/********************************************************************************/
dataList * get_ls(char *datalsTemp);
/********************************************************************************/
/* 得到数据链表长度                                                             */
/* 输入参数:数据链表头指针                                                      */
/* 输出:链表长度                                                                */
/********************************************************************************/
int getLinkLength(dataList * head);
/********************************************************************************/
/* 输出数据链表                                                                 */
/* 输入参数:数据链表头指针                                                      */
/********************************************************************************/
void outputList(dataList * dataHead);
/********************************************************************************/
/* 得到数据链表中的某一项                                                       */
/* 输入参数:数据序列号                                                          */
/* 输出:数据字符串                                                              */
/********************************************************************************/
char * getSomeone(dataList * dataHead,int i);
/********************************************************************************/
/* 释放数据链表                                                                 */
/* 参数:数据链表头指针                                                          */
/********************************************************************************/
void destoryLink(dataList * head);
/********************************************************************************/
/********************************************************************************/
#define MAX_DATA_NUM 1000 //最多支持存储的数据个数
#define IP_ADDRESS_LEN 16//255.255.255.255\0
struct datalist_array
{
	char data[MAX_DATA_NUM][IP_ADDRESS_LEN];
	int now_len;//当前存储数据的个数
};
typedef struct datalist_array datalist_arr;

datalist_arr * get_ls_arr(char * datalsTemp);
char * getSomeone_arr(datalist_arr * dataHead,int i);
void outputList_arr(datalist_arr * dataHead);
int getLinkLength_arr(datalist_arr * head);
/********************************************************************************/
/********************************************************************************/
/* 得到1-n这一范围内某一随机数                                                  */
/* 输入参数:范围上限n                                                           */
/* 输出:得到的随机数                                                            */
/********************************************************************************/
int getRandomNumber(int num);

/*
 * req domain's ip
 * return:
 *      ~NULL  success
 *       NULL  fail
 */
datalist_arr *req_domain_ip(char *domain);

/*
 * req domain's ip
 * return:
 *        0  ip no change
 *        1  ip change
 *        -1 error
 */
int req_fir_domain_ip(char *ipbuf,char *domain,char *ipold);

#endif
