import java.util.Scanner;

public class ecoo18r1p4 {

    public static void main(String[] args) {

        int[][] order = {{-1,-1},{-1,1},{1,1},{1,-1}};
        long[] len = {0,1,1,2,3,5,8,13,21,34,55,89,144,232,375,606,979,1582,2556,4130,6673,10782,17421,28148,45480,73484,118732,191841,309967,500829,809214,1307487,2112571,3413385,5515174,8911138,14398164,23263822,37588502,60733592,98130253,158553878,256183302,413927966,668803781,1080619176,1746009572,282111357L,4558212008L, 4840323365L, 9398535373L, 14238858738L, 23637394111L, 37876252849L, 61513646960L};
        long[][] bounds = new long[len.length][2];

        long startX = 1;
        long startY = 0;

        for (int i=0; i<len.length-1; i++) {

            bounds[i][0] = startX;
            bounds[i][1] = startY;
            int[] dir = order[i%4];
            startX += dir[0]*len[i+1];
            startY += dir[1]*len[i+1];

        }
        Scanner in = new Scanner(System.in);

        for (int i=0; i<10; i++) {
            String num[] = in.nextLine().trim().split(" ");
            long x = Long.parseLong(num[0]);
            long y = Long.parseLong(num[1]);
            for (int j=1; j<bounds.length; j++) {
                if (x <= Math.max(bounds[j][0], bounds[j-1][0])
                        && x >= Math.min(bounds[j][0], bounds[j-1][0])
                        && y <= Math.max(bounds[j][1], bounds[j-1][1])
                        && y >= Math.min(bounds[j][1], bounds[j-1][1])) {
                    System.out.println(j);
                    break;
                }
            }
        }
    }
}
