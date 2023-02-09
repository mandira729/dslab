/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/



public class Main
{
    public static void setzero(int [][]arr)
    {
    int row=arr.length;
    int col=arr[0].length;
   
    
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(arr[i][j]==0)
                {
                    
                    int ind=i-1;
                    
                    while(ind>=0)
                    {
                        if(arr[ind][j]!=0)
                        {
                            arr[ind][j]=-1;
                        }
                        ind--;
                        
                    }
                    
                    ind=i+1;
                    while(ind<row)
                    {
                        if(arr[ind][j]!=0)
                        {
                        arr[ind][j]=-1;
                        }
                        ind++;
                        
                    }
                    ind=j-1;
                    while(ind>=0)
                    {
                        if(arr[i][ind]!=0)
                        {
                            arr[i][ind]=-1;
                        }
                        ind--;
                    }
                    
                    ind=j+1;
                    while(ind<col)
                    {
                        if(arr[i][ind]!=0)
                        {
                            arr[i][ind]=-1;
                            
                        }
                        ind++;
                    }
                }
                
                
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(arr[i][j]<=0)
                {
                    arr[i][j]=0;
                }  
            }
        }
    }    
   
	public static void main(String[] args) {
		int arr[][]={{1,1,1},{1,0,1},{1,1,1}};
		setzero(arr);
		System.out.println("the final matrix is");
		for(int i=0;i<arr.length;i++)
		{
		    for(int j=0;j<arr[0].length;j++)
		    {
		        System.out.print(arr[i][j] +" ");
		    }
		    System.out.println();
		}
	}
}
