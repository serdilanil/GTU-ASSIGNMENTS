
public interface Queue<T> extends Collection<T> {


    T element();
    boolean offer(T e);
    T poll();
}
