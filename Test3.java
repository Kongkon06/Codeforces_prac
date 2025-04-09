class HelloWorld {
    public static void main(String[] args) {
        int a = 5;
        Thread obj1 = new Thread(new Road(a), "Thread1");
        Thread obj2 = new Thread(new Road(a), "Thread2");
        obj1.start(); // Start the first thread
        obj2.start(); // Start the second thread
    }
}

class Road implements Runnable {
    int num;

    Road(int num) {
        this.num = num;
    }

    public void run() {
        for (int i = 0; i < num; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
            try{
                Thread.sleep(500);
            }catch(InterruptedException e){}
        }
    }
}
