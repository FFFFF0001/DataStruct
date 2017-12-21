/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.21 / 18��23
+
-             �޸�ʱ�䣺2017.12.21 / 18��23
+
-             �ļ����ƣ�dtastc.h
+
-             ���ܣ����ݽṹ���ͷ�ļ��������ꡢ�ṹ�塢�Ķ��壬����ǰ������
+
*/

#ifndef __DTASTC_H__
#define __DTASTC_H__

#include <assert.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STACKINITSIZE  50
// ջ��ʼ��ʱ����ʼ����

#define STACKINCREMENT 10
// ջ��������

/*
+
-              ״̬�붨��
+
*/
#define TRUE           1      
#define FALSE          0
#define OK             0
#define ERROR         -1
#define OVERFLOW      -2

typedef unsigned int UINT;
typedef int Status;

typedef struct {

	void ** base;          // ջ��ָ��
	void ** top;           // ջ��ָ��
	UINT stacksize;        // ջ����
	UINT cnt;              // ��ǰջԪ�ظ���

}STACK, * PSTACK;

/*
+
-              ����ǰ������
+
*/

PSTACK
InitStack();

Status
DestroyStack(PSTACK);

Status
ClearStack(PSTACK);

Status
StackEmpty(const PSTACK);

int
StackLength(const PSTACK);

void *
GetTop(const PSTACK);

Status
Push(PSTACK, void *);

void *
Pop(PSTACK);

static Status
AddStackSize(PSTACK);

#ifdef __cplusplus
}
#endif

#endif
