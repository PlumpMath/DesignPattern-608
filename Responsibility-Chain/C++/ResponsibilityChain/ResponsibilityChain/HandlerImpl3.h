#pragma once

#include "Handler.h"
#include <iostream>

/**
 * HandlerImpl3����ְ����ģʽ�г������һ��ʵ����
 */
class HandlerImpl3 : public Handler {
public:

	HandlerImpl3(Handler *handler) : Handler(handler) { }

	virtual ~HandlerImpl3() { }

	virtual void HandlerRequest(Request request) {
		if (request.getMessage() == "HandlerImpl3") {
			std::cout << "HandlerImpl3�ദ������������" << std::endl;
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

