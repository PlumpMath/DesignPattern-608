/**
 * 该文件是职责链模式的案例程序 [C语言版]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
;
/**
 * Request结构体包装了客户端的请求信息
 */
typedef struct Request {
	char message[4096];
} Request;

/**
 * Handler结构体定义了职责链模式中的上层接口
 * 结构体中保存着下一个链节点的结构体指针，以及定义了所有的链节点的公有函数接口
 */
typedef struct Handler {
	struct Handler *handler;
	void(*HandlerRequest)(const struct Handler *, const Request *);
} Handler;

/**
 * HandlerRequest1函数是职责链模式中的一个接口实现函数
 */
void HandlerRequest1(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest1")) {
		printf("HandlerImpl1类处理了您的请求\n");
	}
	else {
		if (handler->handler) {
			handler->handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("非常抱歉，因能力有限，目前无法处理您的请求，请您谅解。\n");
		}
	}
}

/**
 * HandlerRequest2函数是职责链模式中的一个接口实现函数
 */
void HandlerRequest2(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest2")) {
		printf("HandlerImpl2类处理了您的请求\n");
	}
	else {
		if (handler->handler) {
			handler->handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("非常抱歉，因能力有限，目前无法处理您的请求，请您谅解。\n");
		}
	}
}

/**
 * HandlerRequest3函数是职责链模式中的一个接口实现函数
 */
void HandlerRequest3(const struct Handler *handler, const Request *request) {
	if (!handler || !request || !request->message) {
		return;
	}
	if (!strcmp(request->message, "HandlerRequest3")) {
		printf("HandlerImpl3类处理了您的请求\n");
	}
	else {
		if (handler->handler) {
			handler->HandlerRequest(handler->handler, request);
		}
		else {
			printf("非常抱歉，因能力有限，目前无法处理您的请求，请您谅解。\n");
		}
	}
}

/**
 * HandlerBuilder函数用于构建整条职责链
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
 * HandlerDestory函数用于消除整条职责链
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
 * main函数是职责链设计模式的测试函数
 */
int main(int argc, char *argv[]) {
	Handler *handler = HandlerBuilder();
	Request request = { "HandlerRequest2" };
	handler->HandlerRequest(handler, &request);
	HandlerDestory(handler);
	return 0;
}
