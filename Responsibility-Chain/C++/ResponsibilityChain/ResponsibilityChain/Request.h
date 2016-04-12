#pragma once

#include <string>

/**
 * Request类包装了客户端的请求信息
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

