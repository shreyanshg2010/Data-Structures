There are N Mice and N holes are placed in a straight line. Each hole can accommodate only 1 mouse. A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x -1. Any of these moves consumes 1 minute. Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.

Examples:

Input : positions of mice are:
          4 -4 2
        positions of holes are:
          4 0 5
                    
                    
Output :  4
Assign mouse at position x = 4 to hole at 
position x = 4 : Time taken is 0 minutes 
Assign mouse at position x=-4 to hole at 
position x = 0 : Time taken is 4 minutes 
Assign mouse at position x=2 to hole at 
position x = 5 : Time taken is 3 minutes 
After 4 minutes all of the mice are in the holes.
Since, there is no combination possible where
the last mouse's time is less than 4, 
answer = 4.

import java.util.* ; 
  
public class GFG 
{ 
    // Returns minimum time required to place mice 
    // in holes. 
    public int assignHole(ArrayList<Integer> mice, 
                         ArrayList<Integer> holes) 
    { 
        if (mice.size() != holes.size()) 
           return -1; 
  
        /* Sort the lists */
        Collections.sort(mice); 
        Collections.sort(holes); 
  
        int size = mice.size(); 
  
        /* finding max difference between ith mice and hole */
        int max = 0; 
        for (int i=0; i<size; i++) 
            if (max < Math.abs(mice.get(i)-holes.get(i))) 
                max = Math.abs(mice.get(i)-holes.get(i)); 
  
        return Math.abs(max); 
    } 
  
    /* Driver Function to test other functions */
    public static void main(String[] args) 
    { 
        GFG gfg = new GFG(); 
        Scanner sc = new Scanner(System.in); 
        
        int k = sc.nextInt(); 
        ArrayList<Integer> mice = new ArrayList<Integer>(); 
        for(int i = 0; i < k; i++){
            int a = sc.nextInt(); 
            mice.add(a);
        }
         
    
        ArrayList<Integer> holes= new ArrayList<Integer>(); 
        
        for(int i = 0; i < k; i++){
            int b = sc.nextInt(); 
            holes.add(b); 
        }
        
       
        System.out.println(gfg.assignHole(mice, holes)); 
    } 
} 
