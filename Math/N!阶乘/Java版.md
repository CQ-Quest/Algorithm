# Java版

	import java.util.*; 
	import java.math.*; 
	public class Main {   
	public static void main(String[] args) { 
	Scanner s=new Scanner (System.in); 
	int n; 
	BigInteger m;   
	while(s.hasNext()) { 
	n=s.nextInt(); 
	m=BigInteger.ONE; 
	for(int i=1;i<=n;i++) 
	  m=m.multiply(BigInteger.valueOf(i)); 
	System.out.println(m); 
	} 
	} 
	} 
