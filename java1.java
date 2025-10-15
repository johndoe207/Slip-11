package Ass;
interface Vol_cal{
	double PI=3.142;
	double vol();
}
class Cylinder implements Vol_cal {
	private double r;
	private double h;
	Cylinder(double r,double h)
	{
		this.r=r;
		this.h=h;
	}
	public double vol()
	{
		return PI*r*r*h;
	}
}
public class Main {
public static void main(String[] args)
{
	Cylinder cylinder=new Cylinder(5,10);
	double vol=cylinder.vol();
	System.out.println("The volume of the Cylinder is:"+vol);
}
}
