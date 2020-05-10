class FooBar {
private:
    int n;
    sem_t first;
    sem_t second;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&first, 0, 1);
        sem_init(&second, 0, 0);
    }

    ~FooBar() {
        sem_destroy(&first);
        sem_destroy(&second);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&first);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&second);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&second);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&first);
        }
    }
};
