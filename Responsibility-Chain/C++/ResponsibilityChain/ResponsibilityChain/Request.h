#pragma once

#include <string>

/**
 * Request���װ�˿ͻ��˵�������Ϣ
 */
class Request {
public:

	Request(std::string message) : message(message) { }

	virtual ~Request() { }

	std::string getMessage() {
		return this->message;
	}

private:
	std::string message;
};

