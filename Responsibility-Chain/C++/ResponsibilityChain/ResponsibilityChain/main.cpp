#include "Handler.h"
#include "HandlerImpl1.h"
#include "HandlerImpl2.h"
#include "HandlerImpl3.h"

/**
 * main函数用于测试职责链模式
 */
int main(int argc, char *argv[]) {
	Request request("HandlerImpl3");
	Handler *handler = new HandlerImpl1(new HandlerImpl2(new HandlerImpl3(nullptr)));
	handler->HandlerRequest(request);
	delete handler;
	return 0;
}