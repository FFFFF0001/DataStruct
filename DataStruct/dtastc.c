/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.21 / 18��23
+
-             �޸�ʱ�䣺2017.12.21 / 22��38
+
-             �ļ����ƣ�dtastc.c
+
-             ���ܣ����ݽṹ��ĺ�������
+
*/
#include "dtastc.h"

/*
---------------------------------- LinkList ----------------------------------
*/

/*
+
-               ��������
+
*/
static PNODE
NewNode(void * e) {

	PNODE newnode = (PNODE)malloc(sizeof(NODE));
	if (!newnode) {

		exit(OVERFLOW);

	}

	newnode->_data = e;
	newnode->_next = NULL;
	newnode->_pre = NULL;

	return newnode;

}
// ����һ���µĽڵ㣬��������Ϊ����Ĳ�����ֵ


Status
FreeNode(PNODE node) {

	assert(node != NULL);

	if (node->_pre != NULL) {

		PNODE tmp = node->_pre;
		tmp->_next = node->_next;

	}
	if (node->_next != NULL) {

		PNODE tmp = node->_next;
		tmp->_pre = node->_pre;

	}

	free(node);
	node = NULL;

	return OK;

}
// �ͷŴ˽ڵ���ڴ�ռ�


PLINKLIST
Initlklist() {

	PLINKLIST lklist = (PLINKLIST)malloc(sizeof(LINKLIST));
	if (!lklist) {

		exit(OVERFLOW);

	}

	lklist->_cnt = 0;
	lklist->_head = NULL;
	lklist->_tail = NULL;

	return lklist;

}
// ��ʼ��һ������ͷ���Ŀ�����


Status
FreelkList(PLINKLIST lklist) {

	assert(lklist != NULL);

	if (EmptylkList(lklist)) {

		free(lklist);
		lklist = NULL;
		
		return OK;

	}

	PNODE pre = NULL;
	PNODE cur = lklist->_head;

	while (cur != NULL) {

		pre = cur->_next;
		free(cur);
		cur = pre;

	}

	free(lklist);
	lklist = NULL;

	return OK;

}
// ���������ͷ��ڴ�ռ�


Status
ClearlkList(PLINKLIST lklist) {

	assert(lklist != NULL);

	if (EmptylkList(lklist)) {

		return ERROR;

	}

	PNODE pre = NULL;
	PNODE cur = lklist->_head;

	while (cur != NULL) {

		pre = cur->_next;
		free(cur);
		cur = pre;

	}

	lklist->_head = NULL;
	lklist->_tail = NULL;
	lklist->_cnt = 0;

	return OK;

}
// �������Ϊ������


Status
EmptylkList(const PLINKLIST lklist) {

	assert(lklist != NULL);

	if (lklist->_cnt == 0) {

		return TRUE;

	}

	return FALSE;

}
// �ж�һ�������Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE


Status
AddNode(PLINKLIST lklist, void * e) {

	assert(lklist != NULL);
	assert(e != NULL);

	PNODE newnode = NewNode(e);

	if (EmptylkList(lklist)) {

		lklist->_head = newnode;
		lklist->_tail = newnode;

	}
	else {

		PNODE tmp = NULL;
		tmp = lklist->_tail;
		lklist->_tail->_next = newnode;
		lklist->_tail = newnode;
		lklist->_tail->_pre = tmp;

	}

	lklist->_cnt++;

	return OK;

}
// Ϊ�����½�һ���ڵ㣬��������Ϊ����ĵڶ���������ֵ��Ĭ�ϲ���˳���β�����룩


Status
RemoveNode(PLINKLIST lklist) {

	assert(lklist != NULL);

	PNODE tmp = lklist->_tail;

	if (EmptylkList(lklist)) {

		return ERROR;

	}

	lklist->_tail = lklist->_tail->_pre;
	lklist->_tail->_next = NULL;
	lklist->_cnt--;

	free(tmp);
	tmp = NULL;

	return OK;

}
// ����ɾ��һ����㡣(Ĭ�ϴ�β��ɾ��)


int
lkListLength(const PLINKLIST lklist) {

	assert(lklist != NULL);

	return lklist->_cnt;

}
// ��������ĳ���(Ԫ�ظ���)


PNODE
GetNode(const PLINKLIST lklist, void * e) {

	assert(lklist != NULL);
	assert(e != NULL);

	if (EmptylkList(lklist)) {

		return NULL;

	}

	PNODE node = lklist->_head;

	for (; node != NULL; node = node->_next) {

		if (node->_data == e) {

			break;

		}

	}

	if (node == NULL) {

		return NULL;

	}

	return node;

}
// �������в���������Ϊ�ڶ�������ֵ�Ľڵ㣬���������ַ,��û�ҵ�������NULL


Status
InsertNodeAfter(PNODE node, void * e) {

	assert(node != NULL);
	assert(e != NULL);

	PNODE tmp = node->_next;
	PNODE newnode = NewNode(e);

	newnode->_next = tmp;
	newnode->_pre = node;

	node->_next = newnode;
	tmp->_pre = newnode;

	return OK;


}
// �ڵ�һ�����������������Ϊ�ڶ����������½ڵ�


Status
InsertNodeBefore(PNODE node, void * e) {

	assert(node != NULL);
	assert(e != NULL);

	PNODE tmp = node->_pre;
	PNODE newnode = NewNode(e);

	newnode->_pre = tmp;
	newnode->_next = node;

	tmp->_next = newnode;
	node->_pre = newnode;

	return OK;

}
// �ڵ�һ�������ǰ����������Ϊ�ڶ����������½ڵ�

/*
------------------------------------------------------------------------------
*/





/*
---------------------------------- Stack ----------------------------------
*/

/*
+
-               ��������
+
*/
PSTACK
InitStack() {

	PSTACK sqs = (PSTACK)malloc(sizeof(STACK));
	if (!sqs) {

		exit(OVERFLOW);

	}

	sqs->_base = (void **)malloc(STACKINITSIZE * sizeof(void*));
	if (!(sqs->_base)) {

		exit(OVERFLOW);

	}	
	
	sqs->_top = sqs->_base;
	sqs->_stacksize = STACKINITSIZE;
	sqs->_cnt = 0;

	return sqs;

}
// ����һ����ջ


Status
DestroyStack(PSTACK sqs) {

	assert(sqs != NULL);

	free(sqs->_base);
	sqs->_base = NULL;
	sqs->_top = NULL;

	free(sqs);
	sqs = NULL;

	return OK;

}
// ����ջ���ͷ���Դ


Status
ClearStack(PSTACK sqs) {

	assert(sqs != NULL);

	sqs->_top = sqs->_base;
	sqs->_cnt = 0;

	return OK;

}
// ��ջԪ����գ���Ϊ��ջ


Status
StackEmpty(const PSTACK sqs) {

	assert(sqs != NULL);

	if (sqs->_cnt == 0)
		return TRUE;

	return FALSE;

}
// ��ջΪ��ջ������TRUE�����򷵻�FALSE


int
StackLength(const PSTACK sqs) {

	assert(sqs != NULL);

	return sqs->_cnt;

}
// ����ջԪ�صĸ�������ջ�ĳ���


void *
GetTop(const PSTACK sqs) {

	assert(sqs != NULL);

	if (StackEmpty(sqs)) {

		return NULL;

	}

	return *(sqs->_top - 1);

}
// ��ջ���գ�����ջ��Ԫ�ص�ֵ�����򷵻�NULL


Status
Push(PSTACK sqs, void * e) {

	assert(sqs != NULL);

	assert(sqs != NULL);

	if (sqs->_cnt == sqs->_stacksize) {

		AddStackSize(sqs);

	}

	*(sqs->_top) = e;
	sqs->_cnt++;

	return OK;

}
// ����Ԫ��eΪ�µ�ջ��Ԫ��


void *
Pop(PSTACK sqs) {

	assert(sqs != NULL);

	if (StackEmpty(sqs)) {

		return NULL;

	}

	sqs->_top--;
	sqs->_cnt--;

	return *(sqs->_top + 1);

}
// ��ջ���գ���ɾ��ջ��Ԫ�أ���������ֵ


static Status
AddStackSize(PSTACK sqs) {

	assert(sqs != NULL);

	void **add = (void **)realloc(sqs->_base,
		(sqs->_stacksize + STACKINCREMENT) * sizeof(void*));

	if (!add) {

		exit(OVERFLOW);

	}

	sqs->_base = add;
	sqs->_stacksize += STACKINCREMENT;

	return OK;

}
// ����ջ������

/*
---------------------------------------------------------------------------
*/
