#pragma once

#include "Request.h"
#include <iostream>

/**
 * Handler抽象类定义了职责链模式中的上层接口
 * 类中保存着下一个链节点的对象，以及定义了所有的链节点的公有接口
 */
class Handler {
public:

	Handler(Handler *handler) : handler(handler) { }

	virtual ~Handler() {
		if (handler) {
			delete handler;
			// std::cout << "delete handler" << std::endl;
		}
	}

	virtual void HandlerRequest(Request request) = 0;

protected:
	Handler *handler;
};

