package pattern.clazz;

/**
 * HandlerImpl3����ְ����ģʽ�г������һ��ʵ����
 */
public class HandlerImpl3 extends Handler {

	public HandlerImpl3(Handler handler) {
		super(handler);
	}

	@Override
	public void HandlerRequest(Request request) {
		if (request == null || request.getMessage() == null) {
			throw new NullPointerException();
		}
		if (request.getMessage().trim().equals("HandlerImpl3")) {
			System.out.println("HandlerImpl3�ദ������������");
		} else {
			if (this.handler == null) {
				System.out.println("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣");
			} else {
				this.handler.HandlerRequest(request);
			}
		}
	}

}
