import java.util.Scanner;
class Sample2{
    public static void main(String[] args){
        Data student[] = new Data[10];
        String name;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of Students");
        int num=sc.nextInt();
        for(int i=0;i<num;i++){
            student[i]=new Data();
            System.out.println("Enter the name");
            name=sc.next();
            System.out.println("Enter the id");
            int id=sc.nextInt();
            student[i].Insert(name,id);
        }
    }
}
class Data{
    String name;
    int Id;
    void Insert(String name,int id){
        this.name=name;
        this.Id=id;
    }
}