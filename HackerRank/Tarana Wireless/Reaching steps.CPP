A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: x2 = 1, y2 = 1, x1 = 2, y1 = 2
Output: False

Input: x2 = 1, y2 = 1, x1 = 1, y1 = 1
Output: True

string reachingPoints(int x2, int y2, int x1, int y1) {

    if (x1 == y1) 
    {if(x2 == y2 && x2 == x1) return "Yes";
    else return "No";}

    if (x1 < x2 || y1 < y2) {
        return "Yes";
    }
    if (x1 == x2 && y1 == y2) {
        return "Yes";
    }
    if (x1 == x2) {
        if((y1 - y2) % x1 == 0)
            return "Yes";
        else
            return "No";
    }
    if (y1 == y2) {
        if((x1 - x2) % y1 == 0)
            return "Yes";
        else
            return "No";
    }
    if (x1 > y1) {
        return canReach(x2, y2, x1 % x2, y1);
    }
    return canReach(x2, y2, x1, y1 % x1);
    /*while (x2 != x1 || y2 != y1) {
            
        if (x1 < x2 || y1 < y2) return "No";
            
        if (x1 > y1) x1 -= max((x1-x2)/y1, 1) * y1;
        else         y1 -= max((y1-y2)/x1, 1) * x1;
    }
        
    return "Yes";
    

    */
}
