import java.util.Scanner;

class Sample {
    public static void main(String[] args) {
        SharedObject obj = new SharedObject(5);
        Thread t1 = new Thread(new Test(obj), "Thread1");
        Thread t2 = new Thread(new Test(obj), "Thread2");
        t1.start();
        t2.start();
    }
}

class SharedObject {
    int num;

    SharedObject(int num) {
        this.num = num;
    }
}

class Test implements Runnable {
    SharedObject msg;

    Test(SharedObject msg) {
        this.msg = msg;
    }

    public void run() {
        try {
            synchronized (msg) { // Synchronize on the shared object
                for (int i = 0; i < msg.num; i++) {
                    System.out.println(Thread.currentThread().getName() + " " + i);
                    Thread.sleep(500);
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt(); // Properly handle the interruption
            System.out.println(Thread.currentThread().getName() + " was interrupted.");
        }
    }
}
