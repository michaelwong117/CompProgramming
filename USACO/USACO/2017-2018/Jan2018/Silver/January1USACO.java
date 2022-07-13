//package january1usaco;
import java.util.*;
import java.io.*;
public class January1USACO {
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("C:\\USACO\\1_input.txt"));
        BufferedReader br = new BufferedReader(new FileReader("lifeguards.in"));
        //PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C:\\USACO\\1_out.txt")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); 
        int array[]=new int [100000000];
        int timestart[]=new int [n];
        int timeend[]=new int[n];
        for (int i=0; i<n; i++){
             st = new StringTokenizer(br.readLine());
             timestart[i] = Integer.parseInt(st.nextToken()); 
             timeend[i] = Integer.parseInt(st.nextToken());
             for (int j=timestart[i]; j<timeend[i]; j++){
                 array[j]++;
             }
        }
        int sum=0;
        for (int i=0; i<100000000; i++){
            if (array[i]==0){
                sum++;
            }
        }
        int lowest=10000; 
        for (int i=0; i<n; i++){
            int kay=0;
            for (int j=timestart[i]; j<timeend[i]; j++){
                if (array[j]==1){
                   kay++; 
                }
            }
            if (kay<lowest){
                lowest=kay;
            }
        }
        pw.println(100000000-lowest-sum);
        pw.close();
    }
    
}
