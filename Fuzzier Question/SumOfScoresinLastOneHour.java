
Given a stream of data coming from an online game portal, every entry looks like this
User_id, timestamp, score
U1, 12:00pm, 2
U2, 13:00pm, 3
U1, 13:02pm, 2
U3, 14:03pm, 4
Need to figure out the sum of scores in last one hour(Current - 1hr)



CODE - 

package com.test.app;

import java.util.ArrayList;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Application {

   static class Entry {
       public Entry(String userId, Integer timeStamp, Integer score) {
           this.userId = userId;
           this.timeStamp = timeStamp;
           this.score = score;
       }


       String userId;
       int timeStamp; //1230 1231 1259 1300
       int score;
   }

   public static ArrayList<Integer> sumOfScore(ArrayList<Entry> entries, List<Integer> timestamps) {
       Queue<Entry> q = new LinkedList<>();
       ArrayList<Integer> res = new ArrayList<>();
       int n = entries.size();

       int iter=0;
       int sum=0;
       for(int i=0;i<timestamps.size();i++) {
           int currTimestamp = timestamps.get(i);
           int minTimestamp = minus(59,currTimestamp);
           while(q.isEmpty()==false && q.peek().timeStamp<minTimestamp) {
               Entry remove = q.remove();
               sum-=remove.score;
           }
           while(iter<n&& entries.get(iter).timeStamp<=currTimestamp) {
               q.add(entries.get(iter));
               sum+=entries.get(iter).score;
               iter++;
           }
           res.add(sum);
       }
       return res;
   }

   //does t2-min
   private static int minus(int min, int t) {
       if(min==60)
           return (t-100);
       int tmin = t%100;
       if(tmin >= min)
           return t-min;
       else {
           int diff = min-tmin;
           t-=100;
           int mins = 60-diff;
           return t+mins;
       }
        }

   public static void main(String[] args) {
       ArrayList<Entry> arr = new ArrayList<>();
       arr.add(new Entry("",1200,2));
       arr.add(new Entry("",1300,3));
       arr.add(new Entry("",1302,2));
       arr.add(new Entry("",1355,4));

       ArrayList<Integer> timestamps = new ArrayList<>();
       timestamps.add(1200);
       timestamps.add(1300);
       timestamps.add(1330);
       timestamps.add(1400);

       ArrayList<Integer> res = sumOfScore(arr, timestamps);
       for(int i=0;i<timestamps.size();i++) {
           System.out.println("Time " + timestamps.get(i) + ":" + res.get(i));

       }
   }
}




