package pattern.clazz;

/**
 * HandlerImpl1����ְ����ģʽ�г������һ��ʵ����
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
			System.out.println("HandlerImpl1�ദ������������");
		} else {
			if (this.handler == null) {
				System.out.println("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣");
			} else {
				this.handler.HandlerRequest(request);
			}
		}
	}

}
