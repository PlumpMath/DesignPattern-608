#pragma once

#include "Handler.h"
#include <iostream>

/**
 * HandlerImpl2类是职责链模式中抽象类的一个实现类
 */
class HandlerImpl2 : public Handler {
public:

	HandlerImpl2(Handler *handler) : Handler(handler) { }

	virtual ~HandlerImpl2() { }

	virtual void HandlerRequest(Request request) {
		if (request.getMessage() == "HandlerImpl2") {
			std::cout << "HandlerImpl2类处理了您的请求" << std::endl;
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

