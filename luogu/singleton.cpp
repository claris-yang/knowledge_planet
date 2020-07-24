//
// Created by yangtao on 19-6-12.
//

class Singleton {
private:
    Singleton() {};
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

// 线程安全,但锁的代价过高
Singleton* Singleton::getInstance() {
    Lock lock;
    if(m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

// 双检查锁, 但由于内存读写reorder不安全
// double check lock
// 什么叫做reorder
// 指令执行的和我们想想的不一样
// 1 内存 , 构造器 给m_instance
// 2 分配内存, 给m_instance 调用构造器
// reorder 没有调用构造器
Singleton* Singleton::getInstance() {
    if(m_instance == nullptr) {
        Lock lock;
        if(m_instance == nullptr) {  //  不加判断不正确
            m_instance = new Singleton();
        }
    }
    return m_instance;

}

// c++ 11 volatile
std::atomic<Singleton *> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton * Singleton::getInstance() {
    Singleton * t = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if(t == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        t = m_instance.load(std::memory_order_relaxed);
        if(t == nullptr) {
            t = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(t, std::memory_order_relaxed);
        }
    }

    return t;
}