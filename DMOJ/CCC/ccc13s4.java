import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

public class ccc13s4 {

    private static int N, M;
    private static ArrayList<Integer>[] graph;

    private static boolean bfs(int start, int end) {
        boolean visited[] = new boolean[1000001];
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        queue.addLast(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            int cur = queue.pollLast();
            for (int child : graph[cur]) {
                if (child == end) {
                    return true;
                }
                if (!visited[child]) {
                    queue.push(child);
                    visited[child] = true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {

        graph = new ArrayList[1000001];

        for (int i=0; i<1000001; i++) {
            graph[i] = new ArrayList<>();
        }
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        for (int i=0; i<M; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            graph[a].add(b);
        }
        int p = in.nextInt();
        int q = in.nextInt();

        if (bfs(p,q)) {
            System.out.print("yes");
        } else if (bfs(q,p)) {
            System.out.print("no");
        } else {
            System.out.println("unknown");
        }
    }
}
