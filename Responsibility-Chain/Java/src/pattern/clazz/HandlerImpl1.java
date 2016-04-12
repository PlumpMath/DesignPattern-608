package pattern.clazz;

/**
 * HandlerImpl1类是职责链模式中抽象类的一个实现类
 */
public class HandlerImpl1 extends Handler {

	public HandlerImpl1(Handler handler) {
		super(handler);
	}

	@Override
	public void HandlerRequest(Request request) {
		if (request == null || request.getMessage() == null) {
			throw new NullPointerException();
		}
		if (request.getMessage().trim().equals("HandlerImpl1")) {
			System.out.println("HandlerImpl1类处理了您的请求");
		} else {
			if (this.handler == null) {
				System.out.println("非常抱歉，因能力有限，目前无法处理您的请求，请您谅解。");
			} else {
				this.handler.HandlerRequest(request);
			}
		}
	}

}
