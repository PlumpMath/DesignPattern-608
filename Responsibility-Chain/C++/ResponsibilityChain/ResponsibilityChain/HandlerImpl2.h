#pragma once

#include "Handler.h"
#include <iostream>

/**
 * HandlerImpl2����ְ����ģʽ�г������һ��ʵ����
 */
class HandlerImpl2 : public Handler {
public:

	HandlerImpl2(Handler *handler) : Handler(handler) { }

	virtual ~HandlerImpl2() { }

	virtual void HandlerRequest(Request request) {
		if (request.getMessage() == "HandlerImpl2") {
			std::cout << "HandlerImpl2�ദ������������" << std::endl;
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

