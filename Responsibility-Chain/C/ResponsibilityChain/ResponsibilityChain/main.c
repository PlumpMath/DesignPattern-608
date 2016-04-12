/**
 * ���ļ���ְ����ģʽ�İ������� [C���԰�]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
;
/**
 * Request�ṹ���װ�˿ͻ��˵�������Ϣ
 */
typedef struct Request {
	char message[4096];
} Request;

/**
 * Handler�ṹ�嶨����ְ����ģʽ�е��ϲ�ӿ�
 * �ṹ���б�������һ�����ڵ�Ľṹ��ָ�룬�Լ����������е����ڵ�Ĺ��к����ӿ�
 */
typedef struct Handler {
	struct Handler *handler;
	void(*HandlerRequest)(const struct Handler *, const Request *);
} Handler;

/**
 * HandlerRequest1������ְ����ģʽ�е�һ���ӿ�ʵ�ֺ���
 */
void HandlerRequest1(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest1")) {
		printf("HandlerImpl1�ദ������������\n");
	}
	else {
		if (handler->handler) {
			handler->handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣\n");
		}
	}
}

/**
 * HandlerRequest2������ְ����ģʽ�е�һ���ӿ�ʵ�ֺ���
 */
void HandlerRequest2(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest2")) {
		printf("HandlerImpl2�ദ������������\n");
	}
	else {
		if (handler->handler) {
			handler->handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣\n");
		}
	}
}

/**
 * HandlerRequest3������ְ����ģʽ�е�һ���ӿ�ʵ�ֺ���
 */
void HandlerRequest3(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest3")) {
		printf("HandlerImpl3�ദ������������\n");
	}
	else {
		if (handler->handler) {
			handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣\n");
		}
	}
}

/**
 * HandlerBuilder�������ڹ�������ְ����
 */
Handler *HandlerBuilder() {
	Handler *handlerimpl3 = (Handler *)calloc(1, sizeof(Handler));
	handlerimpl3->handler = NULL;
	handlerimpl3->HandlerRequest = HandlerRequest3;

	Handler *handlerimpl2 = (Handler *)calloc(1, sizeof(Handler));
	handlerimpl2->handler = handlerimpl3;
	handlerimpl2->HandlerRequest = HandlerRequest2;

	Handler *handlerimpl1 = (Handler *)calloc(1, sizeof(Handler));
	handlerimpl1->handler = handlerimpl2;
	handlerimpl1->HandlerRequest = HandlerRequest1;

	return handlerimpl1;
}

/**
 * HandlerDestory����������������ְ����
 */
void HandlerDestory(Handler *handler) {
	Handler *next = NULL;
	while (handler) {
		next = handler->handler;
		free(handler);
		handler = next;
	}
}

/**
 * main������ְ�������ģʽ�Ĳ��Ժ���
 */
int main(int argc, char *argv[]) {
	Handler *handler = HandlerBuilder();
	Request request = { "HandlerRequest2" };
	handler->HandlerRequest(handler, &request);
	HandlerDestory(handler);
	return 0;
}
