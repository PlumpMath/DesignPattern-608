package pattern.clazz;

/**
 * HandlerImpl2����ְ����ģʽ�г������һ��ʵ����
 */
public class HandlerImpl2 extends Handler {

	public HandlerImpl2(Handler handler) {
		super(handler);
	}

	@Override
	public void HandlerRequest(Request request) {
		if (request == null || request.getMessage() == null) {
			throw new NullPointerException();
		}
		if (request.getMessage().trim().equals("HandlerImpl2")) {
			System.out.println("HandlerImpl2�ദ������������");
		} else {
			if (this.handler == null) {
				System.out.println("�ǳ���Ǹ�����������ޣ�Ŀǰ�޷������������������½⡣");
			} else {
				this.handler.HandlerRequest(request);
			}
		}
	}

}
