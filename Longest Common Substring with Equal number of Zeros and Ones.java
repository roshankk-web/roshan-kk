import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0, maxL = 0;
        map.put(0, -1);
        for (int i = 0; i < s.length(); i++) {
            sum += (s.charAt(i) == '0') ? -1 : 1;
            if (map.containsKey(sum)) {
                maxL = Math.max(maxL, i - map.get(sum));
            } else {
                map.put(sum, i);
            }
        }
        System.out.println(maxL);
        sc.close();
    }
}
