/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.21 / 18��23
+
-             �޸�ʱ�䣺2017.12.21 / 22��38
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


/*
---------------------------------- LinkList ----------------------------------
*/

/*
+
-              �ṹ�嶨��
+
*/
typedef struct {

	void * _data;
	struct NODE * _next;
	struct NODE * _pre;

}NODE, * PNODE;

typedef struct {

	PNODE _head;    // ͷָ��
	PNODE _tail;    // βָ��
	UINT  _cnt;     // Ԫ�ظ���

}LINKLIST, * PLINKLIST;

/*
+
-              ����ǰ������
+
*/
static PNODE
NewNode(void *);
// ����һ���µĽڵ㣬��������Ϊ����Ĳ�����ֵ


Status
FreeNode(PNODE);
// �ͷŴ˽ڵ���ڴ�ռ�


PLINKLIST
Initlklist();
// ��ʼ��һ������ͷ���Ŀ�����


Status
FreelkList(PLINKLIST);
// ���������ͷ��ڴ�ռ�


Status
ClearlkList(PLINKLIST);
// �������Ϊ������


Status
EmptylkList(const PLINKLIST);
// �ж�һ�������Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE


Status
AddNode(PLINKLIST, void *);
// Ϊ�����½�һ���ڵ㣬��������Ϊ����ĵڶ���������ֵ��Ĭ�ϲ���˳���β�����룩


Status
RemoveNode(PLINKLIST);
// ����ɾ��һ����㡣(Ĭ�ϴ�β��ɾ��)


int
lkListLength(const PLINKLIST);
// ��������ĳ���(Ԫ�ظ���)


PNODE
GetNode(const PLINKLIST, void *);
// �������в���������Ϊ�ڶ�������ֵ�Ľڵ㣬���������ַ,��û�ҵ�������NULL


Status
InsertNodeAfter(PNODE, void *);
// �ڵ�һ�����������������Ϊ�ڶ����������½ڵ�


Status
InsertNodeBefore(PNODE, void *);
// �ڵ�һ�������ǰ����������Ϊ�ڶ����������½ڵ�
/*
------------------------------------------------------------------------------
*/





/*
---------------------------------- Stack ----------------------------------
*/

/*
+
-              �ṹ�嶨��
+
*/
typedef struct {

	void ** _base;          // ջ��ָ��
	void ** _top;           // ջ��ָ��
	UINT _stacksize;        // ջ����
	UINT _cnt;              // ��ǰջԪ�ظ���

}STACK, * PSTACK;

/*
+
-              ����ǰ������
+
*/
PSTACK
InitStack();
// ����һ����ջ


Status
DestroyStack(PSTACK);
// ����ջ���ͷ���Դ


Status
ClearStack(PSTACK);
// ��ջԪ����գ���Ϊ��ջ

Status
StackEmpty(const PSTACK);
// ��ջΪ��ջ������TRUE�����򷵻�FALSE


int
StackLength(const PSTACK);
// ����ջԪ�صĸ�������ջ�ĳ���


void *
GetTop(const PSTACK);
// ��ջ���գ�����ջ��Ԫ�ص�ֵ�����򷵻�NULL


Status
Push(PSTACK, void *);
// ����Ԫ��eΪ�µ�ջ��Ԫ��


void *
Pop(PSTACK);
// ��ջ���գ���ɾ��ջ��Ԫ�أ���������ֵ


static Status
AddStackSize(PSTACK);
// ����ջ������

/*
---------------------------------------------------------------------------
*/

#ifdef __cplusplus
}
#endif

#endif
