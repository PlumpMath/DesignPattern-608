package pattern.main;

import pattern.clazz.Handler;
import pattern.clazz.HandlerImpl1;
import pattern.clazz.HandlerImpl2;
import pattern.clazz.HandlerImpl3;
import pattern.clazz.Request;

/**
 * MainClass类用于测试职责链模式
 */
public class MainClass {

	/**
	 * HandlerBuilder方法用于构建整条职责链
	 */
	public static Handler HandlerBuilder() {
		return new HandlerImpl1(new HandlerImpl2(new HandlerImpl3(null)));
	}

	public static void main(String[] args) {
		Request request = new Request("HandlerImpl3");
		Handler handler = HandlerBuilder();
		handler.HandlerRequest(request);
	}

}
