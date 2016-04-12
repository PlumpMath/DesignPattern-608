#pragma once

#include "Handler.h"
#include <iostream>

/**
 * HandlerImpl1类是职责链模式中抽象类的一个实现类
 */
class HandlerImpl1 : public Handler {
public:

	HandlerImpl1(Handler *handler) : Handler(handler) { }

	virtual ~HandlerImpl1() { }

	virtual void HandlerRequest(Request request) {
		if (request.getMessage() == "HandlerImpl1") {
			std::cout << "HandlerImpl1类处理了您的请求" << std::endl;
		}
		else {
			if (this->handler) {
				this->handler->HandlerRequest(request);
			}
			else {
				std::cout << "非常抱歉，因能力有限，目前无法处理您的请求，请您谅解。" << std::endl;
			}
		}
	}
};

