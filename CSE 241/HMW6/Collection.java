public interface Collection<T> {





    void add(T e);
    Iterator iterator();
    void addAll(Collection<T> other);
    void clear();
    boolean contains(T e);
    boolean containsAll(Collection<T> other);
    boolean isEmpty();
    boolean remove(T e);
    void removeAll(Collection<T> other);
    void retainAll(Collection<T> other);
    Integer size();

    void setLimit(Integer index);
    Integer getLimit();





}
