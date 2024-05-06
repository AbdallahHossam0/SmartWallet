template <typename T>
void MultiThreadQueue<T>::push(T item) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(item);
    m_cond.notify_one();
}

template <typename T>
T MultiThreadQueue<T>::pop() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cond.wait(lock, [this]() { return !m_queue.empty(); });
    T item = m_queue.front();
    m_queue.pop();
    return item;
}

template class MultiThreadQueue<int>;
