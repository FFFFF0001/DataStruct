#include "dtastc.h"

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

	sqs->base = (void **)malloc(STACKINITSIZE * sizeof(void*));
	if (!(sqs->base)) {

		exit(OVERFLOW);

	}	
	
	sqs->top = sqs->base;
	sqs->stacksize = STACKINITSIZE;
	sqs->cnt = 0;

	return sqs;

}
// ����һ����ջ


Status
DestroyStack(PSTACK sqs) {

	assert(sqs != NULL);

	free(sqs->base);
	sqs->base = NULL;
	sqs->top = NULL;

	free(sqs);
	sqs = NULL;

	return OK;

}
// ����ջ���ͷ���Դ


Status
ClearStack(PSTACK sqs) {

	assert(sqs != NULL);

	sqs->top = sqs->base;
	sqs->cnt = 0;

	return OK;

}
// ��ջԪ����գ���Ϊ��ջ


Status
StackEmpty(const PSTACK sqs) {

	assert(sqs != NULL);

	if (sqs->cnt == 0)
		return TRUE;

	return FALSE;

}
// ��ջΪ��ջ������TRUE�����򷵻�FALSE


int
StackLength(const PSTACK sqs) {

	assert(sqs != NULL);

	return sqs->cnt;

}
// ����ջԪ�صĸ�������ջ�ĳ���


void *
GetTop(const PSTACK sqs) {

	assert(sqs != NULL);

	if (StackEmpty(sqs)) {

		return NULL;

	}

	return *(sqs->top - 1);

}
// ��ջ���գ��÷���ջ��Ԫ�ص�ַ�����򷵻�ERROR


Status
Push(PSTACK sqs, void * e) {

	assert(sqs != NULL);

	assert(sqs != NULL);

	if (sqs->cnt == sqs->stacksize) {

		AddStackSize(sqs);

	}

	*(sqs->top) = e;
	sqs->cnt++;

	return OK;

}
// ����Ԫ��eΪ�µ�ջ��Ԫ��

void *
Pop(PSTACK sqs) {

	assert(sqs != NULL);

	if (StackEmpty(sqs)) {

		return NULL;

	}

	sqs->top--;
	sqs->cnt--;

	return *(sqs->top + 1);

}
// ��ջ���գ���ɾ��ջ��Ԫ�أ���������ֵ


static Status
AddStackSize(PSTACK sqs) {

	assert(sqs != NULL);

	void **add = (void **)realloc(sqs->base,
		(sqs->stacksize + STACKINCREMENT) * sizeof(void*));

	if (!add) {

		exit(OVERFLOW);

	}

	sqs->base = add;
	sqs->stacksize += STACKINCREMENT;

	return OK;

}
// ����ջ������
