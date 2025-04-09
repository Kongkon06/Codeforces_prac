import java.util.Scanner;
class Glass{
	public static void main(String[] args){
		String newarr= new String("Kongkon");
		StringBuilder arr=new StringBuilder();
	for(int i=0;i<newarr.length();i++){
          if(i!=2){
		arr.append(newarr.charAt(i));}
		else{
    		arr.append("l");}
	}
 	System.out.println(arr);
	System.out.println(arr.sort());
    }
}