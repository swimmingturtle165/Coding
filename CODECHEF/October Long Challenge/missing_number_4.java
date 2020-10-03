/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.math.BigInteger;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static BigInteger evaluate(String nums,int base) 
    {
        
        BigInteger val=new BigInteger("0");
        BigInteger place_value=new BigInteger("1");
        for(int i = nums.length()-1;i>=0;i--)
        {
            int temp=0;
            if(nums.charAt(i) <='9')
            {
                temp=nums.charAt(i)-'0';
            }
            else
            {
                temp=nums.charAt(i)-'A'+10;
            }
             BigInteger temp_add=new BigInteger(BigInteger.valueOf(place_value))
             val.add(BigInte);
             place_value.multiply(BigInteger.valueOf(base));
             if(val.compareTo(new BigInteger("1000000000000"))==1)
             {
                 return val;
             }
        }
        return val;
    }
    String convert(BigInteger val,int base)
    {
        String ans=new String();
         place_value
        while(val.compareTo(new BigInteger("0"))==1)
        {

        }
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
	}
}
