#pragma once

#include "Handler.h"
#include <iostream>

/**
 * HandlerImpl1����ְ����ģʽ�г������һ��ʵ����
 */
class HandlerImpl1 : public Handler {
public:

	HandlerImpl1(Handler *handler) : Handler(handler) { }

	virtual ~HandlerImpl1() { }

	virtual void HandlerRequest(Request request) {
		if (request.getMessage() == "HandlerImpl1") {
			std::cout << "HandlerImpl1�ദ������������" << std::endl;
		}
		else {
			if (this->handler) {
				this->handler->HandlerRequest(request);
			}
			else {
				std::cout << "�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣" << std::endl;
			}
		}
	}
};

