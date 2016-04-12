package pattern.clazz;

/**
 * Handler抽象类定义了职责链模式中的上层接口 <br>
 * 类中保存着下一个链节点的对象，以及定义了所有的链节点的公有接口
 */
public abstract class Handler {

	protected Handler handler;

	public Handler(Handler handler) {
		super();
		this.handler = handler;
	}

	public abstract void HandlerRequest(Request request);

}
