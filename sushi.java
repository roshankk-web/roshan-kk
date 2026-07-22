import java.util.*;

class Sushi_Matching {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of Shari: ");
        int n = sc.nextInt();

        System.out.print("Enter number of Neta: ");
        int m = sc.nextInt();
        int[] shari = new int[n];
        int[] neta = new int[m];

        System.out.println("Enter weights of Shari:");
        for (int i = 0; i < n; i++) {
            shari[i] = sc.nextInt();
        }

        System.out.println("Enter weights of Neta:");
        for (int i = 0; i < m; i++) {
            neta[i] = sc.nextInt();
        }
        Arrays.sort(shari);
        Arrays.sort(neta);

        int count = 0;

        int i = m - 1; 
        int j = n - 1; 
        while (i >= 0 && j >= 0) {

            if (neta[i] <= (2 * shari[j])) {
                count++;
                i--;
                j--;
            } else {
                i--;
            }
        }
        System.out.println("Total number of sushi pairs is: " + count);
        sc.close();
    }
}
