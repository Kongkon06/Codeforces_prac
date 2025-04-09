import java.util.Scanner;
class New{
    public static void main(String[] args){
        Run obj= new Run();
        Run obj2= new Run();
        obj.Test(1);
        obj2.Test(2);
    }
}
class Run extends Thread{
   void Test(int a){
        for(int i=0;i<5;i++){
            System.out.println("thread "+a+" "+i);
            try{Thread.sleep(500);
            }catch(Exception e){
                System.out.println("error");
            }
        }
    }
};