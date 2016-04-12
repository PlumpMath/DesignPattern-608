package pattern.main;

import pattern.clazz.Handler;
import pattern.clazz.HandlerImpl1;
import pattern.clazz.HandlerImpl2;
import pattern.clazz.HandlerImpl3;
import pattern.clazz.Request;

/**
 * MainClass�����ڲ���ְ����ģʽ
 */
public class MainClass {

	/**
	 * HandlerBuilder�������ڹ�������ְ����
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
