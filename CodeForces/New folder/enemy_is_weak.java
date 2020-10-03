import java.util.*;

public class enemy_is_weak{

    public static int soln(int[] arr, int low, int high){

        int invCount = 0;
        // System.out.println(low);
        // System.out.println(high);
        
        if(low<high){
            int reg=(high-low+1)%3;
            int part_size=(high-low+1)/3;
            int start1=low;
            int end1=start1+part_size-1;
            if(reg>0)
            {
                end1++;
                reg--;
            }
            int start2=end1+1;
            int end2=start2+part_size-1;
            if(reg>0)
            {
                end2++;
                reg--;
            }
            // int start3=end2+1;
            // int end3=high;
            
            int mid1 = low + end1;
            int mid2 = low + end2;

            invCount += soln(arr, low, mid1);
            invCount += soln(arr, mid1 + 1, mid2);
            invCount += soln(arr, mid2 + 1, high);

            invCount += merge(arr, low, mid1, mid2, high);

        }
        return invCount;
    }

    public static int merge(int[] arr, int low, int m1, int m2, int high)
    {
        int swaps = 0;

        int[] a1 = Arrays.copyOfRange(arr, low, m1+1);
        int[] a2 = Arrays.copyOfRange(arr, m1 , m2+1);
        int[] a3 = Arrays.copyOfRange(arr, m2, high+1);

        int i = low, j = m1, k = m2, l = low;

        while(i<m1 && j<m2 && k<high){
            if(a1[i]<a2[j]){
                if(a1[i]<a3[k]){
                    arr[l++] = a1[i++];
                }else{
                    arr[l++] = a3[k++];
                }
            }else{
                if(a2[j]<a3[k]){
                    arr[l++] = a2[j++];
                }else{
                    arr[l++] = a3[k++];
                    swaps += (m1 + 1) - (low + i);
                }
            }
        }

        while(i<m1 && j<m2){
            if(a1[i]<a2[j]){
                arr[l++] = a1[i++];
            }else{
                arr[l++] = a2[j++];
            }
        }

        while(j<m2 && k<high){
            if(a2[j]<a3[k]){
                arr[l++] = a2[j++];
            }else{
                arr[l++] = a3[k++];
            }
        }

        while(i<m1 && k<high){
            if(a1[i]<a3[k]){
                arr[l++] = a1[i++];
            }else{
                arr[l++] = a3[k++];
            }
        }

        while(i<m1){
            arr[l++] = a1[i++];
        }

        while(j<m2){
            arr[l++] = a2[j++];
        }
    
        while(k<high){
            arr[l++] = a3[k++];
        }

        for(int x = 0;x<arr.length;x++){
            arr[x] = arr[x];
        }

        return swaps;
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = s.nextInt();
        }

        int ans = soln(arr, 0, arr.length-1);
        System.out.println(ans);
    }
}