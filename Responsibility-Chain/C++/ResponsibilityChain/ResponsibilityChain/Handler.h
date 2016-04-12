#pragma once

#include "Request.h"
#include <iostream>

/**
 * Handler�����ඨ����ְ����ģʽ�е��ϲ�ӿ�
 * ���б�������һ�����ڵ�Ķ����Լ����������е����ڵ�Ĺ��нӿ�
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

