package pattern.clazz;

/**
 * Handler�����ඨ����ְ����ģʽ�е��ϲ�ӿ� <br>
 * ���б�������һ�����ڵ�Ķ����Լ����������е����ڵ�Ĺ��нӿ�
 */
public abstract class Handler {

	protected Handler handler;

	public Handler(Handler handler) {
		super();
		this.handler = handler;
	}

	public abstract void HandlerRequest(Request request);

}
