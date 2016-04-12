package pattern.clazz;

/**
 * Request类包装了客户端的请求信息 <br>
 */
public class Request {

	private String message;

	public Request(String message) {
		super();
		this.message = message;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	@Override
	public String toString() {
		return "Request [message=" + message + "]";
	}

}
