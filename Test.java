import java.util.Scanner;
class Test{
  public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
    int []arr =new int[10];
    System.out.println("Enter the number of elements");
    int num=sc.nextInt();
    System.out.println("Enter the elements");
    for(int i=0;i<num;i++){
      arr[i]=sc.nextInt();
    }
    System.out.println("Enter the number to search");
    int value=sc.nextInt();
    Sort obj = new Sort(arr,num,value);
    obj.Search(num/2);  
}
}
class Sort{
  int value,size;
  int []arr=new int[size];
  Sort(int []arr,int size,int value){
    this.size=size;
    this.arr=arr;
    this.value=value;
  };
  void Search(int mid){
    if(arr[mid]==value){
      System.out.println("The value is present in "+(mid+1)+" position");
      return;
    }
    if(value<arr[mid]){
      mid=mid-1;
      if(value>arr[mid]){
        System.out.println("Element is not present");
        return;
       }
       Search(mid);
    }
    else if(value>arr[mid]){
      mid=mid+1;
      if(value<arr[mid]){
      System.out.println("Element is not present");
      return;}
      Search(mid);
    }
  }
}