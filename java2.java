package Ass;
import java.util.Scanner;
class Invalid extends Exception
{
	public Invalid(String msg)
	{
		super(msg);
	}
}
public class User {
public static void main(String[] args)
{
	Scanner sc=new Scanner(System.in);
	try {
		System.out.print("Enter username:");
		String nm=sc.nextLine();
		System.out.print("\nEnter Password:");
		String pass=sc.nextLine();
		if(!nm.equals(pass))
		{
			throw new Invalid("Invalid password:username & password are not match.");
		}
		System.out.print("Login successfull.");
	}
	catch(Invalid e)
	{
		System.out.print(e.getMessage());
	}finally {
		sc.close();
	}
}
}
